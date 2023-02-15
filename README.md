# Hello project

This project prints "Hello World" and a counter value via semihosting output. It is configured for Arm Virtual Hardware (Cortex-M55).

## Prerequisites

### Tools

- [CMSIS-Toolbox 1.4.0](https://github.com/Open-CMSIS-Pack/devtools/releases) or later
- [Keil MDK 5.38a](https://www2.keil.com/mdk5/) or later
  - Arm Compiler 6.18 (part of MDK, Eval Version sufficient for compilation)
  - Arm Virtual Hardware for Cortex-M55 v11.18.1 (requires MDK - Professional)
- [GNU Arm Embedded Toolchain 12.2.rel1](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads) or later

### Packs

Required packs are listed in the file [`Hello.csolution.yml`](./Hello.csolution.yml)

## Project Structure

The project is generated using the [CMSIS-Toolbox](https://github.com/Open-CMSIS-Pack/devtools/blob/main/tools/projmgr/docs/Manual/Overview.md) and is defined in [`csolution`](https://github.com/Open-CMSIS-Pack/devtools/blob/main/tools/projmgr/docs/Manual/YML-Format.md) format:

- [`Hello.csolution.yml`](./Hello.csolution.yml) lists the required packs and defines the hardware target and build-types (along with the compiler).
- [`Hello.cproject.yml`](./Hello.cproject.yml) defines the source files and the software components.

## Generated Project

1. Use the `csolution` command to create `.cprj` project file.

   ```bash
   $ csolution convert -s Hello.csolution.yml
   ./build/Hello/GCC/Debug+AVH/Hello.Debug+AVH.cprj - info csolution: file generated successfully
   ./build/Hello/GCC/Release+AVH/Hello.Release+AVH.cprj - info csolution: file generated successfully
   ./Hello.cbuild-idx.yml - info csolution: file generated successfully
   ./build/Hello/GCC/Debug+AVH/Hello.Debug+AVH.cbuild.yml - info csolution: file generated successfully
   ./build/Hello/GCC/Release+AVH/Hello.Release+AVH.cbuild.yml - info csolution: file generated successfully
   ```

2. Use the `cbuild` command to an executable file, here fore the `Debug` build.

   ```bash
   ./ $ cbuild build/Hello/GCC/Debug+AVH/Hello.Debug+AVH.cprj
   info cbuild: Build Invocation 1.0.0 (C) 2022 ARM
      :    // output of the build steps
   info cbuild: build finished successfully!
   ```

> **Note:** During the build process required packs may be downloaded.

## Execute Project

The project is configured for execution on Arm Virtual Hardware which removes the requirement for a physical hardware board.

- When using MDK-Professional, you may execute it with the command:

  ```bash
  ./ $ VHT_MPS2_Cortex-M55 -f vht-config.txt -a build/Hello/GCC/Debug+AVH/outdir/Hello.Debug+AVH.elf
  ```
