/* ÿ����һ��ͯ��,ţ�Ͷ���׼��һЩС����ȥ�����¶�Ժ��С����,����������ˡ�HF��Ϊţ�͵�����Ԫ��,��ȻҲ׼����һЩС��Ϸ������,�и���Ϸ��������:����,��С������Χ��һ����Ȧ��Ȼ��,�����ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,���Ҳ��ٻص�Ȧ��,��������һ��С���ѿ�ʼ,����0...m-1����....������ȥ....ֱ��ʣ�����һ��С����,���Բ��ñ���,�����õ�ţ������ġ�����̽���ϡ���ذ�(��������Ŷ!!^_^)��������������,�ĸ�С���ѻ�õ������Ʒ�أ�(ע��С���ѵı���Ǵ�0��n-1)��*/

#include "question.h"

using namespace std;

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0)
			return -1;
		list<int> list;
		for (int i = 0; i < n; i++)
			list.push_back(i);
		auto it = list.begin();
		auto temp_it = it;
		int count = m;
		while (list.size() > 1)
		{
			count = m;
			while (--count > 0)
			{
				it++;
				if (it == list.end())
					it = list.begin();
			}
			temp_it = it;
			temp_it++;
			if (temp_it == list.end())
				temp_it = list.begin();
			list.erase(it);
			it = temp_it;
		}
		return *list.begin();
	}
};

void question62()
{
	Solution s;
	int n, m;
	cin >> n;
	cin >> m;
	cout << s.LastRemaining_Solution(n, m) << endl;
}