/*��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� ����һ���ǵݼ�����������һ����ת�������ת�������СԪ�ء� ��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��
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
		/* �ö��ֵ�˼�� */
		/* ��������ת����϶��ǲ���ת֮ǰ��������ֵ��С������ת֮����м�ֿ���ǰ�����˱�Ȼ��һ���������������һ������ת�ġ�
		*  ����Сֵ�϶�����ת��һ����*/
		/* �߽�����Ҫע���� */
		while (r > l + 1)
		{
			m = (l + r) / 2;
			/* ��λ�������м��ֵ����������ֵ�Ļ���˵��ǰ���������ģ�����Сֵ�϶��ں����� */
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

