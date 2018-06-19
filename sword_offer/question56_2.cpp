/* С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100�����������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22�����ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������? Good Luck!��*/

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