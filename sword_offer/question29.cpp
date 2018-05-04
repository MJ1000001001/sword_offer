/* 操作给定的二叉树，将其变换为源二叉树的镜像。
* 二叉树的镜像定义：源二叉树 
*    	    8
*    	   /  \
*    	  6   10
*    	 / \  / \
*    	5  7 9 11
*    	镜像二叉树
*    	    8
*    	   /  \
*    	  10   6
*    	 / \  / \
*    	11 9 7  5
*/
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
	void printCircle(vector<vector<int>> &matrix, int &n, vector<int> &vec)
	{
		/*从左向右打印第一行*/
		int j = n;
		int i = n;
		for (; i < matrix[0].size() - n; i++)
		{
			vec.push_back(matrix[j][i]);
		}
		if (matrix.size() - 2 * n <= 1)
		{
			return;
		}
		/*从上向下打印最后一列*/
		j = matrix[0].size() - 1 - n;
		i = n + 1;
		for (; i < matrix.size() - n; i++)
		{
			vec.push_back(matrix[i][j]);
		}
		if (matrix[0].size() - 2 * n <= 1)
		{
			return;
		}
		/*从右向左打印最一行*/
		i = matrix[0].size() - 2 - n;
		j = matrix.size() - 1 - n;
		for (; i >= n; i--)
		{
			vec.push_back(matrix[j][i]);
		}
		if (matrix.size() - 2 * n <= 2 && matrix[0].size() - 2 * n <= 2)
		{
			return;
		}
		/*从下向上打印第一列*/
		i = n;
		j = matrix.size() - 2 - n;
		for (; j > n; j--)
		{
			vec.push_back(matrix[j][i]);
		}
		n++;
		if (2 * n >= matrix.size() || 2 * n >= matrix[0].size())
			return;
		printCircle(matrix, n, vec);
	}
	vector<int> printMatrix(vector<vector<int> > matrix) {
		vector<int> vec;
		int n = 0;
		printCircle(matrix, n, vec);
		return vec;
	}
};
int question29()
{
	Solution s;
	vector<vector<int>> vec;
	int temp;
	int M, N;
	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		vector<int> temp_vec;
		for (int j = 0; j < N; j++)
		{
			cin >> temp;
			temp_vec.push_back(temp);
		}
		vec.push_back(temp_vec);
	}
	for (auto a : s.printMatrix(vec))
	{
		cout << a << " ";
	}
	system("pause");
	return 0;
}