# Simple TrustZone Application

This ARM Cortex-M33 secure/non-secure example project that shows the setup for TrustZone for ARMv8-M applications.

The application uses CMSIS and can be executed on an Arm Virtual Hardware (AVH).

The application demonstrates function calls between secure and non-secure state.

Secure application:

- Setup code and start non-secure application.

Non-secure application:

- Calls a secure function from non-secure state.
- Calls a secure function that call back to a non-secure function.

Output:
Variables used in this application can be viewed in the uVision Debugger Watch window.

## Generated Project

```txt
> cbuild SimpleTZ.csolution.yml --packs .Debug+AVH --toolchain AC6
```

## Run in Fast Models

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
