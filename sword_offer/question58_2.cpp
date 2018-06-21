/* 例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？。*/

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