# Project Scope
## Background 
This project is mostly being created as a learning experience to gain some footing working with embedded software. Because the VideoCore IV processor on the Broadcomm 2835 of the Raspberry Pi Zero W is so integral to booting the system, an attempt to fully understand its boot sequence beyond a vague and high-level overview is a good segue into further development on the RPi. Reading the works of Herman Hermitage in reverse engineering the processor, along with efforts made by Emma Anholt to create an open source graphics driver for the chip has lent better understanding of the chip's architecture, but I sought to understand exactly how the chip accomplishes memory initialization, enabling of hardware, and so on - hence this project. Although I made an attempt to use an extant disassembler created by Hermitage and decipher exactly how that works, I was deterred by lack of user functionality (it just directly converted binary to assembly, which got quite extensive quite quickly).
## Initial Phases
The initial phases of this project are to create a bare-bones disassembler targeting the VideoCore IV architecture (and hopefully make the disassembler configurable and flexible enough to target other processors). Once that's accomplished, I want to add some IDA-esque features such as annotation, code flow graphing, etc. 

I intend for the processor/ISA to be configurable and capable of handling similar architectures, ideally read in from a config file. I do not intend to create a general purpose disassembler that can handle every processor ever made, or a hardware accelerated emulator of any extant processor (for now).
## Why not use extant tools?
1. At some point I probably will make a processor plugin for Ghidra or IDA.
2. I wanted to get more familiar with the processor and its architecture - I've always learned well through immersion
3. It's fun to work on hard/complex problems - even if someone's already done a lot of the work, it can be fun to tackle this stuff independently.
