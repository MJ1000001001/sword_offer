/*输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。*/
#include "question.h"
using namespace std;

class Solution {
public:
	int  NumberOf1(int n) {
		int count = 0;
		while (n)
		{
			n = n&(n - 1);
			count++;
		}
		return count;
		
	}
};
void question15()
{
	Solution s;
	int n = 0;
	cin >> n;
	cout << s.NumberOf1(n) << endl;
}