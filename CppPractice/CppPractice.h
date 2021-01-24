#pragma once
#include <boost/circular_buffer.hpp>

#include <iostream>
#include <fstream>

#include <thread>
#include <mutex>

#include <vector>
#include <string>
#include <queue>
#include <map>

#include <math.h>

long task1();
std::vector<std::pair<int, std::pair<int, int>>> task2(int input[]);
std::vector<short> task4(std::vector<std::pair<short, short>> input);
void calc_sum(long& sum, char* buf);