[![License](https://img.shields.io/github/license/Open-CMSIS-Pack/csolution-examples?label)](https://github.com/Open-CMSIS-Pack/csolution-examples/blob/main/LICENSE)
[![Hello: Test Build and Execution test](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/csolution-examples/Hello-CI.yml?logo=arm&logoColor=0091bd&label=Hello:%20Test%20Build%20and%20Execution)](/.github/workflows/Hello-CI.yml)
[![DualCore: Test Build](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/csolution-examples/DualCore-CI.yml?logo=arm&logoColor=0091bd&label=DualCore:%20Test%20Build)](/.github/workflows/DualCore-CI.yml)
[![CubeMX: Test Build](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/csolution-examples/CubeMX-CI.yml?logo=arm&logoColor=0091bd&label=CubeMX:%20Test%20and%20Build)](/.github/workflows/CubeMX-CI.yml)
[![SimpleTZ: Test Build and Execution](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/csolution-examples/SimpleTZ-CI.yml?logo=arm&logoColor=0091bd&label=SimpleTZ:%20Test%20Build%20and%20Execution)](/.github/workflows/SimpleTZ-CI.yml)

# CMSIS-Toolbox Examples in `csolution` project format

This is a collection of [CMSIS-Toolbox](https://github.com/Open-CMSIS-Pack/cmsis-toolbox) project examples using the [`csolution` project format](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/YML-Input-Format.md) utility.  The project files are provided for experimentation, exploration and education purposes.

> **Note:** These examples use **CMSIS-Toolbox 2.6.0** or higher.
>
> Refer to [**Installation of the CMSIS-Toolbox**](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/installation.md) for information how to setup an environment.

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
> cbuild Hello.csolution.yml --packs --context-set --toolchain AC6 --rebuild 
```

## Examples in other repositories

Source            | Description
:-----------------|:----------------------------------
[Hello](./Hello)  | A simple project to get started
[AWS_MQTT_MutualAuth_Demo](https://github.com/Open-CMSIS-Pack/AWS_MQTT_MutualAuth_SW_Framework)                    | MQTT demo that uses layers for re-targeting to different physical boards
[Arm TrustZone Demo](https://github.com/MDK-Packs/TrustZone)                                                       | Example that uses TF-M and Bootloader for firmware update.  Runs on [STM32U5 board](https://www.st.com/en/evaluation-tools/b-u585i-iot02a.html) or [AVH](https://avh.arm.com/)

>**Note:** The examples may require additional tools. Refer to the instructions for each example to install the required toolchain.
