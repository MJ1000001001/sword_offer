/* 输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构） */

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
/* 方法1：先将两个树用前序遍历遍历一遍，然后再判断第二个数组是否是第一个数组的子数组 */
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
/* 方法2：利用递归，判断树2的根节点是否等于树1当前节点，如果是则判断是否是一个树*/
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