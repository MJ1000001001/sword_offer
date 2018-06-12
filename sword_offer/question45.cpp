/*输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，则打印出这三个数字能排成的最小数字为321323。 */

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