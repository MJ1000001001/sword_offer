/*输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
*假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，
*但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）
*/
#include "question.h"

using namespace std;

#if 0
template<class T>
int my_find(typename vector<T> ::iterator it1,typename vector<T> ::iterator it2, T value)
{
	int count = 0;
	for (; it1 != it2; it1++, count++)
	{
		if (value == *it1)
		{
			return count;
		}
	}
}

class Solution {
public:
	/* 找规律，如果输出序列中的数比后一个大2，则表示不能出栈 */
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		int size = pushV.size();
		vector<int> ::iterator locate1;
		vector<int> ::iterator locate2;
		int temp1 = 0;
		int temp2 = 0;
		if (size == 1)
		{
			temp1 = my_find(pushV.begin(), pushV.end(), popV[0]);
			if (temp1 == -1)
			{
				return false;
			}
		}
		for (int i = 0; i < size - 1; i++)
		{
			temp1 = my_find(pushV.begin(), pushV.end(), popV[i]);
			temp2 = my_find(pushV.begin(), pushV.end(), popV[i+1]);
			if (temp1 == -1 || temp2 == -1)
			{
				return false;
			}
			if ((temp1 - temp2) > 1)
			{
				return false;
			}
			/* 删除输入队列的弹出元素 */
			pushV.erase(pushV.begin()+temp1);
		}
		return true;
	}
};
#endif

class Solution {
public:
	/* 模拟进栈出栈操作 */
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		stack<int> temp;
		for (int i = 0,j = 0; i < pushV.size(); i++)
		{
			/* 进栈操作 */
			temp.push(pushV[i]);
			/* 出栈 */
			while (j < popV.size() && temp.top() == popV[j])
			{
				temp.pop();
				j++;
			}
		}
		/* 如果该操作为空，则可以通过 */
		return temp.empty();
	}
};

void question31()
{
	int N = 0;
	int temp = 0;
	cin >> N;
	vector<int> pushV;
	vector<int> popV;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		pushV.push_back(temp);
	}
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		popV.push_back(temp);
	}
	Solution s;
	if (s.IsPopOrder(pushV, popV))
	{
		cout << "ok" << endl;
	}
	else
		cout << "no" << endl;
}