/*用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。*/
#include "question.h"

using namespace std;

class Solution
{
public:
	void push(int node) {
		/* 入队只能入stack1 */
		stack1.push(node);
	}

	int pop() {
		/* 若stack2不为空，则直接从stack2中弹出数据 */
		if (!stack2.empty())
		{
			int res = stack2.top();
			stack2.pop();
			return res;
		}
		if (stack1.empty())
		{
			return 0;
		}
		/* 出队时如果stack2为空，则将stack1中的数据一个一个弹入到stack2中，直到stack1为空。 */
		while(!stack1.empty())
		{ 
			stack2.push(stack1.top());
			stack1.pop();
		}
		int res = stack2.top();
		stack2.pop();
		return res;
	}
	void clear()
	{
		while(!stack1.empty())
		{ 
			stack1.pop();
		}
		while(!stack2.empty())
		{ 
			stack2.pop();
		}
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

void question8()
{
	Solution s;
	s.push(9);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
}