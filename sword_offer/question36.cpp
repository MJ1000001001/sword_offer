/*����һ�ö��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��*/

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

class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode *temp_node;
		if (pRootOfTree != NULL)
		{
			Convert(pRootOfTree->left);
			Convert(pRootOfTree->right);

			temp_node = pRootOfTree->left;
			if (temp_node != NULL)
			{
				while (temp_node->right != NULL)
					temp_node = temp_node->right;
				pRootOfTree->left = temp_node;
				temp_node->right = pRootOfTree;
			}

			temp_node = pRootOfTree->right;
			if (temp_node != NULL)
			{
				while (temp_node->left != NULL)
					temp_node = temp_node->left;
				pRootOfTree->right = temp_node;
				temp_node->left = pRootOfTree;
			}
		}
		temp_node = pRootOfTree;
		if (temp_node == NULL)
			return NULL;
		while (temp_node->left != NULL)
			temp_node = temp_node->left;
		return temp_node;
	}
};

void question36()
{
	TreeNode node1(10);
	TreeNode node2(5);
	TreeNode node3(12);
	TreeNode node4(4);
	TreeNode node5(7);
	TreeNode node6(6);
	TreeNode node7(7);
	TreeNode node8(8);
	TreeNode node9(9);

	node1.left = &node2;
	//node1.right = &node3;
	node2.left = &node4;
	//node2.right = &node5;
	node3.left = &node6;
	//node3.right = &node7;
	node4.left = &node8;
	//node4.right = &node9;
	/*
					10
			  5             12
		  4      7      6        7
	  8       9

	*/

	Solution s;
	TreeNode *node = s.Convert(&node1);
	while (node != NULL)
	{
		cout << node->val << " ";
		node = node->right;
	}
	cout << endl;
}