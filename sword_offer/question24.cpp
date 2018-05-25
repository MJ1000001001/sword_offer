/*输入一个链表，反转链表后，输出链表的所有元素。*/

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
	ListNode* ReverseList(ListNode* pHead) {
		ListNode *temp1;
		ListNode *temp2;
		ListNode *temp3;
		if (pHead == NULL)
			return NULL;
		if (pHead->next == NULL)
		{
			return pHead;
		}
		if (pHead->next->next == NULL)
		{
			temp2 = pHead->next;
			pHead->next->next = pHead;
			pHead->next = NULL;
			return temp2;
		}
		temp1 = pHead;
		temp2 = temp1->next;
		temp3 = temp2->next;
		temp1->next = NULL;
		while (temp3 != NULL)
		{
			temp2->next = temp1;
			temp1 = temp2;
			temp2 = temp3;
			temp3 = temp3->next;
		}
		temp2->next = temp1;
		return temp2;
	}
};

void question24()
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
	ListNode *res = s.ReverseList(&node1);
	while (res != NULL)
	{
		cout << res->val << " " ;
		res = res->next;
	}
}