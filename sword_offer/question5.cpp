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
		/* ���㵱ǰ�ַ����пո������ */
		for (int i = 0; str[i] != '\0'; i++)
		{
			old_length ++;
			if (str[i] == ' ')
			{
				space_count++;
			}
		}
		/* �����滻�ո����ַ������� */
		new_length = space_count * 2 + old_length;

		/* ����滻����ַ����̶����ڵ�ǰ������ڴ泤�ȣ���ֱ�ӷ��ء�Ҫ��Ȼ��Խ�� */
		if (new_length+1 > length)
		{
			return;
		}

		/* Ҫ�ǵ����ַ����������Ϊ��Ϊ\0�� */
		str[new_length] = '\0';
		/* i>j-----------����ǰλ�õ�ǰ��û�пո��ˣ��ǾͲ������滻�ˡ� */
		for (int i = new_length - 1, j = old_length - 1; i >= 0 && i > j;)
		{
			/* ����ǰ�ַ�Ϊ�ո����滻Ϊ%20. */
			if (str[j] == ' ')
			{
				str[i--] = '0';
				str[i--] = '2';
				str[i--] = '%';
				j--;
				continue;
			}
			/* ����ֱ�Ӹ�ֵ */
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