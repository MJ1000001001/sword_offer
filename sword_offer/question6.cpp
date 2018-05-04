/* 输入一个链表，从尾到头打印链表每个节点的值。*/

#include "question.h"

using namespace std;

class ListNode
{
public:
	int value;
	ListNode *next_node;

	ListNode(int v)
	{
		value = v;
		next_node = NULL;
	}
};

void print_node(ListNode *HeadNode)
{
	ListNode *p;
	p = HeadNode;
	while (p != NULL)
	{
		cout << p->value << " ";
		p = p->next_node;
	}
	cout << endl;
}

#if 0
/* 用三个指针将链表反向指过来 */
void print_node_reversingly_modif(ListNode *HeadNode)
{
	ListNode *p1, *p2, *p3;
	if (HeadNode == NULL)
	{
		cout << "Temp List" << endl;
		return;
	}
	p1 = HeadNode;
	p2 = p1->next_node;
	if (p2 == NULL)
	{
		cout << p1->next_node << endl;
		return;
	}
	p3 = p2->next_node;
	while (p3 != NULL)
	{
		p2->next_node = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next_node;
	}
	p2->next_node = p1;
	HeadNode->next_node = NULL;
	print_node(p2);
}
#endif

void print_node_reversingly_modif(ListNode *HeadNode)
{
	ListNode *p1, *p2, *p3;
	if (HeadNode == NULL)
	{
		cout << "Empty List" << endl;
		return;
	}
	if(HeadNode->next_node == NULL)
	{
		cout << "only head node" << endl;
		return;
	}
	p1 = HeadNode;
	p2 = HeadNode->next_node;
	p3 = p2->next_node;
	p1->next_node = NULL;
	while (p3 != NULL)
	{
		ListNode *temp = p1;
		p2->next_node = p1;
		p1 = p2;
		p2 = p3;
		p3 = p3->next_node;
	}
	p2->next_node = p1;
	print_node(p2);
}

/* 先将所有value存入一个vector中，然后反向打印 */
void print_node_reversingly_vec(ListNode *HeadNode)
{
	ListNode *p;
	p = HeadNode;
	vector<int> vec;
	while (p != NULL)
	{
		vec.push_back(p->value);
		p = p->next_node;
	}
	reverse(vec.begin(),vec.end());
	for (auto end= vec.end() - 1; end != vec.begin(); end--)
	{
		cout << *end<< " ";
	}
	cout << *(vec.begin()) << " ";
	cout << endl;
	
}

/* 将所有的value存入栈中，然后出栈 */
void print_node_reversingly_stack(ListNode *HeadNode)
{
	ListNode *p;
	p = HeadNode;
	stack<ListNode> sta;
	while (p != NULL)
	{
		sta.push(*p);
		p = p->next_node;
	}
	int sta_size = sta.size();
	for (int i = 0;i < sta_size; i++)
	{
		cout << sta.top().value<< " ";
		sta.pop();
	}
	cout << endl;
}

void question6()
{
	ListNode* p0 = new ListNode(0);
	ListNode* p1 = new ListNode(1);
	p0->next_node = p1;
	ListNode* p2 = new ListNode(2);
	p1->next_node = p2;
	ListNode* p3 = new ListNode(3);
	p2->next_node = p3;
	ListNode* p4 = new ListNode(4);
	p3->next_node = p4;
	ListNode* p5 = new ListNode(5);
	p4->next_node = p5;
	ListNode* p6 = new ListNode(6);
	p5->next_node = p6;
	ListNode* p7 = new ListNode(7);
	p6->next_node = p7;
	ListNode* p8 = new ListNode(8);
	p7->next_node = p8;
	ListNode* p9 = new ListNode(9);
	p8->next_node = p9;
	ListNode* p10 = new ListNode(10);
	p9->next_node = p10;
	p10->next_node = NULL;

	print_node_reversingly_vec(p0);
	print_node_reversingly_stack(p0);
	print_node(p0);
	print_node_reversingly_modif(p0);
}




