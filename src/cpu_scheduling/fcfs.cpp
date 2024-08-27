#include <iostream>
#include <vector>

struct Process {
    int pid; // Process ID
    int burst_time; // Burst Time of the process
};

void fcfsScheduling(const std::vector<Process>& processes) {
    int wait_time = 0;
    int total_wait_time = 0; 
    int total_turnaround_time = 0;

    for (const auto& process : processes) {
        total_wait_time += wait_time;
        int turnaround_time = wait_time + process.burst_time;
        total_turnaround_time += turnaround_time;

        // Print Process details
        std::cout << "Process " << process.pid << " - Wait Time: " << wait_time << ", Turnaround Time: " << turnaround_time << std::endl;

        // Update wait_time for the next process
        wait_time += process.burst_time;
    }

    int num_processes = processes.size();
    std::cout << "Average Wait Time: " << static_cast<double>(total_wait_time) / num_processes << std::endl;
    std::cout << "Average Turnaround Time: " << static_cast<double>(total_turnaround_time) / num_processes << std::endl;
}