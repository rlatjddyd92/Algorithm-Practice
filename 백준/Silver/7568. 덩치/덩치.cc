#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> vecStudent;
	vector<int> vecUpper;

	int iNum = 0;

	cin >> iNum;

	vecStudent.resize(iNum);
	vecUpper.resize(iNum, 1);

	for (int i = 0; i < iNum; ++i)
	{
		cin >> vecStudent[i].first >> vecStudent[i].second;
	}

	for (int i = 0; i < iNum; ++i)
		for (int j = 0; j < iNum; ++j)
			if ((vecStudent[i].first < vecStudent[j].first) && (vecStudent[i].second < vecStudent[j].second))
				++vecUpper[i];

	for (int i = 0; i < iNum; ++i)
		cout << vecUpper[i] << " ";

	vecStudent.clear();
	vecUpper.clear();

	return 0;
}