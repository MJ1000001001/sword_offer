/*����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С����������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��*/

#include "question.h"

using namespace std;

class Solution {
public:

	void _Perm(string str, vector<string> &res_vec, int index)
	{
		if (index >= str.length())
		{
			res_vec.push_back(str);
			return;
		}
		for (int i = index; i < str.length(); i++)
		{
			if (i != index && str[i] == str[index])
				continue;
			swap(str[i], str[index]);
			_Perm(str, res_vec, index + 1);
			swap(str[i], str[index]);
		}
	}
	vector<string> Permutation(string str) {
		vector<string> res_vec;
		if (str.length() == 0)
		{
			return res_vec;
		}
		_Perm(str, res_vec, 0);
		sort(res_vec.begin(), res_vec.end());
		return res_vec;
	}
};

void question38()
{
	Solution s;
	vector<string> vec = s.Permutation("abc");
	for (auto a : vec)
		cout << a << endl;
}