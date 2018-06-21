/* 输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。*/

#include "question.h"

using namespace std;

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum)
	{
		vector<int> ret;
		for (auto a : array)
			for (int i = array.size() - 1; i > 0; i--)
			{
				if (a + array[i] < sum)
					break;
				else if (a + array[i] == sum)
				{
					ret.push_back(a);
					ret.push_back(array[i]);
					return  ret;
				}
			}
		return ret;
	}
};

void question57()
{
	Solution s;
	vector<int> vec = { 1,2,3,4,5,6,8,9 };
	vector<int> ret;
	ret = s.FindNumbersWithSum(vec, 10);
	for (auto a : ret)
		cout << a << " ";
	cout << endl;
}