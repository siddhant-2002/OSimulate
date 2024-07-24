#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

void sstfDiskScheduling(std::vector<int>& requests, int head) {
    int seek_count = 0;
    int distance, cur_track;
    std::vector<bool> visited(requests.size(), false);

    for (int i = 0; i < requests.size(); ++i) {
        int min_distance = INT_MAX;
        int min_index;

        for (int j = 0; j < requests.size(); ++j) {
            if (!visited[j] && std::abs(requests[j] - head) < min_distance) {
                min_distance = std::abs(requests[j] - head);
                min_index = j;
            }
        }

        visited[min_index] = true;
        cur_track = requests[min_index];
        distance = std::abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }

    std::cout << "Total Seek Operations: " << seek_count << std::endl;
}
