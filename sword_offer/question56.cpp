/* һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�*/

#include "question.h"

using namespace std;

/* ���ҳ���ֻ��ֻ��һ�����ֳ�����һ�Ρ������Ϳ��Ը㶨����Ϊ�������ε�������򶼻���0,���µ�ֻ�г���һ�ε����� */
class Solution {
public:
	void FindOneAppearOnce(vector<int> data, int *num)
	{
		if (data.empty())
		{
			*num = -1;
			return;
		}
		*num = data[0];
		for (auto a = data.begin() + 1; a < data.end(); a++)
			*num = *num ^ *a;
	}
	/* ȫ����򣬽�����ҳ�Ϊ1��λ������һλ�����������Ϊ�������飬ÿ�������о�ֻ��һ��ֻ������һ�ε����� */
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
	{
		int temp = data[0];

		for (auto a = data.begin() + 1; a < data.end(); a++)
			temp = temp ^ *a;
		while (1)
		{
			if (!(temp & temp - 1))
				break;
			temp = temp & (temp - 1);
		}

		vector<int> data1;
		vector<int> data2;
		for (auto a : data)
		{
			if (a & temp)
				data1.push_back(a);
			else
				data2.push_back(a);
		}
		FindOneAppearOnce(data1, num1);
		FindOneAppearOnce(data2, num2);
	}
};

void question56()
{
	Solution s;
	int num1 = 0;
	int num2 = 0;
	vector<int> data = { 1,2,2,1,4,3,4,5,5,9 };
	s.FindNumsAppearOnce(data, &num1, &num2);
	cout << num1 << " " << num2 << endl;
}