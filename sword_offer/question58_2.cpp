/* ���磬��student. a am I������������ʶ������һ�ԭ���Ѿ��ӵ��ʵ�˳��ת�ˣ���ȷ�ľ���Ӧ���ǡ�I am a student.����Cat��һһ�ķ�ת��Щ����˳��ɲ����У����ܰ�����ô����*/

#include "question.h"

using namespace std;

class Solution {
public:
	string ReverseSentence(string str) 
	{
		reverse(str.begin(),str.end());
		int index_pre = 0;
		int index = 0;
		while (1)
		{
			index = str.find_first_of(' ',index_pre);
			if (index == -1)
			{
				reverse(str.begin() + index_pre, str.end());
				break;
			}
			reverse(str.begin() + index_pre, str.begin() + index);
			index_pre = index + 1;
		}
		return str;
	}
};
void question58_2()
{
	Solution s;
	cout << s.ReverseSentence("student. a am I") << endl;
}