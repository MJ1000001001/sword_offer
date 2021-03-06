/* 一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。*/

#include "question.h"

using namespace std;

/* 先找出来只有只有一个数字出现了一次。用异或就可以搞定。因为出现两次的数组异或都会变成0,留下的只有出现一次的数字 */
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
	/* 全部异或，结果中找出为1的位，用这一位将整个数组分为两个数组，每个数组中就只有一个只出现了一次的数组 */
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