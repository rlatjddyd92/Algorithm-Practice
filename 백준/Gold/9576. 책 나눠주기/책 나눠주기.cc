#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iCase = 0;
	cin >> iCase;

	for (int k = 0; k < iCase; ++k)
	{
		int iBooks = 0;
		int iStudents = 0;

		vector<pair<int, int>> vecStudent;
		vector<bool> vecBooks;

		cin >> iBooks >> iStudents;

		vecStudent.resize(iStudents);
		vecBooks.resize(iBooks + 1, false);

		for (int i = 0; i < iStudents; ++i)
			cin >> vecStudent[i].first >> vecStudent[i].second;

		sort(vecStudent.begin(), vecStudent.end(), [](pair<int, int> Left, pair<int, int> Right)
			{
				if (Left.second < Right.second)
					return true;
				else if (Left.second > Right.second)
					return false;

				if (Right.first > Right.first)
					return true;
				else if (Right.first < Right.first)
					return false;

				return false;
			});

		int iAnswer = 0;

		for (int i = 0; i < iStudents; ++i)
		{
			for (int j = vecStudent[i].first; j <= vecStudent[i].second; ++j)
			{
				if (vecBooks[j] == false)
				{
					vecBooks[j] = true;
					++iAnswer;
					break;
				}
			}
		}

		vecStudent.clear();
		vecBooks.clear();

		cout << iAnswer << "\n";
	}

	

	return 0;
}