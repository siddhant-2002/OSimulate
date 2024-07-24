#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

void pagingSimulation();
void segmentationSimulation();
void fifoPageReplacement(const std::vector<int>& pages, int frame_size);
void lruPageReplacement(const std::vector<int>& pages, int frame_size);

#endif // MEMORY_H
