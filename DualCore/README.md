# Dual Core project

This example generates **HelloWorld** executables for the **FRDM-K32L3A6** evaluation board. The used **K32L3** microcontroller is a dual-core MCU ([**Cortex-M0plus**](https://developer.arm.com/Processors/Cortex-M0-Plus) and [**Cortex-M4**](https://developer.arm.com/Processors/Cortex-M4))

## Prerequisites

### Tools

- [CMSIS-Toolbox 2.6.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or higher
- Arm Compiler 6.22 or higher
- GCC Compiler 13.2.1 or higher

### Packs

- Required packs are listed in the file [`HelloWorld.csolution.yml`](./HelloWorld.csolution.yml)

## Project Structure

The project is generated using the [CMSIS-Toolbox](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/build-overview.md) and is defined in [`csolution`](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/YML-Input-Format.md) format:

- [`HelloWorld.csolution.yml`](./HelloWorld.csolution.yml) lists the required packs, defines, hardware targets, and the build-types (along with the compiler).
- [`./cm0plus/HelloWorld_cm0plus.cproject.yml`](./cm0plus/HelloWorld_cm0plus.cproject.yml) defines the source files and the software components for the **Cortex-M0plus** core.
- [`./cm4/HelloWorld_cm4.cproject.yml`](./cm4/HelloWorld_cm4.cproject.yml) defines the source files and the software components for the **Cortex-M4** core.


## Generate the project binaries

```txt
> cbuild HelloWorld.csolution.yml --packs --toolchain AC6
```

## Execute Project

You may use the debugger of choice for executing this program.
