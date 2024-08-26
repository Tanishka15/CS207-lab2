
# Memory Management System

## Overview

The Memory Management System project is designed to simulate memory allocation and deallocation using various memory management techniques. This C++ project supports both single-level and two-level page tables, and measures performance metrics such as execution time and memory usage. It processes trace files to simulate memory operations under different configurations.

## Features

- **Memory Management**: Efficiently manages physical and virtual memory using page tables.
- **Task Management**: Supports multiple tasks with independent page tables.
- **Performance Tracking**: Measures execution time and memory usage.
- **Trace File Processing**: Reads and processes trace files to simulate memory operations.

## Components

- **` config.h`**: Configuration file defining constants for page sizes, memory sizes, and section start addresses.
- **`IO_Module.h`**: Header file for `IOManager`, responsible for trace file processing.
- **`IOManager.cpp`**: Implements functions to process trace files and manage memory requests.
- **` MemoryManager.pp**: Implements memory management functions for allocating and deallocating pages.
- **` Performance.h`**: Header file for `Performance`, tracking execution times and memory usage.
- **` Performance.pp**: Implements functions to manage and display performance statistics.
- **`PerformanceModule.h`**: The header file for `PerformanceModule` computes memory usage statistics.
- **`Task. pp**: Implements the `Task` class and its derived classes (`SingleLevelTask` and `TwoLevelTask`), managing page tables and memory requests.

## Trace Files

The project uses the following trace files to simulate memory operations:

- **`tracefile_1KB_8GB_16GB.txt`**: For a 1KB page size, 8GB physical memory and 16GB virtual memory.
- **`tracefile_2KB_4GB_8GB.txt`**: For a 2KB page size, 4GB physical memory, and virtual memory.
- **`tracefile_4KB_4GB_4GB.txt`**: 4KB page size, 4GB physical memory, and 4GB virtual memory.

## Compilation

To build the project, use the provided `Makefile`. Ensure that all necessary source files and header files are available.



