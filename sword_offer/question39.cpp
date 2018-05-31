/*��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0��*/

#include "question.h"

using namespace std;

#if 0
/* �ⷨ1:��һ���������齫���������е����ֳ��ֵĴ���������������Ȼ���ж��Ƿ��з��������ġ� */
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

/* �ⷨ2:��ΪҪ�ҳ����������������������е���֮�͡����Կ��Դӵ�һ������ʼ����������ǽ�������������һ���ģ���+1������-1.������Ϊ0.���޸ļ������� */
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