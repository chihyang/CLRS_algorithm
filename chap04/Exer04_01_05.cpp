// This program uses data file ./data/max_subarray
#include <iostream>
#include <vector>
#include <stdexcept>
#include "Exer04_01_05.h"
using std::cout;
using std::endl;
using std::ofstream;
using std::vector;
using std::pair;
using std::runtime_error;
int main()
{
	vector<int> vec = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
	auto ret_line = linear_find_max_subarray(vec.begin(), vec.end());
	for(auto i = ret_line.pos.first; i != ret_line.pos.second; ++i)
		cout << *i << " ";
	cout << endl;
	cout << ret_line.max << endl;
	return 0;
}
