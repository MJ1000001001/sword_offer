/*���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
*����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4��5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У�
*��4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С���ע�⣺���������еĳ�������ȵģ�
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
	/* �ҹ��ɣ������������е����Ⱥ�һ����2�����ʾ���ܳ�ջ */
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
			/* ɾ��������еĵ���Ԫ�� */
			pushV.erase(pushV.begin()+temp1);
		}
		return true;
	}
};
#endif

class Solution {
public:
	/* ģ���ջ��ջ���� */
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		stack<int> temp;
		for (int i = 0,j = 0; i < pushV.size(); i++)
		{
			/* ��ջ���� */
			temp.push(pushV[i]);
			/* ��ջ */
			while (j < popV.size() && temp.top() == popV[j])
			{
				temp.pop();
				j++;
			}
		}
		/* ����ò���Ϊ�գ������ͨ�� */
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