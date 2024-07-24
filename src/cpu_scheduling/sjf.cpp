#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
    int pid;
    int burst_time;
};

bool compareBurstTime(const Process& a, const Process& b) {
    return a.burst_time < b.burst_time;
}

void sjfScheduling(std::vector<Process>& processes) {
    std::sort(processes.begin(), processes.end(), compareBurstTime);

    int wait_time = 0;
    int total_wait_time = 0;
    int total_turnaround_time = 0;

    for (const auto& process : processes) {
        total_wait_time += wait_time;
        int turnaround_time = wait_time + process.burst_time;
        total_turnaround_time += turnaround_time;

        std::cout << "Process " << process.pid << " - Wait Time: " << wait_time 
                  << ", Turnaround Time: " << turnaround_time << std::endl;

        wait_time += process.burst_time;
    }

    std::cout << "Average Wait Time: " << static_cast<float>(total_wait_time) / processes.size() << std::endl;
    std::cout << "Average Turnaround Time: " << static_cast<float>(total_turnaround_time) / processes.size() << std::endl;
}
