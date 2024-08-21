# Continuous Integration (CI) test for csolution-examples

  
Content of `.ci` Directory   | Description
:----------------------------|:-----------------
`vcpkg-configuration.json`   | Tool setup for the CI test.


## GitHub Action Workflows

The [**`GitHub Actions`**](https://docs.github.com/en/actions) in the directory `.github/workflows` are the scripts for the CI tests. These scripts contain detailed comments about each step that is executed.
Projects in the Arm csolution-examples uses the **`ARM compiler (AC6)`** as well as the **`GCC`** toolchains. Not all workflows are using both compilers.

- **`Hello-CI.yml`** implements a build and execution test. The build steps are using **`AC6`** and **`GCC`** toolchains. The execution tests runs on [**`Arm Virtual Hardware - Fixed Virtual Platforms (AVH FVP)`**](https://arm-software.github.io/AVH/main/simulation/html/index.html) simulation models. The directory **`FVP`** contains configuration files for the **`FVP simulation models`**.

- **`DualCore-CI.yml`** implements a build test for a DualCore  (**`cm0plus, cm4`**) project by using the **`AC6`** toolchain. The output of this build test is stored as artifact and can be downloaded.

- **`SimpleTrustZone-CI.yml`** implements build tests for a **`TrustZone`** based project by using the **`AC6`** and **`GCC`** toolchains. The execution tests runs on [**`Arm Virtual Hardware - Fixed Virtual Platforms (AVH FVP)`**](https://arm-software.github.io/AVH/main/simulation/html/index.html) simulation models. The directory **`FVP`** contains configuration files for the **`FVP simulation models`**.

- **`CubeMX-CI.yml`**  implements a build test for a **`CubeMX`** generated project by using only the **`AC6`** toolchain. The output of this build test is stored as artifact and can be downloaded.
