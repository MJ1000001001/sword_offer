/*把只包含因子2、3和5的数称作丑数（Ugly Number）。例如6、8都是丑数，但14不是，因为它包含因子7。 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。 */

#include "question.h"

using namespace std;

#if 0
/* 时间复杂度过高 */
class Solution {
public:
	bool is_uglynumber(int num)
	{
		if (num <= 0)
			return false;
		while (num != 1)
		{
			if (num % 2 == 0)
			{
				num = num / 2;
				continue;
			}
			else if(num % 3 ==0)
			{
				num = num / 3;
				continue;
			}
			else if (num % 5 == 0)
			{
				num = num / 5;
				continue;
			}
			else
				return false;
		}
		return true;
	}

	int GetUglyNumber_Solution(int index) 
	{
		if (index <= 0)
			return 0;
		int res = 0;
		int i = 1;
		while (index--)
			while (1)
				if (is_uglynumber(i++))
					break;
		return --i;

	}
};
#endif

/* 利用已知的丑数，推导出接下来的丑数 */
class Solution {
public:
	int GetUglyNumber_Solution(int index)
	{
		if (index <= 0)
			return 0;
		if (index == 1)
			return 1;
		vector<int> vec;
		vec.push_back(1);
		int index_2 = 0, index_3 = 0, index_5 = 0;
		int max_2 = 0, max_3 = 0, max_5 = 0;
		int temp_min = 0;
		while (vec.size() != index)
		{
			max_2 = 2 * vec[index_2];
			max_3 = 3 * vec[index_3];
			max_5 = 5 * vec[index_5];
			//temp_min = min(max_2, max_3, max_5);
			temp_min = min(max_2, max_3);
			temp_min = min(temp_min, max_5);
			if (max_2 == temp_min)
				index_2++;
			if (max_3 == temp_min)
				index_3++;
			if (max_5 == temp_min)
				index_5++;
			vec.push_back(temp_min);
		}
		cout << "a" << index_2;
		cout << "a" << index_3;
		cout << "a" << index_5;
		for (auto a : vec)
			cout << a << " ";
		cout << endl;
		return *(--vec.end());
	}
};
void question49()
{
	Solution s;
	int index;
	cin >> index;
	cout << s.GetUglyNumber_Solution(index) << endl;
}