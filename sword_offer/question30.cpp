/* 定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数。*/
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
	/*定义两个栈，一个数据栈，一个保存当前最小值的栈。*/
	/*最小栈顶元素为最小元素，如果有在此之前有次小，也会在之前保存在栈中。*/
	stack<int> data_stack, min_stack;
	void push(int value)
	{
		data_stack.push(value);
		if (min_stack.empty())
		{
			min_stack.push(value);
		}

		/*只有当新加入的值小于最小栈顶元素的时候才加入最小栈*/
		else if (min_stack.top() > value)
		{
			min_stack.push(value);
		}
	}
	void pop()
	{
		/* 只有当在数据栈中，将当前最小的值弹出的时候，才能将最小栈顶元素弹出 */
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

