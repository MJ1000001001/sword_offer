/*һֻ����һ�ο�������1��̨�ף�Ҳ��������2���������������һ��n����̨���ܹ��ж�����������*/
#include "question.h"

using namespace std;

class Solution {
public:
	int jumpFloor(int number) {
		if (number == 1)
			return 1;
		else if (number == 2)
			return 2;
		else
			return jumpFloor(number - 1) + jumpFloor(number - 2);
	}
}; 
void question10_1()
{
	Solution s;
	int n = 0;
	cin >> n;
	cout << s.jumpFloor(n) << endl;
}