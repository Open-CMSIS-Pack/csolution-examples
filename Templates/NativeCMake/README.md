# Native CMake Integration Template

This template shows the minimum structure for integrating an existing native CMake project into a *csolution project*. It does not describe the CMake files generated internally for `*.cproject.yml` builds.

Before using the template:

- Replace the pack, board, and device placeholders in `MyName.csolution.yml`.
- Replace `./MyNativeProject` with the directory containing the native project's `CMakeLists.txt`.
- Adapt the configure options, build target, and output image paths to the native project.
- Ensure the native project configures its compiler and linker for the selected target.

Build the Debug target with:

```bash
cbuild MyName.csolution.yml --active MyTargetName@Debug --packs
```

For a complete application, refer to [Arm-Examples/CMSIS-CMake](https://github.com/Arm-Examples/CMSIS-CMake).
