#include "CppPractice.h"


long task1() {

	long sum = 0;

	std::array<std::array<int8_t, 4000>, 2> buffer; //8000ints fit in half of the L1 cache 

	bool flag_first, flag_second;

	std::thread t1(producer_reader, std::ref(flag_first), std::ref(flag_second), std::ref(buffer));
	std::thread t2(consumer_calc_sum, std::ref(sum), std::ref(buffer), std::ref(flag_first), std::ref(flag_second));

	t1.join();
	t2.join();
	return sum;

}
void consumer_calc_sum(long& sum, std::array<std::array<int8_t, 4000>, 2> &buffer, bool& flag_first, bool& flag_second) {
	while (true) {
		if (flag_first || flag_second) {
			if (flag_first) {
				sum += std::accumulate(buffer[0].begin(), buffer[0].end(), 0);
				flag_first = !flag_first;
			}
			if (flag_second) {
				sum += std::accumulate(buffer[1].begin(), buffer[1].end(), 0);
				flag_second = !flag_second;
			}
		}
	}
}
void producer_reader(bool& flag_first, bool& flag_second, std::array<std::array<int8_t, 4000>, 2> &buffer) {
	std::ifstream file("binary.dat", std::ios::in | std::ios::binary);
	if (file.is_open())
	{
		int8_t* ptr = &buffer[0][0];
		int8_t* ptr1 = &buffer[1][0];
		while (!file.eof()) {
			if(!flag_first){
			file.read(reinterpret_cast<char*>(ptr), sizeof(buffer[0]));
			flag_first = !flag_first;
			}
			if (!flag_second) {
				file.read(reinterpret_cast<char*>(ptr1), sizeof(buffer[1]));
				flag_second = !flag_second;
			}
		}
	}
	file.close();

}
//std::vector<std::pair<int, std::pair<int, int>>> task2(int input[]) {
//    //You have an array of numbers. You have to give the range in which each number is the maximum element. For Example, If array is 1, 5, 4, 3, 6 The output would be
//    //1 [1, 1]
//    //5 [1, 4]
//    //4 [3, 4]
//    //3 [4, 4]
//    //6 [1, 5]
//
//    // dont have any good ideas, will look into it a bit more later, thinking about segmented trees
//}

int taks1_1_09_20201(const std::vector<int>& arr) {

	int i = 0;
	int valley = arr[0];
	int peak = arr[0];
	int maxprofit = 0;
	while (i < arr.size() - 1) {
		while (i < arr.size() - 1 && arr[i] >= arr[i + 1])
			i++;
		valley = arr[i];
		while (i < arr.size() - 1 && arr[i] <= arr[i + 1])
			i++;
		peak = arr[i];
		maxprofit += peak - valley;
	}
	return maxprofit;
}