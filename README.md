# SDL2 Example using my [C Makefile Template](https://github.com/Phillezi/C_Makefile_Template)

## Prerequisites

To compile and run this program you will need:
- C compiler, GCC
- SDL2
- SDL2_ttf

## Instructions
### Windows

*This assumes you are using mingw32.*
To build the project, simply run the following command. Since `all` is the first target in the Makefile, it will be executed by default. This command compiles all the `.c` files in the `src` directory into `.o` files and then links them to an executable specified in the Makefile (Target).

```ps
mingw32-make.exe
```

To build the project with debug flags, use the `debug` target. By default, it includes the `-g` flag for debugging information, this lets you debug the executable with programs like GDB.

```ps
mingw32-make.exe debug
```

For a list of available Makefile targets and their descriptions, you can use the `help` target.

```ps
mingw32-make.exe help
```

### Unix-based (OS X / Linux)

To build the project, simply run the following command. Since `all` is the first target in the Makefile, it will be executed by default. This command compiles all the `.c` files in the `src` directory into `.o` files and then links them to an executable specified in the Makefile (Target).

```bash
make
```

To build the project with debug flags, use the `debug` target. By default, it includes the `-g` flag for debugging information, this lets you debug the executable with programs like GDB.

```bash
make debug
```

For a list of available Makefile targets and their descriptions, you can use the `help` target.

```bash
make help
```

Once the program is compiled, the object files will be stored in the `out` directory, and the executable will be generated in the root directory (the same directory as the Makefile).

Feel free to modify the Makefile to suit your project's specific requirements.
