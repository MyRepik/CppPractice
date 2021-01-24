#include "CppPractice.h"


long task1() {
	// gave it some more thoughts
	// decided not to proceed with this idea, since bottleneck here is not CPU but I/O
	//threding wont do much asspecialy if disc is HDD
	//After going over casts didnt notice anything special, will stick to reinterpret_cast

	long sum = 0;
	std::ifstream file("binary.dat", std::ios::in | std::ios::binary);
	boost::circular_buffer<char[32000]> cb(2);
	bool flag_first, flag_second;

	std::thread t1(producer_reader, flag_first, flag_second, file,cb);
	std::thread t2(consumer_calc_sum,sum,cb, flag_first, flag_second);

	t1.join();
	t2.join();
	return sum;

}
void consumer_calc_sum(long& sum, boost::circular_buffer<char[32000]>& cb, bool& flag_first, bool& flag_second) {
	while (true) {
		if (flag_first || flag_second) {
			if (flag_first) {
				int* ptr = reinterpret_cast<int*>(cb[0]);
				for (int i = 0; i < 1024; i++) {
					sum += *ptr;
					ptr++;
				}
				flag_first = !flag_first;
			}
			if (flag_second) {
				int* ptr = reinterpret_cast<int*>(cb[1]);
				for (int i = 0; i < 1024; i++) {
					sum += *ptr;
					ptr++;
				}
				flag_second = !flag_second;
			}
		}
	}
}
void producer_reader(bool& flag_first, bool& flag_second, std::ifstream file, boost::circular_buffer<char[32000]>& cb) {
	char buf[32000];
	if (file.is_open())
	{
		while (!file.eof()) {
			if(!flag_first){
			file.read(buf, sizeof(buf));
			cb.push_back(buf);
			flag_first = !flag_first;
			}
			if (!flag_second) {
				file.read(buf, sizeof(buf));
				cb.push_back(buf);
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