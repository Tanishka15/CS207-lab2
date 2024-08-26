#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <set>

class MemoryManager {
public:
    MemoryManager(int total_pages);
    void SetTotalPages(int total_pages);
    int allocatePage();
    void deallocatePage(int page);
    int availablePageCount() const;
    void printAvailablePages() const;
    void resetMemoryManager();

private:
    int totalPages;
    std::set<int> availablePages;
};

#endif // MEMORYMANAGER_H
