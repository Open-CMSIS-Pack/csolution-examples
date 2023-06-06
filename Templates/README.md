# CMSIS-Toolbox Templates

The following `csolution.yml` templates may be used to create own embedded applications.

Folder                               | Description
:------------------------------------|:----------------------------------
[Simple](./Simple)                   | A `csolution.yml` template with a single `cproject.yml`.
[Multicore](./Multicore)             | A `csolution.yml` template with multiuple `cproject.yml` each targeting one processor of a multicore device.
[TrustZone](./TrustZone)             | A `csolution.yml` template with a non-secure `cproject.yml` and an optional secure `cproject.yml`.
[UnitTest](./UnitTest)               | A `csolution.yml` template that shares one HAL `clayer.yml` with multiple `cproject.yml` files for unit testing.

To use these templates **copy the content of the folder to your own application folder**. Then adapt the names accordingly and add missing information.

## Overall Workflow

1. **Device and/or board software packs**
   - Visit **[www.keil.arm.com](https://www.keil.arm.com) - Hardware - Boards or Devices** to identify software packs for your hardware.
   - Use `cpackget add` to install these software packs.

2. **Adapt the `csolution.yml` and `cproject.yml` files to your application**
   - Enter the device and/or board information along with software packs in `csolution.yml`.
   - Add source files, software components, and potentially software layers to `cproject.yml`.

During the process the following CMSIS-Toolbox commands are useful:

