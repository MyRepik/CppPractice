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
#include <array>

#include <numeric>

#include <math.h>

long task1();
void consumer_calc_sum(long& sum, std::array<std::array<int8_t, 4000>, 2>& buffer, bool& flag_first, bool& flag_second);
void producer_reader(bool& flag_first, bool& flag_second,std::array<std::array<int8_t, 4000>, 2>& buffer);