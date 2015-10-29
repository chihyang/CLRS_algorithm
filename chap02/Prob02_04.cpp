#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using sz = vector<int>::size_type;
sz merge_inversions(vector<int> &arr, sz p, sz q, sz r)
{
	auto n1 = q - p + 1;
	auto n2 = r - q;
	vector<int> L1(n1);
	vector<int> L2(n2);
	sz cnt = 0;
	for(auto i = 0; i < n1; ++i)
		L1[i] = arr[p + i];
	for(auto j = 0; j < n2; ++j)
		L2[j] = arr[q + j + 1];
	sz i = 0, j = 0, k = p;
	while(i < n1 && j < n2)
	{
		if(L1[i] > L2[j])
		{
			cnt += n1 - i;
			arr[k] = L2[j];
			++j;
		}
		else
		{
			arr[k] = L1[i];
			++i;
		}
		++k;
	}
	while(i < n1)
		arr[k++] = L1[i++];
	while(j < n2)
		arr[k++] = L2[j++];
	return cnt;
}
sz merge(vector<int> &arr, sz p, sz r)
{
	sz cnt = 0;
	if(p < r)
	{
		auto q = (p + r) / 2;
		cnt += merge(arr, p, q);
		cnt += merge(arr, q + 1, r);
		cnt += merge_inversions(arr, p, q, r);
	}
	return cnt;
}
int main()
{
	vector<int> a = {3, 41, 52, 26, 38, 57, 9, 49};
	for(auto ival : a)
		cout << ival << " ";
	cout << endl;
	sz cnt = merge(a, 0, 7);
	cout << cnt << endl;
	for(auto ival : a)
		cout << ival << " ";
	return 0;
}