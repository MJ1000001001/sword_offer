/* �������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ�� */

#include "question.h"
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};
#if 0
/* ����1���Ƚ���������ǰ���������һ�飬Ȼ�����жϵڶ��������Ƿ��ǵ�һ������������� */
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;
		vector<int> vec1;
		vector<int> vec2;
		pre_tree(pRoot1, vec1);
		pre_tree(pRoot2, vec2);
		int j = 0;
		for (int i = 0; i < vec1.size(); i++)
		{
			if (vec1[i] == vec2[0])
			{
				for (j = 0; j < vec2.size(); j++)
				{
					if (vec1[i + j] != vec2[j])
						break;
				}
				if (j == vec2.size())
					return true;
			}
		}
		return false;
	}
	void pre_tree(TreeNode *Root, vector<int> &vec)
	{
		if (Root == NULL)
			return;
		vec.push_back(Root->val);
		pre_tree(Root->left, vec);
		pre_tree(Root->right, vec);
	}
};
#endif
/* ����2�����õݹ飬�ж���2�ĸ��ڵ��Ƿ������1��ǰ�ڵ㣬��������ж��Ƿ���һ����*/
class Solution {
public:
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL)
			return false;
		if (is_subtree(pRoot1, pRoot2))
			return true;
		if (HasSubtree(pRoot1->left, pRoot2))
			return true;
		if (HasSubtree(pRoot1->right, pRoot2))
			return true;
		return false;
	}
	bool is_subtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot2 == NULL)
			return true;
		if (pRoot1 == NULL || pRoot1->val != pRoot2->val)
			return false;
		return is_subtree(pRoot1->left, pRoot2->left) && is_subtree(pRoot1->right, pRoot2->right);
	}
};
void question26()
{
	Solution s;

	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	node1.left = &node2;
	node1.right = &node3;
	node2.left = &node4;

	/*
				1
			 2      3
		   4

	*/

	TreeNode temp_node1(2);
	TreeNode temp_node2(2);
	temp_node1.left = &temp_node2;

	if (s.HasSubtree(&node1, &temp_node1))
		cout << " OK " << endl;
	else
		cout << " NG " << endl;
}