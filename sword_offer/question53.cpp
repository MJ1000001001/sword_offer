/*统计一个数字在排序数组中出现的次数。 */

#include "question.h"

using namespace std;

#if 0
/* 最坏情况时间复杂度是O(N) */
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty())
			return 0;
		if (data[0] > k && data[data.size() - 1] < k)
			return 0;
		int l = 0;
		int r = data.size();
		int m = (l + r) / 2;
		int ret = 0;
		while (data[m] != k && m != r && m != l)
		{
			if (data[m] > k)
			{
				r = m;
				m = (l + r) / 2;
			}
			else
			{
				l = m;
				m = (l + r) / 2;
			}
		}
		int i = m;
		while (data[i] == k)
			i--;
		while (data[++i] == k)
			ret++;
		return ret;
	}
};
#endif

/* 利用二分查找找出第一个等于k的数 */
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k) {
		if (data.empty())
			return 0;
		if (data[0] > k && data[data.size() - 1] < k)
			return 0;
		int l = 0;
		int r = data.size();
		int m = (l + r) / 2;
		int ret = 0;
		int i = 0;
		while (m != r && m != l)
		{
			if (data[m] == k)
			{
				if (data[m - 1] != k)
				{
					i = m;
					break;
				}
				else
				{
					r = m;
					m = (l + r) / 2;
					continue;
				}
			}
			else if (data[m] > k)
			{
				r = m;
				m = (l + r) / 2;
				continue;
			}
			else
			{
				l = m;
				m = (l + r) / 2;
				continue;
			}
		}
		while (data[i++] == k)
			ret++;
		return ret;
	}
};


void question53()
{
	Solution s;
	vector<int> data = { 1,2,3,3,3,3,5,6 };
	cout << s.GetNumberOfK(data, 3) << endl;
}