/*大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。n<=39。*/
#include "question.h"

using namespace std;

class Solution {
public:
	int Fibonacci(int n) {
		if (n == 0)
		{
			return 0;
		}
		if(n == 1 || n == 2)
		{
			return 1;
		}
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
};

void question10()
{
	Solution s;
	int n = 0;
	cin >> n;
	cout << s.Fibonacci(n) << endl;
}