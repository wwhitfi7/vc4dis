# Yaml Processor

## Background Information
For extensibility and easy modification, the architecture this disassembler targets is completely defined as a set of instructions and register definitions in config/ARCH. This is great, but those files require parsing to be usable. Determine whether or not to use a parsing library, or roll our own.

## Extant Libraries
### Pros:
- No need to write my own parser for yaml files, when one already needs creation for the bitstream/input file
- Simplifies development
- Several libraries targeting .yml exist
### Cons:
- Libraries could be heavy (requires further research)
- Might be slow?
- Need to interact with and learn a new API.

## Write my own
### Pros:
- Could be fun
- Might be faster, definitely smaller than most libraries out there since only targeting a specific subset of the language
- Could switch away from yaml to format that is designed to work with the program as a whole
### Cons:
- Slows development, might take a week
- Takes time away from writing the nitty-gritty that I really enjoy
- I could write a worse version of something that already exists
