#include "question.h"

using namespace std;

template<class T>
class display
{
public:
	void operator()(const T &temp)
	{
		cout << temp << " ";
	}
};

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
	void _FindPath(TreeNode *root, int expectNumber, vector<vector<int>> &res, vector<int> vec, int sum)
	{
		/* 调整路径和并将该节点加入数组中 */
		sum += root->val;
		vec.push_back(root->val);
		/* 如果是叶子节点，就判断路径和是否符合条件 */
		if (root->left == NULL && root->right == NULL)
		{
			if (sum == expectNumber)
				res.push_back(vec);
		}
		/* 从左子树递归到叶子节点 */
		if (root->left != NULL)
		{
			_FindPath(root->left, expectNumber, res, vec, sum);
		}
		/* 从右子树递归到叶子节点 */
		if (root->right != NULL)
		{
			_FindPath(root->right, expectNumber, res, vec, sum);
		}
	}
	vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
		int sum = 0;
		vector<vector<int>> res;
		vector<int> vec;

		if (root == NULL)
			return res;
		_FindPath(root, expectNumber, res, vec, sum);
		return res;
	}
};

void question34()
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
	node1.right = &node3;
	node2.left = &node4;
	node2.right = &node5;
#if 0
	node3.left = &node6;
	node3.right = &node7;
	node4.left = &node8;
	node4.right = &node9;
#endif

	vector<vector<int>> res;
	Solution s;
	res = s.FindPath(&node1, 22);
	for (auto a : res)
	{
		for (auto b : a)
		{
			cout << b << " ";
		}
		cout << endl;
	}
}