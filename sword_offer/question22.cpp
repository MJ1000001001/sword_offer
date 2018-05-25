/*输入一个链表，输出该链表中倒数第k个结点。*/

/* 思路2：可以用两个指针，一个指针正常走，当第一个指针走了k次之后，第二个指针和第一个指针同时往前走。最后返回第二个指针 */
/* 对于单链表，当一个指针的遍历不能满足要求时，可以考虑用多个指针，比如反转链表可以用三个指针，判断是否有环可以用两个指针，
    找倒数第k个节点可以用两个指针*/
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