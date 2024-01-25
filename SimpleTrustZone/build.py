#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import logging

from enum import Enum
from matrix_runner import main, matrix_axis, matrix_action, matrix_command, matrix_filter
from matrix_runner.command import CommandResult
from typing import List

@matrix_axis("compiler", "c", "Compiler(s) to be considered.")
class CompilerAxis(Enum):
    AC6 = ('AC6')
    GCC = ('GCC')
    IAR = ('IAR')
    CLANG = ('Clang')

    @property
    def image_ext(self):
        ext = {
            CompilerAxis.AC6: 'axf',
            CompilerAxis.GCC: 'elf',
            CompilerAxis.IAR: 'elf',
            CompilerAxis.CLANG: 'elf',
        }
        return ext[self]

    @property
    def toolchain(self):
        ext = {
            CompilerAxis.AC6: 'AC6',
            CompilerAxis.GCC: 'GCC',
            CompilerAxis.IAR: 'IAR',
            CompilerAxis.CLANG: 'CLANG'
        }
        return ext[self]


@matrix_action
def build(config, results: List[CommandResult]):
    """Build the selected configurations using CMSIS-Build."""
    logging.info("Compiling SimpleTrustZone example...")
    yield cbuild(config)


def expect(result: CommandResult, output: str):
    if not output in result.output.getvalue():
        logging.warning(f"Expected output '{output}' no captured.")
        result.success = False


@matrix_action
def run(config, results: List[CommandResult]):
    """Run the selected configurations."""
    logging.info("Running SimpleTrustZone example on Arm model ...")
    yield model_exec(config)

    expect(results[-1], "func1(1) = 4")
    expect(results[-1], "func2(func3, 2) = 9")


@matrix_command()
def cbuild(config):
    return ["cbuild", "-r", "--toolchain", config.compiler.toolchain, "--update-rte", "--packs", \
             "--context", f".Debug", "SimpleTZ.csolution.yml" ]


@matrix_command()
def model_exec(config):
    return ["FVP_MPS2_Cortex-M33", "-q", "--simlimit", 100, "-f", "model_config.txt",
            "-a", f"out/AVH/CM33_ns.{config.compiler.image_ext}",
            "-a", f"out/AVH/CM33_s.{config.compiler.image_ext}"]


@matrix_filter
def filter_iar(config):
    return config.compiler == CompilerAxis.IAR


if __name__ == "__main__":
    main()
