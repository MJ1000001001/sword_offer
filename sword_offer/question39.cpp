/*数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。*/

#include "question.h"

using namespace std;

#if 0
/* 解法1:用一个辅助数组将数组中所有的数字出现的次数都保存起来。然后判断是否有符合条件的。 */
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int max = INT_MIN;

		for (int i = 0; i < numbers.size(); i++)
			if (max < numbers[i])
				max = numbers[i];
		vector<int> vec(max+1, 0);

		for (int i = 0; i < numbers.size(); i++)
			vec[numbers[i]]++;
		for (int i = 0; i < numbers.size(); i++)
			if (vec[numbers[i]] >(numbers.size() / 2))
				return numbers[i];
		return 0;
	}
};
#endif

/* 解法2:因为要找出来的数次数大于其他所有的数之和。所以可以从第一个数开始计数，如果是接下来的数还是一样的，则+1，否则-1.若次数为0.则修改检测的数。 */
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;

		int temp = *numbers.begin();
		int time = 1;
		for (int i = 1; i < numbers.size(); i++)
		{
			if (time == 0)
				temp = numbers[i];
			if (temp == numbers[i])
				time++;
			else
				time--;
		}
		for (int i = 0; i < numbers.size(); i++)
			if (temp == numbers[i])
				time++;
		if (time * 2 > numbers.size())
			return temp;
		return 0;
	}
};

void question39()
{
	Solution s;
	vector<int> param{ 2,2,2,2,2,1,3,4,5 };
	cout << s.MoreThanHalfNum_Solution(param) << endl;
}