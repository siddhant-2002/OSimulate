#ifndef SCHEDULING_H
#define SCHEDULING_H

#include <vector>

struct Process {
    int pid;
    int burst_time;
    int remaining_time;
    int priority;
};

void fcfsScheduling(const std::vector<Process>& processes);
void sjfScheduling(std::vector<Process>& processes);
void rrScheduling(std::vector<Process>& processes, int time_quantum);
void priorityScheduling(std::vector<Process>& processes);

#endif // SCHEDULING_H
