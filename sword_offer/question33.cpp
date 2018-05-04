#include "question.h"

using namespace std;

class Solution {
public:
	int find_root(const vector<int> &vec,int root,int l,int r)
	{
		for (int i = l; i < r; i++)
			if (root < vec[i])
				return i;
		return r - 1;
	}

	bool verity_left(const vector<int> &vec,int l ,int r)
	{
		int root = vec.back();
		for (; l < r; l++)
			if (root < vec[l])
				return false;
		return true;
	}

	bool verity_right(const vector<int> &vec,int l ,int r)
	{
		int root = vec.back();
		for (; l < r; l++)
			if (root > vec[l])
				return false;
		return true;
	}

	bool _verifySquenceOfBST(const vector<int> &vec, int l, int r)
	{
		if (l < r)
		{
			int m = 0;
			int root = vec[r];
			/* 找到中序遍历时根节点应该在的位置 */
			m = find_root(vec,root,l,r);
			/* 验证左子树和右子树是不是二叉搜索树 */
			if (!verity_left(vec, l, m - 1) || !verity_right(vec, m, r-1))
				return false;
			/* 递归找子树 */
			if (!_verifySquenceOfBST(vec, l, m - 1) || !_verifySquenceOfBST(vec, m, r - 1))
				return false;
			return true;
		}
		return true;
	}
	bool VerifySquenceOfBST(vector<int> sequence) 
	{
		if (sequence.size() == 0)
			return false;
		return _verifySquenceOfBST(sequence, 0, sequence.size()-1);
	}
};

void question33()
{
	int N = 0;
	int temp = 0;
	cin >> N;
	vector<int> vec;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		vec.push_back(temp);
	}
	Solution s;
	if (s.VerifySquenceOfBST(vec))
		cout << "ok" << endl;
	else
		cout << "no" << endl;
}