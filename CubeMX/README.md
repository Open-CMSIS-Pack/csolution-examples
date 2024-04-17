# CubeMX project

This project shows the usage of CubeMX

## Prerequisites

### Tools

- [CMSIS-Toolbox 2.3.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or higher
- [Keil MDK 5.37](https://www2.keil.com/mdk5/)
  - Arm Compiler 6.18 (part of MDK, Eval Version sufficient for compilation)
  - Arm Virtual Hardware for Corstone-300 v11.18.1 (requires MDK - Professional)

>**Note:** later versions will also compiler with GCC.

### Packs

- Required packs are listed in the file [`CubeMX.csolution.yml`](./CubeMX.csolution.yml) and [`CubeMX.cproject.yml`](./CubeMX.cproject.yml)

## Run CubeMX

This command starts STM32CubeMX using the previous configuration with the current selected context set.

```txt
> csolution CubeMX.csolution.yml run --generator CubeMX --context-set
```

## Generated Project

```txt
> cbuild Hello.csolution.yml --packs
```

>**Note:** During the build process required packs may be downloaded.

## Execute Project

ToDo
