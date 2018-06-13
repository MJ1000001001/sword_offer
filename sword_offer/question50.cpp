/*在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置。 */

#include "question.h"

using namespace std;

class Solution {
public:
	int FirstNotRepeatingChar(string str) {
		if (str.empty())
			return -1;
		map<char, int> mymap;
		//unordered_map<char, int, hash<signed char>> mymap;
		for (auto a : str)
			mymap[a]++;
		int i = 0;
		for (auto a : str)
		{
			if (mymap[a] == 1)
				return i;
			i++;
		}
		for (auto it = mymap.begin(); it != mymap.end(); it++)
			cout << (*it).first << ":" << (*it).second << endl;
		return 0;
	}
};

void question50()
{
	Solution s;
	//string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string str = "ninllnas";
	cout << s.FirstNotRepeatingChar(str) << endl;
}