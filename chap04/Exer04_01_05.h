#ifndef EXER04_01_05_H
#define EXER04_01_05_H
#include <cstddef>
#include <type_traits>
#include <stdexcept>
// class to store the result
template <typename It, typename T>
struct max_pos {
	std::pair<It, It> pos; // maximum subarray, represented by a pair of iterator
	T max;
};
template <typename It>
auto linear_find_max_subarray(It beg, It end) ->
    max_pos<It, typename std::remove_reference<decltype(*beg)>::type>
{
	typedef typename std::remove_reference<decltype(*beg)>::type value_type;
	if(beg == end)
		throw std::runtime_error("Empty input sequence!");
	value_type max = *beg; // sum of max subarray
	value_type max_with_end = value_type(); // sum of max subarray that contains the last element
	It left_max = beg, right_max = left_max; // max subarray
	It left_max_with_end = beg, right_max_with_end = left_max_with_end; // max subarray that contains the last element
	for (It i = beg; i != end; ++i) {
		if (*i < max_with_end + *i) {
			max_with_end = max_with_end + *i;
		} else {
			max_with_end = *i;
			left_max_with_end = i;
		}
		right_max_with_end = i;
		if (max < max_with_end) {
			max = max_with_end;
			left_max = left_max_with_end;
			right_max = right_max_with_end;
		}
	}
	return max_pos<It, value_type>{{left_max, ++right_max}, max};
}
#endif