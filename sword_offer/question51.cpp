/*�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ������,�����������е�����Ե�����P������P��1000000007ȡģ�Ľ������� �����P%1000000007 */

/* ����һ���ȶ�����Ĺ��̣�ð��Ҳ���ԣ�����ʱ�临�Ӷȹ��ߡ��������˹鲢����
   �鲢������ߵ�ʱ�临�Ӷ���O(nlgn)��
   һ��Ҫ���Ǻ�ÿ�μӶ���*/

#include "question.h"

using namespace std;

#if 0
class Solution {
public:
	int InversePairs(vector<int> data) {
		int temp = 0;
		int ret = 0;
		for (int i = 0; i < data.size(); i++)
		{
			for (int j = i + 1; j < data.size(); j++)
			{
				if (data[i] > data[j])
				{
					temp = data[i];
					data[i] = data[j];
					data[j] = temp;
					ret++;
				}
			}
		}
		return ret% 1000000007;
	}
};
#endif

class Solution {
public:
	int ret;
	void my_merge(vector<int> &data, int l, int m, int r)
	{
		int temp_l = l;
		int temp_m = m;
		int temp_r = r;
		vector<int> temp_data;
		while (temp_l < m && temp_m < r)
		{
			if (data[temp_l] > data[temp_m])
			{
				temp_data.push_back(data[temp_m++]);
				ret += m - temp_l;
				ret = ret % 1000000007;
			}
			else
				temp_data.push_back(data[temp_l++]);
		}
		if (temp_m == r)
			while (temp_l < m)
				temp_data.push_back(data[temp_l++]);
		else
			while (temp_m < r)
				temp_data.push_back(data[temp_m++]);
		for (auto a : temp_data)
			data[l++] = a;
	}
	void merge_sort(vector<int> &data, int l, int r)
	{
		if (l < r - 1)
		{
			int m = (l + r) / 2;
			merge_sort(data, l, m);
			merge_sort(data, m, r);
			my_merge(data, l, m, r);
		}
	}
	int InversePairs(vector<int> data)
	{
		ret = 0;
		merge_sort(data,0,data.size());
		for (auto a : data)
			cout << a << " ";
		cout << endl;
		return ret % 1000000007;
	}
};

void question51()
{
	Solution s;
	vector<int> data = { 1,2,3,4,5,6,7,0 };
	cout << s.InversePairs(data) << endl;
}