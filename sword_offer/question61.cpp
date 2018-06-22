/* ������\С �����Կ����κ�����,����A����1,JΪ11,QΪ12,KΪ13�������5���ƾͿ��Ա�ɡ�1,2,3,4,5��(��С���ֱ���2��4),��So Lucky!����*/

#include "question.h"

using namespace std;

/* �ҵ�������С�Ĳ�(����0)�����պò�Ϊ����ĳ��ȣ���������������Ȼ���ж���û���ظ������֡� */
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