#include <iostream>
#include <cstddef>
#include <vector>
#include <utility>
#include <stdexcept>
#include "Exer04_01_01.h"
using std::cout;
using std::endl;
using std::size_t;
using std::vector;
using std::pair;
using std::runtime_error;
int main()
{
	vector<int> vec1 = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
	vector<double> vec2;
	auto ret_div = find_max_subarray(vec1.begin(), vec1.end());
	auto ret_brute = brute_find_max_subarray(vec1.begin(), vec1.end());
	for(auto b = ret_div.pos.first; b != ret_div.pos.second; ++b)
		cout << *b << " ";
	cout << endl;
	cout << ret_div.max << endl;
	for(auto b = ret_brute.pos.first; b != ret_brute.pos.second; ++b)
		cout << *b << " ";
	cout << endl;
	cout << ret_brute.max << endl;
	try {
		find_max_subarray(vec2.begin(), vec2.end());
	} catch(runtime_error e) {
		cout << e.what() << endl;
	}
	return 0;
}