# Zephyr West Integration Template

This template shows the minimum structure for integrating an existing Zephyr application into a *csolution project* using the West build system.

Before using the template:

- Install Zephyr and initialize a West workspace as described in the [Zephyr Getting Started Guide](https://docs.zephyrproject.org/latest/develop/getting_started/index.html).
- Replace the pack, board, device, and `west-board` placeholders in `MyName.csolution.yml`.
- Replace `./MyZephyrApp` with the path to an application in the West workspace.

Build the Debug target with:

```bash
cbuild MyName.csolution.yml --active MyTargetName@Debug --packs
```

For a complete multi-board example with debugging and CI workflows, refer to [Arm-Examples/CMSIS-Zephyr](https://github.com/Arm-Examples/CMSIS-Zephyr).
