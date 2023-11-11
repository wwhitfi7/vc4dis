# Abandoning yaml in favor of C++

## Background
Although yaml is an excellent data language, moving definitions of the architecture from a .yml file to a series of CPP headers may ultimately benefit the project. Not only could CPP headers easily permit definition of most opcodes, they would allow directly importing and working with the instruction set in the program without complicated parsing and transformations that would slow down program startup. 

Pros:
- Headers can be directly imported and used
- Less compute wasted on parsing yaml, dynamically generating maps for text/binary

Cons:
- Static, altering instruction set requires recompile
- Harder to target more than one instruction set

## Addendum 1:
Instead of using C++ headers compiled into the program, the program could instead load a dynamic shared library. For example, we could load in a library that supports a specific architecture, and other architectures supported by the program could be implemented as their own shared library with the appropriate functions and data types to support that architecture. So long as any shared library conforms to an expected interface with the larger program, it should be possible to represent most instructions and their arguments using a library instead of a YAML file, OR direct compilation/hardcoding :D.
