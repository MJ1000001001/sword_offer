/*输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。*/

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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == NULL)
			return pHead2;
		if (pHead2 == NULL)
			return pHead1;
		ListNode *temp1 = pHead1;
		ListNode *temp2 = pHead2;
		ListNode *res;
		if (temp1->val <= temp2->val)
		{
			res = temp1;
			temp1 = temp1->next;
		}
		else
		{
			res = temp2;
			temp2 = temp2->next;
		}
		while (temp1 != NULL && temp2 != NULL)
		{
			if (temp1->val <= temp2->val)
			{
				res->next = temp1;
				res = res->next;
				temp1 = temp1->next;
			}
			else
			{
				res->next = temp2;
				res = res->next;
				temp2 = temp2->next;
			}
		}
		if (temp1 == NULL)
			res->next = temp2;
		else
			res->next = temp1;
		return (pHead1->val) <= (pHead2->val) ? pHead1 : pHead2;
	}
};

void question25()
{
	Solution s;
	ListNode node1(1);
	ListNode node2(3);
	node1.next = &node2;
	ListNode node3(5);
	node2.next = &node3;
	ListNode node5(1);
	ListNode node6(3);
	node5.next = &node6;
	ListNode node7(5);
	node6.next = &node7;
	ListNode *res = s.Merge(&node1, &node5);
	while (res != NULL)
	{
		cout << res->val << " ";
		res = res->next;
	}
}