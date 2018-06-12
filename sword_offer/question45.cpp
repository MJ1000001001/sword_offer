/*����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323�� */

#include "question.h"

using namespace std;

class mycmp
{
public:
	bool operator()(const string  &str1,const string &str2)
	{
		string s1 = str1 + str2;
		string s2 = str2 + str1;
		return s1 < s2;
	}
};
class Solution {
public:

	string PrintMinNumber(vector<int> numbers) 
	{
		vector<string> 	res; 
		for (auto a : numbers)
		{
			string temp_str = to_string(a);
			res.push_back(temp_str);
		}
		sort(res.begin(), res.end(), mycmp());
		string ret;
		for (auto a : res)
			ret += a;
		return ret;
	}
};

void question45()
{
	Solution s;
	vector<int> param{3,32,321};
	cout << s.PrintMinNumber(param) << endl;
}