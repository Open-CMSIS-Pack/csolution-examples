# CMSIS-Toolbox Examples in `csolution.yml` format

This is a collection of [CMSIS-Toolbox](https://github.com/Open-CMSIS-Pack/devtools/blob/main/tools/README.md) project examples using the [`csolution` Project Manager](https://github.com/Open-CMSIS-Pack/devtools/blob/main/tools/projmgr/docs/Manual/Overview.md) utility.  The project files are provided in [`csolution.yml`](https://github.com/Open-CMSIS-Pack/devtools/blob/main/tools/projmgr/docs/Manual/Overview.md#yml-input-format) format for experimentation, exploration and education purposes.

> **Note:** These examples use **CMSIS-Toolbox 2.0.0-dev0** or higher.
> 
- [**Installation of the CMSIS-Toolbox**](https://github.com/Open-CMSIS-Pack/devtools/tree/main/tools#download-and-install)

## Use vcpkg

This example uses also [vcpkg](https://vcpkg.io/en/) for installation of a consistent tool environment.

**Install vcpgk:**

- Windows cmd: `curl -LO https://aka.ms/vcpkg-init.cmd && .\vcpkg-init.cmd`
- PowerShell: `iex (iwr -useb https://aka.ms/vcpkg-init.ps1)`
- Linux / macOS: `. <(curl https://aka.ms/vcpkg-init.sh -L)`

**Activating vcpkg in a new shell:**

- Windows cmd: `%USERPROFILE%\.vcpkg\vcpkg-init.cmd`
- PowerShell:  `. ~/.vcpkg/vcpkg-init.ps1`
- Linux / macOS: `. ~/.vcpkg/vcpkg-init.sh`

**Configuration file:**

The default file name is: `vcpkg-configuration.json` (part of this repository)
This file stores the required registries and the artifact versions to be installed and added to the path in your current shell.

**Update “arm” registry:**

This command is required when a new CMSIS-Toolbox update is released to pickup the new version:

```txt
vcpkg z-ce update arm
```

## Project Examples

Examples in this repository:

Source                               | Description
:------------------------------------|:----------------------------------
[Hello](./Hello)                     | A simple project to get started
[DualCore](./DualCore)               | Application with multiple processors
[SimpleTrustZone](./SimpleTrustZone) | Simple TrustZone example

Examples in other repositories:

Source            | Description
:-----------------|:----------------------------------
[Hello](./Hello)  | A simple project to get started
[AWS Workshop](https://catalog.us-east-1.prod.workshops.aws/workshops/30043722-0362-4859-bc6f-c28836a2d7ac/en-US)  | Getting Started With Arm Virtual Hardware (AVH) in Keil Studio Cloud (KSC) - All examples use `csolution` format
[AWS_MQTT_MutualAuth_Demo](https://github.com/Open-CMSIS-Pack/AWS_MQTT_MutualAuth_SW_Framework)                    | MQTT demo that uses layers for re-targeting to different physical boards
[Arm TrustZone Demo](https://github.com/MDK-Packs/TrustZone)                                                       | Example that uses TF-M and Bootloader for firmware update.  Runs on [STM32U5 board](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) or [AVH](https://avh.arm.com/)

>**Note:** The examples may require additional tools. Refer to the instructions for each example to install the required toolchain.

## Download Software Packs

Before you start downloading new software packs, ensure that the pack index on your local computer is up-to-date with the command.

```txt
> cpackget update-index        
```

Most examples list in the `csolution.yml` file the software packs that are used. You may download these packs with the following commands:

```txt
> csolution list packs -s Demo.csolution.yml -m > packlist.txt
> cpackget add -f packlist.txt
```
