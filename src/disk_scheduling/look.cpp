#include <iostream>
#include <vector>
#include <algorithm>

void lookDiskScheduling(std::vector<int>& requests, int head, bool direction) {
    int seek_count = 0;
    int distance, cur_track;
    std::vector<int> left, right;
    std::vector<int> seek_sequence;

    for (int i = 0; i < requests.size(); ++i) {
        if (requests[i] < head)
            left.push_back(requests[i]);
        if (requests[i] > head)
            right.push_back(requests[i]);
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());

    if (direction) {
        for (int i = 0; i < right.size(); ++i) {
            cur_track = right[i];
            seek_sequence.push_back(cur_track);
            distance = std::abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }

        for (int i = left.size() - 1; i >= 0; --i) {
            cur_track = left[i];
            seek_sequence.push_back(cur_track);
            distance = std::abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }
    } else {
        for (int i = left.size() - 1; i >= 0; --i) {
            cur_track = left[i];
            seek_sequence.push_back(cur_track);
            distance = std::abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }

        for (int i = 0; i < right.size(); ++i) {
            cur_track = right[i];
            seek_sequence.push_back(cur_track);
            distance = std::abs(cur_track - head);
            seek_count += distance;
            head = cur_track;
        }
    }

    std::cout << "Total Seek Operations: " << seek_count << std::endl;
}
