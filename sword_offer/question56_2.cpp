/* 小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!。*/

#include "question.h"

using namespace std;

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum)
	{
		vector<vector<int>> ret;
		if (sum <= 0)
			return ret;
		int temp = sqrt(2 * sum) ;
		while (temp > 1)
		{
			if (temp & 1)
				if (sum % temp == 0)
				{
					int start = (sum / temp) - (temp / 2);
					if (start <= 0)
					{
						temp--;
						continue;
					}
					vector<int> vec;
					for (int i = 0; i < temp; i++)
						vec.push_back(start++);
					ret.push_back(vec);
				}
				else;
			else if (sum % temp == (temp / 2))
			{
				int start = (sum / temp) - (temp / 2) + 1;
				if (start <= 0)
				{
					temp--;
					continue;
				}
				vector<int> vec;
				for (int i = 0; i < temp; i++)
					vec.push_back(start++);
				ret.push_back(vec);
			}
			temp--;
		}
		return ret;
	}
};

void question56_2()
{
	Solution s;
	int num1 = 0;
	int num2 = 0;
	vector<vector<int>> ret = s.FindContinuousSequence(3);
	for (auto a : ret)
	{
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
}