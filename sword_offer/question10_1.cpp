/*一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。*/
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