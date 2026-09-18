# Hello project

This project prints "Hello World" and a counter value via the UART output. It is configured for [**Arm Virtual Hardware (AVH)**](https://developer.arm.com/Tools%20and%20Software/Arm%20Virtual%20Hardware), but other target hardware that provides a CMSIS Driver:USART can be easily added.

## Prerequisites

### Tools

- [CMSIS-Toolbox 2.14.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or higher
- Arm Compiler 6.22 or higher
- GCC Compiler 13.2.1 or higher
- CLANG 22.1 or higher
- Arm Virtual Hardware for Corstone-300 v11.26.11 or higher

### Packs

- Required packs are listed in the file [`Hello.csolution.yml`](./Hello.csolution.yml). The file [`Hello.cbuild-pack.yml`](./Hello.cbuild-pack.yml) records the versions that have been used to generate the application.

## Project Structure

The project is generated using the [CMSIS-Toolbox](https://open-cmsis-pack.github.io/cmsis-toolbox/build-overview) and is defined in [`csolution`](https://open-cmsis-pack.github.io/cmsis-toolbox/YML-Input-Format) format:

- [`Hello.csolution.yml`](./Hello.csolution.yml) lists the required packs and defines the hardware targets, build types, and supported compilers.
- [`Hello.cproject.yml`](./Hello.cproject.yml) defines the source files and the software components.

> [!NOTE]
> The project supports the AC6, GCC, and CLANG compilers.

## Generate project binaries

```bash
> cbuild Hello.csolution.yml --packs --toolchain AC6
```

> [!NOTE]
> During the build process, required packs may be downloaded.

## Execute the project on Arm Virtual Hardware

The project is configured for execution on [**Arm Virtual Hardware**](https://developer.arm.com/Tools%20and%20Software/Arm%20Virtual%20Hardware) which removes the requirement for a physical hardware board.  

### Execute this project via command line

#### For debug type

```bash
> FVP_Corstone_SSE-300 -f ../FVP/FVP_Corstone_SSE-300/fvp_config.txt -a ./out/Hello/CS300/Debug/Hello.axf
```

#### For release type

```bash
> FVP_Corstone_SSE-300 -f ../FVP/FVP_Corstone_SSE-300/fvp_config.txt -a ./out/Hello/CS300/Release/Hello.axf
```

### Use this project with Keil Studio

Install [Keil Studio](https://marketplace.visualstudio.com/items?itemName=Arm.keil-studio-pack) from the Visual Studio Marketplace, clone this repository, and open `Hello.csolution.yml` in VS Code. Keil Studio provides the CMSIS solution, build, and debug tooling required to work with the project.
