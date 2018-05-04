/*������ջ��ʵ��һ�����У���ɶ��е�Push��Pop������ �����е�Ԫ��Ϊint���͡�*/
#include "question.h"

using namespace std;

class Solution
{
public:
	void push(int node) {
		/* ���ֻ����stack1 */
		stack1.push(node);
	}

	int pop() {
		/* ��stack2��Ϊ�գ���ֱ�Ӵ�stack2�е������� */
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
		/* ����ʱ���stack2Ϊ�գ���stack1�е�����һ��һ�����뵽stack2�У�ֱ��stack1Ϊ�ա� */
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