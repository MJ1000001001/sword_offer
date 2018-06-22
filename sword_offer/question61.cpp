/* 决定大\小 王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4),“So Lucky!”。*/

#include "question.h"

using namespace std;

/* 找到最大和最小的差(不算0)，若刚好差为数组的长度，则继续，否则错误。然后判断有没有重复的数字。 */
class Solution {
public:
	bool IsRepeat(vector<int> vec)
	{
		for (int i = 0; i < vec.size() - 1; i++)
		{
			if (vec[i] == 0)
				continue;
			if (vec[i] == vec[i + 1])
				return false;
		}
		return true;
	}
	bool IsContinuous(vector<int> numbers)
	{
		if (numbers.empty())
			return false;
		sort(numbers.begin(), numbers.end());
		int diff = 0;
		int min = 0;
		int min_index = 0;
		int max = 0;
		for (min_index = 0; min_index < numbers.size(); min_index++)
			if (numbers[min_index] != 0)
			{
				min_index = min_index;
				min = numbers[min_index];
				break;
			}
		max = *(numbers.end() - 1);
		if ((max - min) != (numbers.size() - 1) && max != min)
			return  false;
		return IsRepeat(numbers);
	}
};
void question61()
{
	Solution s;
	vector<int> vec{ 1,2,3,5,0,0,7 };
	if (s.IsContinuous(vec))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}