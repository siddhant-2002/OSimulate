#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

void fifoPageReplacement(const std::vector<int>& pages, int frame_size) {
    std::unordered_set<int> s;
    std::queue<int> indexes;

    int page_faults = 0;
    for (int page : pages) {
        if (s.size() < frame_size) {
            if (s.find(page) == s.end()) {
                s.insert(page);
                indexes.push(page);
                page_faults++;
            }
        } else {
            if (s.find(page) == s.end()) {
                int val = indexes.front();
                indexes.pop();
                s.erase(val);
                s.insert(page);
                indexes.push(page);
                page_faults++;
            }
        }
    }

    std::cout << "Total Page Faults: " << page_faults << std::endl;
}
