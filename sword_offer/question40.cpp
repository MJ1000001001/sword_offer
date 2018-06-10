/*输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4。 */

#include "question.h"

using namespace std;

class mycmp
{
public:
	bool operator()(const int &a, const int &b)
	{
		return a < b;
	}
};

class Solution {
public:
	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		vector<int> res;
		priority_queue<int, vector<int>, mycmp> pq;
		//priority_queue<int> pq;
		if (input.empty() || k <= 0)
			return res;
		if (input.size() < k)
			return res;
		int i = 0;
		for (i = 0; i < input.size(); i++)
		{
			if (i < k)
			{
				pq.push(input[i]);
				continue;
			}
			if (input[i] < pq.top())
			{
				pq.pop();
				pq.push(input[i]);
			}
		}
		int a = 0;
		for (i = 0; i < k; i++)
		{
			a = pq.top();
			pq.pop();
			res.push_back(a);
		}
		return res;
	}
};

void question40()
{
	Solution s;
	vector<int> param{ 4,5,1,6,2,7,3,8 };
	vector<int> res;
	res = s.GetLeastNumbers_Solution(param, 0);
	for (auto a : res)
		cout << a << " ";
	cout << endl;
}