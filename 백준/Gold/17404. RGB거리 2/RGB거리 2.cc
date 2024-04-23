#include <iostream>
#include <vector>

using namespace std;

enum class COLOR
{
	RED,
	GREEN,
	BLUE,
	END
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int>> vecPrice; // [행 넘버][색상] 
	vector<vector<int>> vecSum; // [현재 색상][마지막 색상]

	int iNum = 0;

	cin >> iNum;

	for (int i = 0; i < iNum; ++i)
	{
		vector<int> vecInput(3);
		cin >> vecInput[int(COLOR::RED)] >> vecInput[int(COLOR::GREEN)] >> vecInput[int(COLOR::BLUE)];
		vecPrice.push_back(vecInput);
	}

	int iLast = vecPrice.size() - 1;

	for (int i = 0; i < 3; ++i)
	{
		vector<int> vecInput(3);

		for (int j = 0; j < 3; ++j)
		{
			if (i == j)
				vecInput[j] = -1;
			else
				vecInput[j] = vecPrice[0][i] + vecPrice[iLast][j];
		}

		vecSum.push_back(vecInput);
	}

	/*
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			cout << "[" << vecSum[i][j] << "]";

	cout << endl;
	*/

	for (int i = 1; i < iLast; ++i) // 검사하는 열 (Price)
	{
		vector<vector<int>> vecInput(3);

		for (int j = 0; j < 3; ++j) // 현재 행의 색상 (Price)
		{
			vector<int> vecTemp(3);

			for (int k = 0; k < 3; ++k) // 마지막 행의 색상 (Sum)
			{
				int iMin = -1;

				for (int a = 0; a < 3; ++a) // 현재 행의 색상 (Sum)
				{
					if (j == a)
						continue;

					if (vecSum[a][k] == -1)
						continue;

					if (iMin == -1)
						iMin = vecSum[a][k];
					else if (iMin > vecSum[a][k])
						iMin = vecSum[a][k];
				}

				vecTemp[k] = vecPrice[i][j] + iMin;
			}

			vecInput[j] = vecTemp;
		}

		vecSum = vecInput;

		/*
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
				cout << "[" << vecSum[j][k] << "]";

		cout << endl;
		*/
	}


	int iAnswer = -1;

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
		{
			if (i == j)
				continue;

			if (iAnswer == -1)
				iAnswer = vecSum[i][j];
			else if (iAnswer > vecSum[i][j])
				iAnswer = vecSum[i][j];
		}

	cout << iAnswer;

	for (int i = 0; i <= iLast; ++i)
	{
		vecPrice[i].clear();

		if (i < 3)
			vecSum[i].clear();
	}

	vecPrice.clear();
	vecSum.clear();

	return 0;
}