#include <iostream>
#include <vector>
#include <queue>

struct Process {
    int pid;
    int burst_time;
    int remaining_time;
};

void rrScheduling(std::vector<Process>& processes, int time_quantum) {
    std::queue<Process*> ready_queue;

    for (auto& process : processes) {
        process.remaining_time = process.burst_time;
        ready_queue.push(&process);
    }

    int current_time = 0;
    int total_wait_time = 0;
    int total_turnaround_time = 0;

    while (!ready_queue.empty()) {
        Process* process = ready_queue.front();
        ready_queue.pop();

        if (process->remaining_time > time_quantum) {
            process->remaining_time -= time_quantum;
            current_time += time_quantum;
            ready_queue.push(process);
        } else {
            current_time += process->remaining_time;
            int wait_time = current_time - process->burst_time;
            int turnaround_time = current_time;

            total_wait_time += wait_time;
            total_turnaround_time += turnaround_time;

            std::cout << "Process " << process->pid << " - Wait Time: " << wait_time 
                      << ", Turnaround Time: " << turnaround_time << std::endl;

            process->remaining_time = 0;
        }
    }

    std::cout << "Average Wait Time: " << static_cast<float>(total_wait_time) / processes.size() << std::endl;
    std::cout << "Average Turnaround Time: " << static_cast<float>(total_turnaround_time) / processes.size() << std::endl;
}
