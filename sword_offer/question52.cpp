/*�������������ҳ����ǵĵ�һ��������㡣 */

#include "question.h"

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

/* ��ջ�����еĽڵ㶼�����������Ϳ��Դ�β��ͷ������ */
class Solution {
public:
	ListNode * FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		if (pHead1 == NULL || pHead2 == NULL)
			return NULL;
		stack<ListNode *> s1;
		stack<ListNode *> s2;
		ListNode *temp1 = pHead1;
		ListNode *temp2 = pHead2;
		ListNode *ret = NULL;
		while (temp1 != NULL)
		{
			s1.push(temp1);
			temp1 = temp1->next;
		}
		while (temp2 != NULL)
		{
			s2.push(temp2);
			temp2 = temp2->next;
		}
		while (!s1.empty() && !s2.empty())
		{
			temp1 = s1.top();
			temp2 = s2.top();
			if (temp1 == temp2)
				ret = temp1;
			else
				break;
			s1.pop();
			s2.pop();
		}
		return ret;
	}
};

void question52()
{
	Solution s;
	ListNode l1(0);
	ListNode l2(1);
	ListNode l3(2);
	ListNode l4(3);
	ListNode l5(4);
	ListNode l6(5);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l5;
	l4.next = &l5;
	l5.next = &l6;
	cout << s.FindFirstCommonNode(&l1, &l4)->val << endl;
}