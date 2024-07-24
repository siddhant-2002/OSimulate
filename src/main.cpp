#include <iostream>
#include "cpu_scheduling/scheduling.h"
#include "memory_management/memory.h"
#include "disk_scheduling/disk.h"
#include "deadlock_avoidance/deadlock.h"
#include "utils.h"

int main()
{
    std::cout << "OS Simulation Project" << std::endl;

    printHeader("CPU Scheduling - FCFS");
    std::vector<Process> processes = {{1, 24}, {2, 3}, {3, 3}};
    fcfsScheduling(processes);

    printHeader("Memory Management - FIFO Page Replacement");
    std::vector<int> pages = {1, 3, 0, 3, 5, 6};
    fifoPageReplacement(pages, 3);

    printHeader("Disk Scheduling - FCFS");
    std::vector<int> requests = {98, 183, 37, 122, 14, 124, 65, 67};
    fcfsDiskScheduling(requests, 53);

    printHeader("Deadlock Avoidance - Banker's Algorithm");
    bankersAlgorithm();

    return 0;
}
