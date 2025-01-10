# Hello project

This project prints "Hello World" and a counter value via the UART output. It is configured for [**Arm Virtual Hardware (AVH)**](https://developer.arm.com/Tools%20and%20Software/Arm%20Virtual%20Hardware), but other target hardware that provides a CMSIS Driver:USART can be easily added.

## Prerequisites

### Tools

- [CMSIS-Toolbox 2.6.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or higher
- Arm Compiler 6.22 or higher
- GCC Compiler 13.2.1 or higher
- Arm Virtual Hardware for Corstone-300 v11.26.11 or higher

### Packs

- Required packs are listed in the file [`Hello.csolution.yml`](./Hello.csolution.yml). The file [`Hello.cbuild-pack.yml`](./Hello.cbuild-pack.yml) records the versions that have been used to generate the application.

## Project Structure

The project is generated using the [CMSIS-Toolbox](https://open-cmsis-pack.github.io/cmsis-toolbox/build-overview) and is defined in [`csolution`](https://open-cmsis-pack.github.io/cmsis-toolbox/YML-Input-Format) format:

- [`Hello.csolution.yml`](./Hello.csolution.yml) lists the required packs, defines,hardware targets, and thebuild-types (along with the compiler).
- [`Hello.cproject.yml`](./Hello.cproject.yml) defines the source files and the software components.

> **Note:**
>
> The project also builds with the GCC compiler.

## Generate project binaries

```bash
> cbuild Hello.csolution.yml --packs --toolchain AC6
```

>**Note:** During the build process required packs may be downloaded.

## Execute the project on ARM Virtual Hardware

The project is configured for execution on [**Arm Virtual Hardware**](https://developer.arm.com/Tools%20and%20Software/Arm%20Virtual%20Hardware) which removes the requirement for a physical hardware board.  

### Execute this project via command line

#### For debug type

```bash
> FVP_Corstone_SSE-300 -f FVP/FVP_Corstone_SSE-300/fvp-config.txt -a ./out/Debug/Hello.axf
```

#### For release type

```bash
> FVP_Corstone_SSE-300 -f FVP/FVP_Corstone_SSE-300/fvp-config.txt -a ./out/Release/Hello.axf
```

### Execute this project in [**Keil Studio Cloud**](https://studio.keil.arm.com/)

- Keil Studio Cloud integrates also the Arm Virtual Hardware for FVP_Corstone_SSE-300/_Ethos-U55/_Ethos-U65 models. The steps to use the example are:
    - Start [Keil Studio Cloud](https://studio.keil.arm.com/) and login to the system using your account.
    - Use **File - Clone** and enter the URL: (https://github.com/Open-CMSIS-Pack/csolution-examples).
    - Select from the drop-down *Target hardware*: **Corstone SSE-300 (Cortex-M55, Ethos-U55, Ethos-U65)**
    - Click **Run project** which executes the project build step and then starts running on Arm Virtual Hardware.
