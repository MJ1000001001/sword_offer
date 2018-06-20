/* 汇编语言中有一种移位指令叫做循环左移（ROL），现在有个简单的任务，就是用字符串模拟这个指令的运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。是不是很简单？OK，搞定它！。*/

#include "question.h"

using namespace std;

#if 0
/* 直接用stl的substr进行部分字符串的翻转 */
class Solution {
public:
	string LeftRotateString(string str, int n) 
	{
		string ret;
		if (str.empty() || n < 0 || n > str.size())
			return ret;
		string temp1 = str.substr(0, n);
		string temp2 = str.substr(n, str.size());
		ret = temp2 + temp1;
		return ret;
	}
};
#endif

/* 先全部字母翻转一次，再部分翻转，达到目的 */
class Solution {
public:
	string LeftRotateString(string str, int n)
	{
		string ret;
		if (str.empty() || n < 0 || n > str.size())
			return ret;
		reverse(str.begin(),str.end());
		reverse(str.begin(), str.begin() + str.size() - n);
		reverse(str.begin() + str.size() - n, str.end());
		return str;
	}
};

void question58()
{
	Solution s;
	cout << s.LeftRotateString("abcdefghijklmn", 7) << endl;
}