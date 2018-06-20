/* �����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ���������������һ���������ַ�����S���������ѭ������Kλ���������������磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc�����ǲ��Ǻܼ򵥣�OK���㶨������*/

#include "question.h"

using namespace std;

#if 0
/* ֱ����stl��substr���в����ַ����ķ�ת */
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

/* ��ȫ����ĸ��תһ�Σ��ٲ��ַ�ת���ﵽĿ�� */
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