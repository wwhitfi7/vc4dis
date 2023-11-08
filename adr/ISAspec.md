#Instruction Set Architecture Representation
## Background
The Instruction Set of a processor is the set of commands that can be given to that processor in order to accomplish some work with it. These commands can accomplish various tasks like loading bytes into registers from memroy, adding them, performing more complex operations on them, etc. In order to disassemble a program from a binary into a human-readable assembly language, it's important for the disassembler to actually know the instructions the processor is capable of and create instructions using them. Although I was tempted to hardcode the ISA of the VideoCore IV GPU (since that's primarily what I intend to dissassemble programs for), I instead decided to make this disassembler more useful in the hopes that it can be reused for an arbitrary future processor.
## Representation
Thus, the disassembler needs to have some internal representation of instructions and a way to ensure that its output is always congruent with the specification of the instruction set. Much like a higher-level programming language, the instruction set of a system can be viewed as yet another language - after all, it has a specified grammar defined by the execution cycle of the processor and various rules surrounding usage. 

Yaml files describing an ISA require:
    1. The length or lengths of an instruction (VideoCore IV has 16, 32, 48, and 80 bit instructions)
    2. The rules used to determine length of an instruction
    3. The memory range and registers that may be affected
    4. A regex pattern matching that instruction

My current intent is to fully represnt 16, 32, and 48 bit scalar instructions. The VideoCore IV is also capable of 48 and 80 bit vector instructions - although I intend to recognize them, I do not intend to fully represnt them until I better understand them. The system will always fetch the minimum instruction length, and invalid instructions will be skipped but marked as data when applicable in order to continue searching for instructions in the blob.
