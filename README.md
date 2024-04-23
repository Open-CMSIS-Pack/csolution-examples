# CMSIS-Toolbox Examples in `csolution` project format

This is a collection of [CMSIS-Toolbox](https://github.com/Open-CMSIS-Pack/cmsis-toolbox) project examples using the [`csolution` project format](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/YML-Input-Format.md) utility.  The project files are provided for experimentation, exploration and education purposes.

> **Note:** These examples use **CMSIS-Toolbox 2.0.0** or higher.
> 
> Refer to [**Installation of the CMSIS-Toolbox**](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/installation.md) for information how to setup an enviornment.

## Project Examples

Examples in this repository:

Source                               | Description
:------------------------------------|:----------------------------------
[Hello](./Hello)                     | A simple project to get started.
[DualCore](./DualCore)               | Application with multiple processors.
[SimpleTrustZone](./SimpleTrustZone) | Simple TrustZone example.
[CubeMX](./CubeMX)                   | Project that uses [STM32Cube](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/tree/main/docs/CubeMX.md) as generator for device configuration.

## Build Projects

Before you build projects, ensure that the pack index on your local computer is up-to-date with the command.

```txt
> cpackget update-index        
```

The project files  contain a list of software packs that are used. When using the `cbuild` tool option `--packs` these packs are downloaded during the build process as shown in the following example command line:

```txt
> cbuild Hello.csolution.yml --packs --rebuild
```

## Examples in other repositories:

Source            | Description
:-----------------|:----------------------------------
[Hello](./Hello)  | A simple project to get started
[AWS Workshop](https://catalog.us-east-1.prod.workshops.aws/workshops/30043722-0362-4859-bc6f-c28836a2d7ac/en-US)  | Getting Started With Arm Virtual Hardware (AVH) in Keil Studio Cloud (KSC) - All examples use `csolution` format
[AWS_MQTT_MutualAuth_Demo](https://github.com/Open-CMSIS-Pack/AWS_MQTT_MutualAuth_SW_Framework)                    | MQTT demo that uses layers for re-targeting to different physical boards
[Arm TrustZone Demo](https://github.com/MDK-Packs/TrustZone)                                                       | Example that uses TF-M and Bootloader for firmware update.  Runs on [STM32U5 board](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) or [AVH](https://avh.arm.com/)

>**Note:** The examples may require additional tools. Refer to the instructions for each example to install the required toolchain.
