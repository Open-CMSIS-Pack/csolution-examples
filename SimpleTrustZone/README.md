# Simple TrustZone Application

- This [**ARM Cortex-M33**](https://developer.arm.com/Processors/Cortex-M33) secure/non-secure example project shows how to setup the [**TrustZone**](https://www.arm.com/technologies/trustzone-for-cortex-m) for running on [**ARMv8-M**](https://www.arm.com/architecture/cpu/m-profile) profile.
- The application uses [**CMSIS**](https://www.arm.com/technologies/cmsis) and can be executed on an [**Arm Virtual Hardware (AVH)**](https://developer.arm.com/Tools%20and%20Software/Arm%20Virtual%20Hardware).
- The application demonstrates function calls between [**secure and non-secure**](https://developer.arm.com/documentation/100235/0004/the-cortex-m33-processor/security-state-switches) state.

## Prerequisites

### Tools

- [CMSIS-Toolbox 2.6.0](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/releases) or higher
- Arm Compiler 6.22 or higher
- Arm Virtual Hardware for FVP_MPS2_Cortex-M33 v11.26.11

### Packs

- Required packs are listed in the file [`SimpleTZ.csolution.yml`](./SimpleTZ.csolution.yml)

## Project Structure

The project is generated using the [CMSIS-Toolbox](https://open-cmsis-pack.github.io/cmsis-toolbox/build-overview) and is defined in [`csolution`](https://open-cmsis-pack.github.io/cmsis-toolbox/YML-Input-Format) format:


- [`SimpleTZ.csolution.yml`](./SimpleTZ.csolution.yml) lists the required packs, defines, hardware targets, and the build-types (along with the compiler).
- [`CM33_s.cproject.yml`](./CM33_s/CM33_s.cproject.yml) defines the source files and the software components used for the secure part.
- [`CM33_ns.cproject.yml`](./CM33_ns/CM33_ns.cproject.yml) defines the source files and the software components used for the non-secure part.

## Theory of operation

### Secure application:
- Setup code and start for the non-secure application.

### Non-secure application:
- Calls a secure function from non-secure state.
- Calls a secure function that call back to a non-secure function.

### Output:
- Message  : 
   - Switch from the secure execution to the non-secure execution.
- Messages :
   - Start program execution in the non-secure state
   - Show function calls and results of the program execution in the non-secure state

## Generate the project binaries

Note that the file [SimpleTZ.cbuild-set.yml](./SimpleTZ.cbuild-set.yml) contains the selected [context set](https://open-cmsis-pack.github.io/cmsis-toolbox/build-overview#working-with-context-set) for the application.


```txt
> cbuild SimpleTZ.csolution.yml --packs .Debug+AVH --toolchain AC6 --context-set
```

## Execute the project on ARM Virtual Hardware

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
