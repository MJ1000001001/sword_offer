#include "question.h"

using namespace std;

class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row = 0, col = 0;
		row = array.size();
		col = (array.back()).size();

		int i = 0;
		int j = col-1;
		int temp = 0;

		while (1)
		{
			temp = array[i][j];
			if (i >= row || j < 0)
			{
				return false;
			}
			if (temp == target)
			{
				return true;
			}
			else if (temp > target)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
	}
};

void question4()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> array;
	vector<int> vec;
	int temp = 0;

	for (int i = 0; i < N; i++)
	{
		vec.clear();
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			vec.push_back(temp);
		}
		array.push_back(vec);
	}

	int  value = 0;
	cin >> value;
	Solution s;
	if (s.Find(value, array))
	{
		cout << "ok" << endl;
	}
	else
		cout << "no" << endl;

}