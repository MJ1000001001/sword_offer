/* 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!。*/

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