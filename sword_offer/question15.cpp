/*����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��*/
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