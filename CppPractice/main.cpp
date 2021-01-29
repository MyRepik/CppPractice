#include "CppPractice.h"

int main() {

    std::array<char, 32> buffer = { 1,1 ,1 ,1 ,1 ,1 ,1 ,1,1,1 ,1 ,1 ,1 ,1 ,1 ,1,1,1 ,1 ,1 ,1 ,1 ,1 ,1,1,1 ,1 ,1 ,1 ,1 ,1 ,1 };
   // std::array<std::array<char, 32>, 2> buffer = { {1,1,1,1,1,1,1,} };// {2, 2, 2, 2, 2, 2, 2, }

    int sum = std::accumulate(buffer.begin(), buffer.end(), 0);
    std::cout << sum << std::endl;
    int kek = (int)(1);
    std::cout << kek << std::endl;
    std::cin >> sum;
    return 0;


}