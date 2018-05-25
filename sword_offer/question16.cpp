/*����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���*/
#include "question.h"
using namespace std;

class Solution {
public:
	double Power(double base, int exponent) {
		double res = base;
		if (exponent == 0)
			return 1;
		if (exponent < 0)
		{
			exponent = -exponent;
			for (int i = 1; i < exponent; i++)
			{
				res *= base;
			}
			return 1.0 / res;
		}
		else
		{
			for (int i = 1; i < exponent; i++)
			{
				res *= base;
			}
		}
		return res;
	}
};

void question16()
{
	Solution s;
	int exponent = 0;
	cin >> exponent;
	double base = 1.2;
	cout << s.Power(base, exponent) << endl;
}