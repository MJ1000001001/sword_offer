/*HZż������Щרҵ������������Щ�Ǽ����רҵ��ͬѧ����������鿪����,���ַ�����:�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý��������,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)����᲻�ᱻ������ס��(�������ĳ���������1) */

#include "question.h"

using namespace std;

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array) {
		int max = INT_MIN;
		int sum = 0;
		for (int i = 0; i < array.size(); i++)
		{
			sum += array[i];
			if (max < sum)
				max = sum;
			if (sum <= 0)
				sum = 0;
		}
		return max;
	}
};

void question42()
{
	Solution s;
	vector<int> param{ 6,-3,-2,7,-15,1,2,2 };
	cout << s.FindGreatestSumOfSubArray(param);
}