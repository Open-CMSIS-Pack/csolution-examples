[![License: Apache-2.0](https://img.shields.io/badge/License-Apache--2.0-green?label=License)](https://github.com/Open-CMSIS-Pack/csolution-examples/blob/main/LICENSE-Apache-2.0)
[![License: BSD-3-Clause](https://img.shields.io/badge/License-BSD--3--Clause-green?label=License)](https://github.com/Open-CMSIS-Pack/csolution-examples/blob/main/LICENSE-BSD-3-Clause)
[![Hello: Test Build and Execution](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/csolution-examples/Hello-CI.yml?logo=arm&logoColor=0091bd&label=Hello:%20Test%20Build%20and%20Execution)](/.github/workflows/Hello-CI.yml)
[![DualCore: Test Build](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/csolution-examples/DualCore-CI.yml?logo=arm&logoColor=0091bd&label=DualCore:%20Test%20Build)](/.github/workflows/DualCore-CI.yml)
[![CubeMX: Test Build](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/csolution-examples/CubeMX-CI.yml?logo=arm&logoColor=0091bd&label=CubeMX:%20Test%20and%20Build)](/.github/workflows/CubeMX-CI.yml)
[![SimpleTZ: Test Build and Execution](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/csolution-examples/SimpleTZ-CI.yml?logo=arm&logoColor=0091bd&label=SimpleTZ:%20Test%20Build%20and%20Execution)](/.github/workflows/SimpleTZ-CI.yml)

# CMSIS-Toolbox Examples in *csolution project format*

This is a collection of [CMSIS-Toolbox](https://open-cmsis-pack.github.io/cmsis-toolbox) project examples in [*csolution project format*](https://open-cmsis-pack.github.io/cmsis-toolbox/YML-Input-Format).  The project examples are provided for experimentation, exploration and education purposes.

## Tool Requirements

The examples use **CMSIS-Toolbox 2.14.0** or higher; the Native CMake integration template requires version 2.15.0 or higher. Depending on the example, additional tools include CMake, Ninja, Arm Compiler 6, GCC, CLANG, Arm Virtual Hardware Fixed Virtual Platforms (AVH FVP), STM32CubeMX, and West with a Zephyr workspace. Refer to the README of each example or template for its specific requirements.

Refer to [**Installation of the CMSIS-Toolbox**](https://open-cmsis-pack.github.io/cmsis-toolbox/installation) for information on the setup of a development environment with these tools.

When using VS Code with the [Arm Environment Manager](https://marketplace.visualstudio.com/items?itemName=Arm.environment-manager) the required tools are installed based on the settings in the file [`vcpkg-configuration.json`](./vcpkg-configuration.json) using the [Arm Tools Artifactory](https://artifacts.tools.arm.com/).

!!! Note
    The Debug build type includes workarounds for known debugger issues. Refer to [CMSIS-Toolbox Troubleshooting](https://open-cmsis-pack.github.io/cmsis-toolbox/Troubleshooting/#stack-unwinding-fails-or-hangs) for details.

## Project Examples

Examples in this repository:

*csolution project*                  | Description
:------------------------------------|:----------------------------------
[Hello](./Hello)                     | A simple project to get started. Requires no hardware as it runs on [AVH-FVP](https://github.com/ARM-software/AVH) simulation models.
[DualCore](./DualCore)               | Application with multiple processors that runs on the [NXP FRDM-K32L3A6](https://www.keil.arm.com/boards/nxp-frdm-k32l3a6-989d2e5/projects/) board.
[SimpleTrustZone](./SimpleTrustZone) | Simple TrustZone example that shows secure and non-secure projects, including how to use a prebuilt secure image. Runs on [AVH-FVP](https://github.com/ARM-software/AVH) simulation models.
[CubeMX](./CubeMX)                   | Project that uses [STM32CubeMX](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/tree/main/docs/CubeMX.md) for device configuration and contains a RAM and ROM target.

Each *csolution project* example shows different aspects of the CMSIS-Toolbox. For example, the [CubeMX](./CubeMX) *csolution project* contains two targets that show RAM and ROM execution.

## Build Projects

The project files contain a list of software packs that are used. When using the `cbuild` tool option `--packs` these packs are downloaded during the build process as shown in the following example command line:

```txt
> cbuild Hello/Hello.csolution.yml --packs --toolchain AC6 --rebuild
```

## Template Projects

The directory [Templates](./Templates) contains structural templates for simple single-core, multi-core, TrustZone, and unit-test projects. It also contains integration templates for existing [Zephyr applications built with West](./Templates/ZephyrWest) and [native CMake projects](./Templates/NativeCMake). They are not ready-to-build examples, but may be used as a starting point for an application.

## GitHub Action Workflows

The directory [.ci](./.ci) contains the required setup for testing these examples with [GitHub Actions](./.github) workflows. The tools are downloaded from the [Arm Tools Artifactory](https://artifacts.tools.arm.com/). The test results are available in the [*Actions*](/../../actions) view.

## Examples in Other Repositories

See [github.com/Arm-Examples](https://github.com/Arm-Examples) for a collection of embedded software example projects.
