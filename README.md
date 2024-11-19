[![License](https://img.shields.io/github/license/Open-CMSIS-Pack/csolution-examples)](https://github.com/Open-CMSIS-Pack/csolution-examples/blob/main/LICENSE)
[![Hello: Test Build and Execution test](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/csolution-examples/Hello-CI.yml?logo=arm&logoColor=0091bd&label=Hello:%20Test%20Build%20and%20Execution)](/.github/workflows/Hello-CI.yml)
[![DualCore: Test Build](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/csolution-examples/DualCore-CI.yml?logo=arm&logoColor=0091bd&label=DualCore:%20Test%20Build)](/.github/workflows/DualCore-CI.yml)
[![CubeMX: Test Build](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/csolution-examples/CubeMX-CI.yml?logo=arm&logoColor=0091bd&label=CubeMX:%20Test%20and%20Build)](/.github/workflows/CubeMX-CI.yml)
[![SimpleTZ: Test Build and Execution](https://img.shields.io/github/actions/workflow/status/Open-CMSIS-Pack/csolution-examples/SimpleTZ-CI.yml?logo=arm&logoColor=0091bd&label=SimpleTZ:%20Test%20Build%20and%20Execution)](/.github/workflows/SimpleTZ-CI.yml)

# CMSIS-Toolbox Examples in *csolution project format*

This is a collection of [CMSIS-Toolbox](https://github.com/Open-CMSIS-Pack/cmsis-toolbox) project examples in [*csolution project format*](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/YML-Input-Format.md).  The project examples are provided for experimentation, exploration and education purposes.

## Tool Requirements

The examples use **CMSIS-Toolbox 2.6.0** or higher and require additional tools such as CMake, Ninja, Arm Compiler 6, GCC Compiler, and Arm Fixed Virtual Platforms (AVH-FVP).

Refer to [**Installation of the CMSIS-Toolbox**](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/blob/main/docs/installation.md) for information on the setup of a development environment with these tools.

When using VS Code with the [Arm Environment Manager](https://marketplace.visualstudio.com/items?itemName=Arm.environment-manager) the required tools are installed based on the settings in the file [`vcpkg-configuration.json`](./vcpkg-configuration.json) using the [Arm Tools Artifactory](https://artifacts.tools.arm.com/).

## Project Examples

Examples in this repository:

*csolution project*                  | Description
:------------------------------------|:----------------------------------
[Hello](./Hello)                     | A simple project to get started. Requires no hardware as it runs on [AVH-FVP](https://github.com/ARM-software/AVH) simulation models.
[DualCore](./DualCore)               | Application with multiple processors that runs on the [NXP FRDM-K32L3A6](https://www.keil.arm.com/boards/nxp-frdm-k32l3a6-989d2e5/projects/) board.
[SimpleTrustZone](./SimpleTrustZone) | Simple TrustZone example that shows the concept of secure and non-secure projects. Runs on [AVH-FVP](https://github.com/ARM-software/AVH) simulation models.
[CubeMX](./CubeMX)                   | Project that uses [STM32Cube](https://github.com/Open-CMSIS-Pack/cmsis-toolbox/tree/main/docs/CubeMX.md) for device configuration and contains a RAM and ROM target.

Each *csolution project* example shows different aspects of the CMSIS-Toolbox. For example, the [CubeMX](./CubeMX) *csolution project* contains two targets that show RAM and ROM execution.

## Build Projects

Before you build projects, ensure that the pack index on your local computer is up-to-date with the command.

```txt
> cpackget update-index
```

The project files  contain a list of software packs that are used. When using the `cbuild` tool option `--packs` these packs are downloaded during the build process as shown in the following example command line:

```txt
> cbuild Hello.csolution.yml --packs --context-set --toolchain AC6 --rebuild 
```

## Template Projects

The directory [Templates](./Templates) may be used as starting point for different types of embedded applications: simple single core, multi-core, TrustZone, and unit test.

## GitHub Action Workflows

The directory [.ci](./.ci) contains the required setup for the Continuous Integration (CI) test of these examples with [GitHub action](./.github) workflows. The tools are downloaded from the [Arm Tools Artifactory](https://artifacts.tools.arm.com/). The test results are available in the [*Actions*](/../../actions) view.

## Examples in Other Repositories

Source            | Description
:-----------------|:----------------------------------
[github.com/Arm-Examples](https://github.com/Arm-Examples)  | A collection of several example projects
[AWS_MQTT_MutualAuth_Demo](https://github.com/Open-CMSIS-Pack/AWS_MQTT_MutualAuth_SW_Framework)  | MQTT demo that uses layers for re-targeting to different physical boards
[AVH_CI_Template](https://github.com/Arm-Examples/AVH_CI_Template) |  CI Template for unit test automation that uses [GitHub Actions](https://github.com/features/actions)