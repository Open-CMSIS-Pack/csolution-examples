# Simple TrustZone Application

- This [**Arm Cortex-M33**](https://developer.arm.com/Processors/Cortex-M33) secure/non-secure example project shows how to set up [**TrustZone**](https://www.arm.com/technologies/trustzone-for-cortex-m) on the [**Armv8-M**](https://www.arm.com/architecture/cpu/m-profile) profile.
- The application uses [**CMSIS**](https://www.arm.com/technologies/cmsis) and can be executed on an [**Arm Virtual Hardware (AVH)**](https://developer.arm.com/Tools%20and%20Software/Arm%20Virtual%20Hardware).
- The application demonstrates function calls between the [**secure and non-secure**](https://developer.arm.com/documentation/100235/0004/the-cortex-m33-processor/security-state-switches) states.

## Prerequisites

### Tools

- [CMSIS-Toolbox 2.14.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or higher
- Arm Compiler 6.22 or higher
- GCC Compiler 13.2.1 or higher
- Arm Virtual Hardware for FVP_MPS2_Cortex-M33 v11.26.11

### Packs

- Required packs are listed in the file [`SimpleTZ.csolution.yml`](./SimpleTZ.csolution.yml)

## Project Structure

The project is generated using the [CMSIS-Toolbox](https://open-cmsis-pack.github.io/cmsis-toolbox/build-overview) and is defined in [`csolution`](https://open-cmsis-pack.github.io/cmsis-toolbox/YML-Input-Format) format:

- [`SimpleTZ.csolution.yml`](./SimpleTZ.csolution.yml) lists the required packs and defines the hardware target, build types, supported compilers, and target sets.
- [`CM33_s.cproject.yml`](./CM33_s/CM33_s.cproject.yml) defines the source files and the software components used for the secure part.
- [`CM33_ns.cproject.yml`](./CM33_ns/CM33_ns.cproject.yml) defines the source files and the software components used for the non-secure part.

## Theory of operation

### Secure application

- Sets up and starts the non-secure application.

### Non-secure application

- Calls a secure function from the non-secure state.
- Calls a secure function that calls back to a non-secure function.

### Output

The output shows the transition from secure to non-secure execution followed by the function calls and their results in the non-secure application.

## Generate the project binaries

The solution provides `Debug` and `Release` target sets. Select the required set with the `--active` option:

```txt
> cbuild SimpleTZ.csolution.yml --packs --active AVH@Debug --toolchain AC6
> cbuild SimpleTZ.csolution.yml --packs --active AVH@Release --toolchain AC6
```

Replace `AC6` with `GCC` to build a target set with the GCC compiler.

## Execute the project on Arm Virtual Hardware

```txt
> FVP_MPS2_Cortex-M33 -a ./out/CM33_ns/AVH/Debug/CM33_ns.axf -a ./out/CM33_s/AVH/Debug/CM33_s.axf -f ./../FVP/FVP_MPS2_Cortex-M33/fvp_config.txt --stat

telnetterminal0: Listening for serial connection on port 5000
telnetterminal1: Listening for serial connection on port 5001
telnetterminal2: Listening for serial connection on port 5002

Jump to non-secure application at 0x00201565
Non-secure application...
func1(1) = 4
func2(func3, 2) = 9

Info: /OSCI/SystemC: Simulation stopped by user.

--- FVP_MPS2_Cortex_M33 statistics: -------------------------------------------
Simulated time                          : 0.000400s
User time                               : 0.004335s
System time                             : 0.004148s
Wall time                               : 0.008444s
Performance index                       : 0.05
cpu0                                    :   1.37 MIPS (       11610 Inst)
cpu1                                    :   0.00 MIPS (           0 Inst)
Total                                   :   1.37 MIPS (       11610 Inst)
Memory highwater mark                   : 0x11278000 bytes ( 0.268 GB )
-------------------------------------------------------------------------------
```
