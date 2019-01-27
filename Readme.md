Approximate String Matching

Implemented algorithms: Dynamic, Dynamic with Ukkonen Cut-off, Myers (without Ukkonen Cut-off)

The project can be build with "make CONF=Release build" in the project root folder.
Requires make, and a c99 compiler.
A binary "asm" will be generated to dist/Release/

It can be used with "asm pattern maximum_error path_to_text".
It outputs the end positions of the where the levensthein distance is less or equal to "maximum_error".
"maximum_error" can be at most 64 for Myers algorithm to work.
The file will be read entirely to memory.
The memory usage for the algorithms rises linearly in respect to the pattern size.

The binary has been tested with gcc 6.3.1, linux kernel 4.9.11 (Arch Linux x64), glibc 2.24.
The source includes a Netbeans project file, and the make files are generated with it.

The test binary can be created with "make CONF=Test build".
It takes no parameters, and it outputs results of the tests to console.
The tests include a few precomputed distances, and a random testing tool.
The random test generates 20000 strings and compares the results of Ukkonen and Myers to the dynamic solution.

"make help" prints all the parameters for the build.
