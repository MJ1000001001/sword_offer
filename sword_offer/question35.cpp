#include "question.h"

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
/* 用数组保存复制出来的空间，时间复杂度为O(n^2) */
/*
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;
		RandomListNode *temp = pHead;
		vector<RandomListNode *> vec1;
		vector<RandomListNode *> vec2;
		RandomListNode *res = NULL;
		RandomListNode *pre_res = NULL;


		res = new RandomListNode(temp->label);
		pre_res = res;
		vec1.push_back(temp);
		vec2.push_back(res);
		temp = temp->next;

		while (temp != NULL)
		{
			res = new RandomListNode(temp->label);
			vec1.push_back(temp);
			vec2.push_back(res);
			temp = temp->next;
			pre_res->next = res;
			pre_res = res;
		}
		temp = pHead;
		int j = 0;
		while (temp != NULL && j < vec2.size())
		{
			for (int i = 0; i < vec1.size(); i++)
			{
				if (vec1[i] == temp->random)
				{
					vec2[j]->random = vec2[i];
					break;
				}
			}
			j++;
			temp = temp->next;
		}
		return vec2[0];
	}
};
*/

/* 用map保存随机指针，时间复杂度为O(n) */
class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		if (pHead == NULL)
			return NULL;

		RandomListNode *temp = pHead;
		RandomListNode *temp_res = NULL;
		RandomListNode *pre_res = NULL;

		unordered_map<RandomListNode *, RandomListNode *>  my_map;

		temp_res = new RandomListNode(temp->label);
		pre_res = temp_res;
		my_map.insert(pair<RandomListNode *,RandomListNode *> (temp,temp_res));
		temp = temp->next;

		RandomListNode *res = temp_res;

		while (temp != NULL)
		{
			temp_res = new RandomListNode(temp->label);
			my_map.insert(pair<RandomListNode *, RandomListNode *>(temp, temp_res));
			temp = temp->next;
			pre_res->next = temp_res;
			pre_res = temp_res;
		}
		temp = pHead;
		temp_res = res;
		int j = 0;
		while (temp != NULL)
		{
			if (temp->random == NULL)
				temp_res->random = NULL;
			else
				temp_res->random = my_map.at(temp->random);
			temp_res = temp_res->next;
			temp = temp->next;
		}
		return res;
	}
};

void question35()
{
	Solution s;

	RandomListNode node1(1);
	RandomListNode node2(2);
	node1.next = &node2;
	RandomListNode node3(3);
	node2.next = &node3;
	RandomListNode node4(4);
	node3.next = &node4;
	RandomListNode node5(5);
	node4.next = &node5;
	RandomListNode node6(6);
	node5.next = &node6;
	RandomListNode node7(7);
	node6.next = &node7;

	node1.random = &node3;
	node2.random = &node1;
	node3.random = &node5;
	node4.random = NULL;
	node5.random = &node5;
	node6.random = &node1;
	node7.random = &node6;

	RandomListNode * res = s.Clone(&node1);
	for (int i = 0; i < 7; i++)
	{
		cout << res->label << " ";
		res = res->random;
	}
}