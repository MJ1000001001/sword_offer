/* ����һ����������������һ������S���������в������������ǵ����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�*/

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