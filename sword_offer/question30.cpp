/* ����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��СԪ�ص�min������*/
#include "question.h"

using namespace std;
/*
class stack_blk
{
public:
	stack_blk(int v): pre(NULL),value(v) {};
	stack_blk *pre;
	int        value;
};

class Solution 
{
public:
	Solution() :end(NULL), count(0) {};
	stack_blk *end;
	size_t	  count;
	void push(int value)
	{
		stack_blk * blk = new stack_blk(value);
		blk->pre = end;
		end = blk;
		count++;
	}

	void pop()
	{
		if (end == NULL)
			return;
		stack_blk * temp = end->pre;
		delete(end);
		end = temp;
		count--;
	}

	int top()
	{
		if (end == NULL)
			return 0;
		return end->value;
	}

	int min()
	{
		int min = INT_MAX;
		stack_blk *index = end;
		while (index != NULL)
		{
			if (min > index->value)
			{
				min = index->value;
			}
			index = index->pre;
		}
		return min;
	}
};
*/

class Solution 
{
public :
	/*��������ջ��һ������ջ��һ�����浱ǰ��Сֵ��ջ��*/
	/*��Сջ��Ԫ��Ϊ��СԪ�أ�������ڴ�֮ǰ�д�С��Ҳ����֮ǰ������ջ�С�*/
	stack<int> data_stack, min_stack;
	void push(int value)
	{
		data_stack.push(value);
		if (min_stack.empty())
		{
			min_stack.push(value);
		}

		/*ֻ�е��¼����ֵС����Сջ��Ԫ�ص�ʱ��ż�����Сջ*/
		else if (min_stack.top() > value)
		{
			min_stack.push(value);
		}
	}
	void pop()
	{
		/* ֻ�е�������ջ�У�����ǰ��С��ֵ������ʱ�򣬲��ܽ���Сջ��Ԫ�ص��� */
		if (data_stack.top() == min_stack.top())
		{
			min_stack.pop();
		}
		data_stack.pop();
	}
	int top()
	{
		return data_stack.top();
	}
	int min()
	{
		return min_stack.top();
	}
};

void question30()
{
	Solution *s = new Solution();
	s->push(4);
	s->push(2);
	s->push(3);
	s->push(1);
	s->push(5);
	cout << s->min() << endl;
	return;

}

