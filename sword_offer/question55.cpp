/*����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ� */

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
/* ʹ��һ���µ����ݽṹ��������ÿ���ڵ����ȡ��ö��������й�ȱ���. */
struct mTreeNode
{
	struct TreeNode *node;
	int depth;
};

class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int dep = 1;
		TreeNode * pNode = pRoot;
		queue<mTreeNode> que;
		mTreeNode mnode;
		mTreeNode tempnode;
		mnode.node = pRoot;
		mnode.depth = 1;
		que.push(mnode);
		while (!que.empty())
		{
			mnode = que.front();
			pNode = mnode.node;
			que.pop();
			if (pNode->left != NULL)
			{
				tempnode.node = pNode->left;
				tempnode.depth = mnode.depth + 1;
				que.push(tempnode);
				if (dep < tempnode.depth)
					dep = tempnode.depth;
			}
			if (pNode->right != NULL)
			{
				tempnode.node = pNode->right;
				tempnode.depth = mnode.depth + 1;
				que.push(tempnode);
				if (dep < tempnode.depth)
					dep = tempnode.depth;
			}
		}
		return dep;
	}
};
#endif

/* ���õݹ� */
class Solution {
public:
	int TreeDepth(TreeNode* pRoot)
	{
		if (pRoot == NULL)
			return 0;
		int leftDepth = TreeDepth(pRoot->left) + 1;
		int rightDepth = TreeDepth(pRoot->right) + 1;
		return leftDepth > rightDepth ? leftDepth : rightDepth;
	}
};

void question55()
{
	Solution s;
	TreeNode t1(9);
	cout << s.TreeDepth(&t1) << endl;
}