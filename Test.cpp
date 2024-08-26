// test.cpp
#include "MemoryManager.h"
#include "Task.h"
#include "IOManager.h"
#include "config.h"
#include "Performance.h"
#include <iostream>
#include <map>
#include <vector>
#include <chrono> // Include this header for std::chrono

// Two global variables
// one a map of all tasks 
// and the other to store the current page size under consideration

std::map<std::string, Task*> tasks;
int current_page_size;
MemoryManager memManager(1);

int main() {
    Performance perf = Performance();

    SingleLevelTask task1(1);
    TwoLevelTask task2(2);

    long long unsigned int num_pages = PHYSICAL_MEMORY_SIZE_16GB / PAGE_SIZE_1KB;

    memManager = MemoryManager((int)num_pages);

    tasks["T1"] = &task1;
    tasks["T2"] = &task2;

    // List of trace files to process
    std::vector<std::string> traceFiles = {
        "tracefile_1KB_8GB_16GB.txt",
        "tracefile_2KB_4GB_8GB.txt",
        "tracefile_4KB_4GB_4GB.txt"
    };

    // Process each trace file
    // Instead of making a loop, since it's only three
    // Copied the code three times

    // Process trace file 1 - tracefile_1KB_8GB_16GB.txt

    auto start = std::chrono::high_resolution_clock::now();
    current_page_size = PAGE_SIZE_1KB;

    IOManager::processTraceFile("tracefile_1KB_8GB_16GB.txt");

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    perf.storeFileAndExecutionTime("tracefile_1KB_8GB_16GB.txt", duration.count());

    std::cout << "\n\nTrace File tracefile_1KB_8GB_16GB output: " << std::endl;

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        it->second->printTaskData();
    }
    std::cout << "\nRemaining Available Pages: " << memManager.availablePageCount() << std::endl;

    memManager.resetMemoryManager();
    tasks.clear();

    // Process trace file 2 - tracefile_2KB_4GB_8GB.txt
    num_pages = PHYSICAL_MEMORY_SIZE_8GB / PAGE_SIZE_2KB;
    memManager.SetTotalPages(int(num_pages));
    current_page_size = PAGE_SIZE_2KB;

    start = std::chrono::high_resolution_clock::now();

    IOManager::processTraceFile("tracefile_2KB_4GB_8GB.txt");

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    perf.storeFileAndExecutionTime("tracefile_2KB_4GB_8GB.txt", duration.count());

    std::cout << "\n\nTrace File tracefile_2KB_4GB_8GB output: " << std::endl;
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        it->second->printTaskData();
    }
    std::cout << "\nRemaining Available Pages: " << memManager.availablePageCount() << std::endl;

    memManager.resetMemoryManager();
    tasks.clear();

    // Process trace file 3 - tracefile_4KB_4GB_4GB.txt

    num_pages = PHYSICAL_MEMORY_SIZE_4GB / PAGE_SIZE_4KB;
    memManager.SetTotalPages((int)num_pages);

    current_page_size = PAGE_SIZE_4KB;

    start = std::chrono::high_resolution_clock::now();

    IOManager::processTraceFile("tracefile_4KB_4GB_4GB.txt");

    stop = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    perf.storeFileAndExecutionTime("tracefile_4KB_4GB_4GB.txt", duration.count());

    std::cout << "\n\nTrace File tracefile_4KB_4GB_4GB output: " << std::endl;

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        it->second->printTaskData();
    }
    std::cout << "\nRemaining Available Pages: " << memManager.availablePageCount() << std::endl;

    std::cout << "\nPerformance Statistics: " << std::endl;
    perf.printTotalStatistics();

    return 0;
}
// Task.h
