# OS Simulation Project

## Overview
This project simulates various operating system algorithms including CPU scheduling, memory management, disk scheduling, and deadlock avoidance.

## Directory Structure





## How to Build
1. Create a build directory:
    ```
    mkdir build && cd build
    ```
2. Run CMake to configure the project:
    ```
    cmake ..
    ```
3. Build the project:
    ```
    make
    ```
4. Run the executable:
    ```
    ./os_simulation
    ```

## Features
- **CPU Scheduling Algorithms:**
  - First-Come, First-Served (FCFS)
  - Shortest Job First (SJF)
  - Round Robin (RR)
  - Priority Scheduling

- **Memory Management Algorithms:**
  - Paging
  - Segmentation
  - First-In-First-Out (FIFO) Page Replacement
  - Least Recently Used (LRU) Page Replacement

- **Disk Scheduling Algorithms:**
  - First-Come, First-Served (FCFS)
  - Shortest Seek Time First (SSTF)
  - SCAN
  - LOOK

- **Deadlock Avoidance:**
  - Banker's Algorithm

## Contribution
Feel free to open issues or create pull requests if you find any bugs or have suggestions for new features.

## License
This project is licensed under the MIT License.
