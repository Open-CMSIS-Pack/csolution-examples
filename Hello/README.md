# Hello project

This project prints "Hello World" and a counter value via the UART output. It is configured for Arm Virtual Hardware, but other target hardware that provides a CMSIS Driver:USART can be easily added.

## Prerequisites

### Tools

- [CMSIS-Toolbox 2.0.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or higher
- [Keil MDK 5.37](https://www2.keil.com/mdk5/)
  - Arm Compiler 6.18 (part of MDK, Eval Version sufficient for compilation)
  - Arm Virtual Hardware for Corstone-300 v11.18.1 (requires MDK - Professional)

>**Note:** later versions will also compiler with GCC.

### Packs

- Required packs are listed in the file [`Hello.csolution.yml`](./Hello.csolution.yml) and [`Hello.cproject.yml`](./Hello.cproject.yml)

## Project Structure

The project is generated using the [CMSIS-Toolbox](https://github.com/Open-CMSIS-Pack/devtools/blob/main/tools/projmgr/docs/Manual/Overview.md) and is defined in [`csolution`](https://github.com/Open-CMSIS-Pack/devtools/blob/main/tools/projmgr/docs/Manual/YML-Format.md) format:

- [`Hello.csolution.yml`](./Hello.csolution.yml) lists the required packs and defines the hardware target and build-types (along with the compiler).
- [`Hello.cproject.yml`](./Hello.cproject.yml) defines the source files and the software components.

## Generated Project

```txt
> cbuild Hello.csolution.yml --packs
```

>**Note:** During the build process required packs may be downloaded.

## Execute Project

The project is configured for execution on Arm Virtual Hardware which removes the requirement for a physical hardware board.  

- When using MDK-Professional, you may execute it with the command:
### For debug type
  ```txt
  > C:/Keil_v5/ARM/VHT/VHT_Corstone_SSE-300_Ethos-U55 -f vht-config.txt -a ./out/Debug/Hello.axf
  ```
### For release type
  ```txt
  > C:/Keil_v5/ARM/VHT/VHT_Corstone_SSE-300_Ethos-U55 -f vht-config.txt -a ./out/Release/Hello.axf
  ```

- [Keil Studio Cloud](https://studio.keil.arm.com/) integrates also the Arm Virtual Hardware VHT_Corstone_SSE-300_Ethos-U55 model. The steps to use the example are:
  - Start [Keil Studio Cloud](https://studio.keil.arm.com/) and login to the system using your account.
  - Use **File - Clone** and enter the URL: (https://github.com/Open-CMSIS-Pack/csolution-examples).  Add
  - Select from the drop-down *Target hardware*: **Corstone SSE-300 (Cortex-M55, Ethos-U55)**
  - Click **Run project** which executes the project build step and then starts running on Arm Virtual Hardware.
