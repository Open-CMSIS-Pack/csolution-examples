# CubeMX project

This project shows the usage of CubeMX. Refer to the documentation chapter
[**CMSIS-Toolbox > Work with CubeMX**](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/tree/main/docs/CubeMX.md) for details.

## Prerequisites

### Tools

- [CMSIS-Toolbox 2.3.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or higher
- [Keil MDK 5.37](https://www2.keil.com/mdk5/) or higher
- [STM32CubeMX 6.11](https://www.st.com/en/development-tools/stm32cubemx.html) or higher

>**Note:** later versions will also compile with GCC.

### Packs

- Required packs are listed in the file [`CubeMX.csolution.yml`](./CubeMX.csolution.yml) and [`CubeMX.cproject.yml`](./CubeMX.cproject.yml)

DFP and BSP development packs are available here https://github.com/Open-CMSIS-Pack/pack-examples. Clone the repo and install the packs by executing:
```txt
> cpackget add <path to Keil.STM32U5xx_DFP.pdsc>
> cpackget add <path to Keil.B-U585I-IOT02A_BSP.pdsc>
```

## Run CubeMX

This command starts STM32CubeMX using the previous configuration with the current selected context set.

```txt
> csolution CubeMX.csolution.yml run --generator CubeMX --context-set
```

This command starts STM32CubeMX using the previous configuration with the specified context.

```txt
> csolution CubeMX.csolution.yml run --generator CubeMX --context CubeMX.Debug+MyBoard
```

## Generated Project

```txt
> cbuild CubeMX.csolution.yml --packs --update-rte
```

>**Note:** During the build process required packs may be downloaded.

## Execute Project

You may use the debugger of choice for executing this program.
