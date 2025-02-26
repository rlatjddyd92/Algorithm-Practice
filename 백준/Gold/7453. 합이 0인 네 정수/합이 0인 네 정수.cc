#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> vecNum; 
vector<int> vecA;
vector<int> vecB;

int iNum = 0;
long long iAnswer = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iNum;

	vecNum.resize(4);

	for (int i = 0; i < 4; ++i)
		vecNum[i].resize(iNum);

	for (int i = 0; i < iNum; ++i)
		for (int j = 0; j < 4; ++j)
			cin >> vecNum[j][i];

	for (int i = 0; i < iNum; ++i)
		for (int j = 0; j < iNum; ++j)
		{
			vecA.push_back(vecNum[0][i] + vecNum[1][j]);
			vecB.push_back(-1 * (vecNum[0][i] + vecNum[1][j]));
		}
			
	sort(vecA.begin(), vecA.end(), [](int First, int Second) {return First < Second; });
	sort(vecB.begin(), vecB.end(), [](int First, int Second) {return First < Second; });

	for (int i = 0; i < iNum; ++i)
		for (int j = 0; j < iNum; ++j)
		{
			int iFindNum = (vecNum[2][i] + vecNum[3][j]) * -1;
			long long iIndexLower = lower_bound(vecA.begin(), vecA.end(), iFindNum) - vecA.begin();

			if ((iIndexLower >= (iNum * iNum)) || (vecA[iIndexLower] != iFindNum))
				continue;

			iFindNum = (vecNum[2][i] + vecNum[3][j]);
			long long iIndexUpper = lower_bound(vecB.begin(), vecB.end(), iFindNum) - vecB.begin();

			iIndexUpper = (iNum * iNum) - iIndexUpper;
			iAnswer += iIndexUpper - iIndexLower;
		}
		
	cout << iAnswer;
	
	for (auto& iter : vecNum)
		iter.clear();

	vecNum.clear();
	vecA.clear();

	return 0;
}
