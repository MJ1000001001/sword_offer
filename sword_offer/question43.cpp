/*���1~13��������1���ֵĴ���,�����100~1300��������1���ֵĴ�����Ϊ�����ر�����һ��1~13�а���1��������1��10��11��12��13��˹�����6��,���Ƕ��ں�����������û���ˡ�ACMerϣ�����ǰ����,������������ձ黯,���Ժܿ���������Ǹ�����������1���ֵĴ�����) */

#include "question.h"

using namespace std;

class Solution {
public:
	int NumberOf1InDig(int n)
	{
		if (n <= 0)
			return 0;
		if (n == 1)
			return 1;
		if (n == 2)
			return 20;
		else
			return  pow(10,n-1)+ 10 * NumberOf1InDig(n - 1);
	}

	int NumberOf1Between1AndN_Solution(int n)
	{
		if (n <= 0)
			return 0;
		if (n < 9 && n>0)
			return 1;
		int count_of_1 = 0;
		int dig = 0;
		int temp = n;
		int top = n;
		while (1)
		{
			dig++;
			temp = temp / 10;
			if (temp == 0)
				break;
			top = temp;
		}
		count_of_1 = top * NumberOf1InDig(dig - 1);
		temp = pow(10, dig - 1);
		if (top > 1)
			count_of_1 += pow(10, dig - 1);
		if (top == 1)
			count_of_1 += n % temp + 1;
		count_of_1 += NumberOf1Between1AndN_Solution(n % temp);
		return count_of_1;
	}
};

void question43()
{
	Solution s;
	int input = 0;
	cin >> input;
	cout << s.NumberOf1Between1AndN_Solution(input);
	//cout << s.NumberOf1InDig(input);
}