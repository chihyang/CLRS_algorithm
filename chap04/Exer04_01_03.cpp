// This program uses data file ./data/max_subarray
#include <cstddef>
#include <ctime>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include "Exer04_01_03.h"
using std::size_t;
using std::clock_t;
using std::clock;
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::find_end;
using std::pair;
using std::runtime_error;
int main(int argc, char* argv[])
{
	if (argc != 2)
		return -1;
	ifstream is(argv[1]);
	vector<double> vec;
	vector<double> time_div;
	vector<double> time_brute;
	double data;
	while (is >> data) {
		vec.push_back(data);
	}
	unsigned loop = 10000;
	clock_t t_div;
	clock_t t_brute;
	for(unsigned i = 1; i < vec.size(); ++i) {
		if(i < 100) {
			t_div = clock();
			for(unsigned j = 0; j < loop; ++j) {
				auto ret_div = find_max_subarray(vec.begin(), vec.begin() + i);
			}
			t_div = clock() - t_div;
			t_brute = clock();
			for(unsigned j = 0; j < loop; ++j) {
				auto ret_brute = brute_find_max_subarray(vec.begin(), vec.begin() + i);
			}
			t_brute = clock() - t_brute;
		} else {
			/* t_div = clock();
			auto ret_div = find_max_subarray(vec.begin(), vec.begin() + i);
			t_div = clock() - t_div;
			t_brute = clock();
			auto ret_brute = brute_find_max_subarray(vec.begin(), vec.begin() + i);
			t_brute = clock() - t_brute; */
			break;
		}
		time_div.push_back(static_cast<double>(t_div) / CLOCKS_PER_SEC);
		time_brute.push_back(static_cast<double>(t_brute) / CLOCKS_PER_SEC);
	}
	ofstream os("result.txt");
	os << std::showpoint;
	for (size_t i = 0; i < time_div.size(); ++i) {
		os << *(time_div.begin() + i) << "\t" << *(time_brute.begin() + i) << endl;
	}
	return 0;
}
// Note: see http://www.cplusplus.com/reference/ctime/clock/ for clock_t.