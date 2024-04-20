# CubeMX project

This project shows the usage of CubeMX. Refer to the documentation chapter [
[**CMSIS-Toolbox > Work with CubeMX**](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/tree/main/docs/CubeMX.md) for details.

## Prerequisites

### Tools

- [CMSIS-Toolbox 2.3.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or higher
- [Keil MDK 5.37](https://www2.keil.com/mdk5/) or higher
- [STM32CubeMX 6.11](https://www.st.com/en/development-tools/stm32cubemx.html) or higher

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

You may use the debugger of choice for executing this program.
