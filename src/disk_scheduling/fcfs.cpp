#include <iostream>
#include <vector>
#include <cmath>

void fcfsDiskScheduling(const std::vector<int>& requests, int head) {
    int seek_count = 0;
    int distance, cur_track;

    for (int i = 0; i < requests.size(); i++) {
        cur_track = requests[i];
        distance = std::abs(cur_track - head);
        seek_count += distance;
        head = cur_track;
    }

    std::cout << "Total Seek Operations: " << seek_count << std::endl;
}
