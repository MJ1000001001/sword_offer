/*���ǿ�����2 * 1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�������n��2 * 1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����*/
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