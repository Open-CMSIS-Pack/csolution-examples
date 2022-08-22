# Hello project

This project prints "Hello World" and a counter value via the UART output. It is configured for Arm Virtual Hardware, but other target hardware that provides a CMSIS Driver:USART can be easily added.

## Prerequisites
### Tools:
 - [CMSIS-Toolbox 1.0.0](https://github.com/Open-CMSIS-Pack/devtools/releases) or higher
 - [Keil MDK 5.37](https://www2.keil.com/mdk5/)
   - Arm Compiler 6.18 (part of MDK, Eval Version sufficient for compilation)
   - Arm Virtual Hardware for Corstone-300 v11.18.1 (requires MDK - Professional)

>**Note:** later versions will also compiler with GCC

### Packs
 - Required paks are listed in the file [`Hello.csolution.yml`](./Hello.csolution.yml)

###
## Project Structure

The project is generated using the [CMSIS-Toolbox](https://github.com/Open-CMSIS-Pack/devtools/blob/main/tools/projmgr/docs/Manual/Overview.md) and is defined in [`csolution`](https://github.com/Open-CMSIS-Pack/devtools/blob/main/tools/projmgr/docs/Manual/YML-Format.md) format:

 - [`Hello.csolution.yml`](./Hello.csolution.yml) lists the requried packs and defines the hardware target and build-types (along with the compiler).
 - [`Hello.cproject.yml`](./Hello.cproject.yml) defines the source files and the software components.

## Generated Project

1. Use the `csolution` command to create `.cprj` project file.
   ```
   > csolution convert -s Hello.csolution.yml
   ./Hello.Debug+AVH.cprj - info csolution: file generated successfully
   ./Hello.Release+AVH.cprj - info csolution: file generated successfully
   ```

2. Use the `cbuild` command to an executable file, here fore the `Debug` build.
   ```
   > cbuild Hello.Debug+AVH.cprj       
   info cbuild: Build Invocation 1.0.0 (C) 2022 ARM
   :
   info cbuild: build finished successfully!
   ```
   
>**Note:** During the build process required packs may be downloaded

## Execute Project

The project is configured for execution on Arm Virtual Hardware which removes the requirement for a physical hardware board.  You may execute it with the command:

    ```
    > VHT_Corstone_SSE-300_Ethos-U55 -f vht-config.txt -a ./out/Hello/AVH/Debug/Hello.Debug+AVH.axf
    ```






