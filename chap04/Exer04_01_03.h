#include <iostream>
#include <utility>
#include <type_traits>
#include <stdexcept>
// class to store the result
template <typename It, typename T>
struct max_pos {
	std::pair<It, It> pos; // maximum subarray, represented by a pair of iterator
	T max;
};
// brute force
template <typename It>
auto brute_find_max_subarray(It beg, It end) -> 
    max_pos<It, typename std::remove_reference<decltype(*beg)>::type>
{
	typedef typename std::remove_reference<decltype(*beg)>::type value_type;
	if(beg == end)
		throw std::runtime_error("Empty input sequence!");
	value_type max = *beg;
	It left_max = beg, right_max = left_max;
	for(It i = beg; i != end; ++i)
	{
		value_type sum = value_type();
		for(It j = i; j != end; ++j)
		{
			sum += *j;
			if(max < sum) {
				left_max = i;
				right_max = j;
				max = sum;
			}
		}
	}
	// the end is one past the last position
	return max_pos<It, value_type>{{left_max, ++right_max}, max};
}
// divide-and-conquer to find the maximum subarray
template <typename It>
auto find_max_crossing_subarray(It beg, It mid, It end) ->
    max_pos<It, typename std::remove_reference<decltype(*beg)>::type>
{
	typedef typename std::remove_reference<decltype(*beg)>::type value_type;
	value_type left_sum = *(mid - 1);
	value_type right_sum = *mid;
	It pos_left = mid - 1, pos_right = mid;
	value_type sum = value_type();
	for (auto i = mid - 1; beg <= i; --i) {
		sum += *i;
		if (left_sum <= sum) {
			pos_left = i; // the first position
			left_sum = sum;
		}
	}
	sum = value_type();
	for(auto j = mid; j < end; ++j) {
		sum += *j;
		if (right_sum <= sum) {
			pos_right = j;
			right_sum = sum;
		}
	}
	// the end is one past the last position
	return max_pos<It, value_type>{{pos_left, ++pos_right}, left_sum + right_sum};
}
template <typename It>
auto find_max_subarray(It beg, It end) ->
    max_pos<It, typename std::remove_reference<decltype(*beg)>::type>
{
	typedef typename std::remove_reference<decltype(*beg)>::type value_type;
	if (beg == end)
		throw std::runtime_error("Empty input sequence!");
	if (end - beg == 1)
		return max_pos<It, value_type>{{beg, end}, *beg};
	else {
		auto mid = beg + (end - beg) / 2;
		auto ret_left = find_max_subarray(beg, mid);
		auto ret_right = find_max_subarray(mid, end);
		auto ret_mid = find_max_crossing_subarray(beg, mid, end);
		if(ret_mid.max <= ret_left.max && ret_right.max <= ret_left.max)
			return ret_left;
		else if(ret_left.max <= ret_right.max && ret_mid.max <= ret_right.max)
			return ret_right;
		else
			return ret_mid;
	}
}