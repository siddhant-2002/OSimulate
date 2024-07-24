#ifndef DISK_H
#define DISK_H

#include <vector>

void fcfsDiskScheduling(const std::vector<int>& requests, int head);
void sstfDiskScheduling(std::vector<int>& requests, int head);
void scanDiskScheduling(std::vector<int>& requests, int head, int disk_size, bool direction);
void lookDiskScheduling(std::vector<int>& requests, int head, bool direction);

#endif // DISK_H
