#include "question.h"

using namespace std;

class Solution
{
public:
	void replaceSpace(char *str, int length)
	{
		int space_count = 0;
		int new_length = 0;
		int old_length = 0;
		/* 计算当前字符串中空格的数量 */
		for (int i = 0; str[i] != '\0'; i++)
		{
			old_length ++;
			if (str[i] == ' ')
			{
				space_count++;
			}
		}
		/* 计算替换空格后的字符串长度 */
		new_length = space_count * 2 + old_length;

		/* 如果替换后的字符串商都大于当前传入的内存长度，则直接返回。要不然会越界 */
		if (new_length+1 > length)
		{
			return;
		}

		/* 要记得新字符串中最后以为置为\0。 */
		str[new_length] = '\0';
		/* i>j-----------若当前位置的前面没有空格了，那就不用再替换了。 */
		for (int i = new_length - 1, j = old_length - 1; i >= 0 && i > j;)
		{
			/* 若当前字符为空格，则替换为%20. */
			if (str[j] == ' ')
			{
				str[i--] = '0';
				str[i--] = '2';
				str[i--] = '%';
				j--;
				continue;
			}
			/* 否则直接赋值 */
			str[i--] = str[j--];
		}
	}
};

void question5()
{
	char str[40] = "hello world ne i ";
	Solution s;
	s.replaceSpace(str, 40);
	cout << str << endl;
}