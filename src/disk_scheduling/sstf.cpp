#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits> // Include for INT_MAX

void sstfDiskScheduling(std::vector<int>& requests, int head) {
    int seek_count = 0;
    int distance, cur_track;
    std::vector<bool> visited(requests.size(), false);

    for (int i = 0; i < requests.size(); ++i) {
        int min_distance = 131613491;
        int min_index = -1; // Initialize min_index to a valid value

        for (int j = 0; j < requests.size(); ++j) {
            if (!visited[j] && std::abs(requests[j] - head) < min_distance) {
                min_distance = std::abs(requests[j] - head);
                min_index = j;
            }
        }

        if(min_index != -1) { // Check if min_index was updated
            visited[min_index] = true;
            cur_track = requests[min_index];
            distance = std::abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }
    }

    std::cout << "Total Seek Operations: " << seek_count << std::endl;
}