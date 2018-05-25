/*输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/
#include "question.h"
using namespace std;

template <class A>
class display
{
public:
	void operator()(const A& temp)
	{
		cout << temp << " ";
	}
};

#if 0
class Solution {
public:
	void reOrderArray(vector<int> &array) {
		if (array.size() == 0)
			return;
		int odd_count = 0;
		for(auto a:array)
		{
			if (a & 0x01)
			{
				odd_count++;
			}
		}
		int even_index = odd_count;
		int odd_index = 0;
		int temp;
		while (odd_index < odd_count)
		{
			while (odd_index < odd_count)
			{
				if (!(array[odd_index] & 0x01))
				{
					break;
				}
				odd_index++;
			}
			while (even_index < array.size())
			{
				if (array[even_index] & 0x01)
				{
					temp = array[odd_index];
					array[odd_index] = array[even_index];
					array[even_index] = temp;
					odd_index++;
					even_index++;
					break;
				}
				even_index++;
			}
		}
	}
};
#endif

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		vector<int> temp_vec(array);
		int index = 0;
		for (auto a : temp_vec)
			if (a & 0x01)
				array[index++] = a;
		for (auto a : temp_vec)
			if (!(a & 0x01))
				array[index++] = a;
	}
};

void question21()
{
	Solution s;
	vector<int> vec;
	int n;
	int temp;
	cin >> n;
	while (n--)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	s.reOrderArray(vec);
	for_each(vec.begin(),vec.end(),display<int>());
	cout << endl;
}