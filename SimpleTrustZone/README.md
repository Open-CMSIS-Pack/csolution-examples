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
> cbuild SimpleTZ.csolution.yml --packs --context .Debug --update-rte
```

## Run in Fast Models

```txt
> FVP_MPS2_Cortex-M33 -f model_config.txt -a cpu0=out/CM33_ns/AVH/Debug/CM33_ns.axf -a cpu0=out/CM33_s/AVH/Debug/CM33_s.axf 
telnetterminal0: Listening for serial connection on port 5000
telnetterminal1: Listening for serial connection on port 5001
telnetterminal2: Listening for serial connection on port 5002
Jump to non-secure application at 0x0020242D
Non-secure application...
func1(1) = 4
func2(func3, 2) = 9

Info: /OSCI/SystemC: Simulation stopped by user.
```
