# Abandoning yaml in favor of C++

## Background
Although yaml is an excellent data language, moving definitions of the architecture from a .yml file to a series of CPP headers may ultimately benefit the project. Not only could CPP headers easily permit definition of most opcodes, they would allow directly importing and working with the instruction set in the program without complicated parsing and transformations that would slow down program startup. 

Pros:
- Headers can be directly imported and used
- Less compute wasted on parsing yaml, dynamically generating maps for text/binary

Cons:
- Static, altering instruction set requires recompile
- Harder to target more than one instruction set
