# Dual Core project

This example generates **HelloWorld** executables for the **FRDM-K32L3A6** evaluation board. The **K32L3** microcontroller is a dual-core MCU with a [**Cortex-M0+**](https://developer.arm.com/Processors/Cortex-M0-Plus) and a [**Cortex-M4**](https://developer.arm.com/Processors/Cortex-M4).

## Prerequisites

### Tools

- [CMSIS-Toolbox 2.14.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or higher
- Arm Compiler 6.22 or higher

### Packs

- Required packs are listed in the file [`HelloWorld.csolution.yml`](./HelloWorld.csolution.yml)

## Project Structure

The project is generated using the [CMSIS-Toolbox](https://open-cmsis-pack.github.io/cmsis-toolbox/build-overview) and is defined in [`csolution`](https://open-cmsis-pack.github.io/cmsis-toolbox/YML-Input-Format) format:

- [`HelloWorld.csolution.yml`](./HelloWorld.csolution.yml) lists the required packs and defines the hardware target, build types, compiler, and target set that groups both core images and configures the debugger.
- [`./cm0plus/HelloWorld_cm0plus.cproject.yml`](./cm0plus/HelloWorld_cm0plus.cproject.yml) defines the source files and the software components for the **Cortex-M0+** core.
- [`./cm4/HelloWorld_cm4.cproject.yml`](./cm4/HelloWorld_cm4.cproject.yml) defines the source files and the software components for the **Cortex-M4** core.

## Generate the project binaries

```txt
> cbuild HelloWorld.csolution.yml --packs --toolchain AC6
```

## Execute Project

Select the `FRDM-K32L3A6` target with `--active FRDM-K32L3A6` to build the Debug application containing both core images. The target set configures MCU-Link with pyOCD for downloading and debugging the application.
