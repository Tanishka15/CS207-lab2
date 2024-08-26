// MemoryManager.cpp
#include "MemoryManager.h"
#include <iostream>
#include <vector>

int total_pages_used;

MemoryManager::MemoryManager(int total_pages) {
    totalPages = total_pages;
    for (int i = 0; i < totalPages; ++i) {
        availablePages.insert(i);
    }
}

void MemoryManager::SetTotalPages(int total_pages) {
    totalPages = total_pages;
    availablePages.clear();
    for (int i = 0; i < totalPages; ++i) {
        availablePages.insert(i);
    }
}

int MemoryManager::allocatePage() {
    if (availablePages.empty()) {
        std::cerr << "No available pages to allocate." << std::endl;
        return -1; // Return -1 if no pages are available
    }
    int allocatedPage = *availablePages.begin();
    availablePages.erase(availablePages.begin());
    return allocatedPage;
}

void MemoryManager::deallocatePage(int page) {
    if (page < 0 || page >= totalPages) {
        std::cerr << "Invalid page number." << std::endl;
        return;
    }
    availablePages.insert(page);
}

int MemoryManager::availablePageCount() const {
    return availablePages.size();
}

void MemoryManager::printAvailablePages() const {
    std::cout << "Available Pages: ";
    for (int page : availablePages) {
        std::cout << page << " ";
    }
    std::cout << std::endl;
}

void MemoryManager::resetMemoryManager() {
    availablePages.clear();
    totalPages = 0;
}
