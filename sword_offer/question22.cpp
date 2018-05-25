/*����һ����������������е�����k����㡣*/

/* ˼·2������������ָ�룬һ��ָ�������ߣ�����һ��ָ������k��֮�󣬵ڶ���ָ��͵�һ��ָ��ͬʱ��ǰ�ߡ���󷵻صڶ���ָ�� */
/* ���ڵ�������һ��ָ��ı�����������Ҫ��ʱ�����Կ����ö��ָ�룬���練ת�������������ָ�룬�ж��Ƿ��л�����������ָ�룬
    �ҵ�����k���ڵ����������ָ��*/
#include "question.h"
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		stack<ListNode *> sta;
		ListNode *temp_node = pListHead;
		if (k <= 0)
			return NULL;
		while (temp_node)
		{
			sta.push(temp_node);
			temp_node = temp_node->next;
		}
		if (k > sta.size())
			return NULL;
		while((--k > 0) && !sta.empty())
			sta.pop();
		return sta.top();
	}
};

void question22()
{
	Solution s;
	ListNode node1(1);
	ListNode node2(2);
	node1.next = &node2;
	ListNode node3(3);
	node2.next = &node3;
	ListNode node4(4);
	node3.next = &node4;
	ListNode node5(5);
	node4.next = &node5;
	ListNode node6(6);
	node5.next = &node6;
	ListNode node7(7);
	node6.next = &node7;
	//cout << s.FindKthToTail(&node3, -1)->val << endl;
	s.FindKthToTail(&node2, -1);
}