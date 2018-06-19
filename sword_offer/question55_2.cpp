/*输入一棵二叉树，判断该二叉树是否是平衡二叉树。。 */

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

/* 另一种方法可以将每个子树的深度记录下来，这样子每个节点就只算一次 */
class Solution {
public:
	int TreeDepth(TreeNode *pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int leftDepth = TreeDepth(pRoot->left) + 1;
		int rightDepth = TreeDepth(pRoot->right) + 1;
		return leftDepth > rightDepth ? leftDepth : rightDepth;
	}
	bool IsBalanced_Solution(TreeNode* pRoot) {
		if (pRoot == NULL)
			return true;
		int leftDepth = TreeDepth(pRoot->left) + 1;
		int rightDepth = TreeDepth(pRoot->right) + 1;
		if (leftDepth - rightDepth <= 1 && leftDepth - rightDepth >= -1)
			return true && IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
		return false;
	}
};

void question55_2()
{
	Solution s;
	TreeNode t1(1);
	TreeNode t2(2);
	TreeNode t3(3);
	TreeNode t4(4);
	TreeNode t5(5);
	TreeNode t6(6);
	t1.left = &t2;
	t1.right= &t3;
	t2.left = &t4;
	t2.right= &t5;
	t5.left = &t6;
	if (s.IsBalanced_Solution(&t1))
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}