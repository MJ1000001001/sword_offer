/*һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n���������������һ��n����̨���ܹ��ж�����������*/
#include "question.h"

using namespace std;

class Solution {
public:
	int jumpFloorII(int number) {
		if (number == 1)
			return 1;
		int i = 1;
		int sum = 1;
		for (; i < number; i++)
			sum += jumpFloorII(i);
		return sum;
	}
};
void question10_2()
{
	Solution s;
	int n = 0;
	cin >> n;
	cout << s.jumpFloorII(n) << endl;
}