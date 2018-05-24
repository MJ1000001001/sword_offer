/*我们可以用2 * 1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2 * 1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？*/
#include "question.h"
using namespace std;

class Solution {
public:
	int rectCover(int number) {
		if (number <= 0)
			return 0;
		if (number == 1)
			return 1;
		if (number == 2)
			return 2;
		return rectCover(number - 1) + rectCover(number - 2);
	}
};
void question10_3()
{
	Solution s;
	int n = 0;
	cin >> n;
	cout << s.rectCover(n) << endl;
}