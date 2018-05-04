/*把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
*/
#include "question.h"

using namespace std;

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
		{
			return 0;
		}
		int l = 0;
		int r = rotateArray.size() - 1;
		int m = 0;
		/* 用二分的思想 */
		/* 这样的旋转数组肯定是不旋转之前的数组首值最小，而旋转之后从中间分开，前后两端必然有一段是正常有序而另一段是旋转的。
		*  而最小值肯定在旋转的一段中*/
		/* 边界问题要注意下 */
		while (r > l + 1)
		{
			m = (l + r) / 2;
			/* 若位于数组中间的值大于数组首值的话，说明前半段是有序的，则最小值肯定在后半段中 */
			if (rotateArray[m] >= rotateArray[l])
				l = m;
			else
				r = m;
			cout << l <<"-" << r << endl;
		}
		return rotateArray[r];
	}
};
void question11()
{
	vector<int> vec = { 5,6,2,3,4};
	Solution s;
	cout << s.minNumberInRotateArray(vec) << endl;
}

