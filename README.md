Deprecated repository
=====================
This repository is scheduled to be deleted. Once all source files are moved
to new projects the repository will be deleted.

# Introduction 

This is a bare-kernel for embedded systems. It is intended for a bigger project 
which already includes some synchronization mechanisms. The initial idea was 
that this kernel would only provide minimal functionality for context switching.

eSolid is a collection of resources for embedded system design and this
Real-Time kernel is only a piece of that collection. Because of that fact
remember: *there are (still) no synchronization or IPC mechanisms in this kernel*, 
and it can be viewed as a preemptive Round-Robin scheduler, only.


## TODO list

- Integrate a profiling system (memory/stack usage, cpu usage...)
- test, test, test...


# Using eSolid - Real-Time Kernel

## Configuration and ports

Configuration is done in two files: `kernel_cfg.h` (port independent settings) 
and in `kcore_cfg.h` (port depended settings, located in port structure).
Currently, kernel is ported only to ARMv7-M architecture range of 
microcontrollers. It was tested on STM32F100 series of microcontrollers, but it
should work, with minimal modifications, on any ARMv7-M CPU. Some other ports 
like AVR-GCC are planned, too.


## Building

The kernel was built using arm-none-eabi GCC v4.7.3 compiler toolchain (from 
https://launchpad.net/gcc-arm-embedded/+download) and binary was downloaded
to the MCU using _texane_ gdb-server. There are no makefiles, it is assumed
that IDE will generate them for you.


#### Example for STM32F10x family port

There are two groups of source files which need to be compiled for ARMv7-M 
architecture: 
- kernel.c, semaphore.c in `./src` source directory and 
- kcore.c in `./port/arm-none-eabi-gcc/v7-m` port directory.

The following include paths are needed:
- `./inc`
- `./port/arm-none-eabi-gcc/v7-m`

## Documentation

Some documentation is available under Wiki 
https://github.com/nradulovic/esolid-kernel/wiki. 
Doxygen configuration and full documentation source files are available in `/doc` 
directory. Go to the directory `doc` create a directory named `kernel` and than 
run doxygen:

    # doxygen doxyfile-kernel

This will generate HTML, LaTex and man documentation in `./doc/kernel` directory.


## Running
To successfully use and run kernel you will need to study the kernel 
documentation. The documentation is still being written and some examples will
be added later.
