#include "question.h"

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void _constructBT(TreeNode *root, vector<int> pre, vector<int> vin, int pre_l, int pre_r,int vin_l,int vin_r,int flag)
	{
		if (vin_r >= vin_l)
		{
			cout << "pre_l-pre_r: " << pre_l << "-" << pre_r << endl;
			cout << "vin_l-vin_r: " << vin_l << "-" << vin_r << endl;
			int m = find(vin.begin() + vin_l, vin.begin() + vin_r, pre[pre_l]) - vin.begin();
			TreeNode *node = new TreeNode(vin[m]);
			if (flag == 0)
				root->left = node;
			else
				root->right = node;
			cout << "m: " << m;
			cout << endl;
			/* 算出来中序数组中的根节点下标之后，计算前序数组中的根节点下标 是在中序数组中的相对位置+前序数组的起始下标 */
			/* 左子树 */
			_constructBT(node, pre, vin, pre_l + 1, pre_l + m + vin_l, vin_l, m - 1, 0);
			/* 右子树 */
			_constructBT(node, pre, vin, m - vin_l + pre_l +1, pre_r, m + 1, vin_r, 1);
		}
	}
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty())
		{
			return NULL;
		}
		TreeNode * root = new TreeNode(pre.front());
		int m = find(vin.begin(), vin.end(), pre.front()) - vin.begin();
		cout << "m: " << m;
		cout << endl;
		_constructBT(root, pre, vin, 1, m, 0, m - 1, 0);
		_constructBT(root, pre, vin, m + 1, pre.size() - 1, m + 1, pre.size() - 1, 1);
		return root;
	}
};

void printTree(TreeNode *root)
{
	cout << root->val << " ";
	/* 从左子树递归到叶子节点 */
	if (root->left != NULL)
	{
		printTree(root->left);
	}
	/* 从右子树递归到叶子节点 */
	if (root->right != NULL)
	{
		printTree(root->right);
	}
}

void question7()
{
	Solution s;
	vector<int> pre = { 1,2,4,7,3,5,6,8 };
	vector<int> vin = { 4,7,2,1,5,3,8,6 };
	TreeNode *root = s.reConstructBinaryTree(pre, vin);
	printTree(root);
	cout << endl;
}