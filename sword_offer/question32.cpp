/*从上往下打印出二叉树的每个节点，同层节点从左至右打印。*/
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

template<class T>
class display
{
public:
	void operator()(const T &temp)
	{
		cout << temp << " ";
	}
};

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) 
	{
		queue<TreeNode *> q;
		vector<int> res;
		if (root == NULL)
			return res;
		q.push(root);
		while (!q.empty())
		{
			res.push_back(q.front()->val);
			if (q.front()->left != NULL)
			{
				q.push(q.front()->left);
			}
			if (q.front()->right != NULL)
			{
				q.push(q.front()->right);
			}
			q.pop();
		}
		return res;
	}
};

void question32()
{
	TreeNode node1(1);
	TreeNode node2(2);
	TreeNode node3(3);
	TreeNode node4(4);
	TreeNode node5(5);
	TreeNode node6(6);
	TreeNode node7(7);
	TreeNode node8(8);
	TreeNode node9(9);
	
	node1.left = &node2;
	node1.right= &node3;
	node2.left = &node4;
	node2.right= &node5;
	node3.left = &node6;
	node3.right= &node7;
	node4.left = &node8;
	node4.right= &node9;

	/*
			1
		2		3
	  4   5   6    7
	8   9
	
	*/

	vector<int> res;
	Solution s;
	res = s.PrintFromTopToBottom(&node1);
	for_each(res.begin(),res.end(),display<int>());
	cout << endl;
}