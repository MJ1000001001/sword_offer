/*��Ҷ�֪��쳲��������У�����Ҫ������һ������n���������쳲��������еĵ�n�n<=39��*/
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