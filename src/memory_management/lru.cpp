#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // For std::find
#include <climits> // For INT_MAX

void lruPageReplacement(const std::vector<int>& pages, int frame_size) {
    std::unordered_map<int, int> indexes;
    std::vector<int> frames;
    int page_faults = 0;

    for (int i = 0; i < pages.size(); ++i) {
        if (frames.size() < frame_size) {
            if (std::find(frames.begin(), frames.end(), pages[i]) == frames.end()) {
                frames.push_back(pages[i]);
                page_faults++;
            }
            indexes[pages[i]] = i;
        } else {
            if (std::find(frames.begin(), frames.end(), pages[i]) == frames.end()) {
                int lru = INT_MAX, val = -1; // Initialize val to a valid value
                for (int j = 0; j < frames.size(); ++j) {
                    if (indexes[frames[j]] < lru) {
                        lru = indexes[frames[j]];
                        val = frames[j];
                    }
                }
                auto it = std::find(frames.begin(), frames.end(), val);
                frames[it - frames.begin()] = pages[i];
                page_faults++;
            }
            indexes[pages[i]] = i;
        }
    }

    std::cout << "Total Page Faults: " << page_faults << std::endl;
}