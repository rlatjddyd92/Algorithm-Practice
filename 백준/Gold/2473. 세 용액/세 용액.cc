#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<long long> vecLiqud;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iNum = 0;
	long long iAnswer[4] = { (4000000001),0,0,0 }; // 기록 , 숫자 0~2

	cin >> iNum;
	vecLiqud.resize(iNum);

	for (long long i = 0; i < iNum; ++i)
		cin >> vecLiqud[i];

	stable_sort(vecLiqud.begin(), vecLiqud.end(), [](long long iFirst, long long iSecond) {return iFirst < iSecond;});

	for (long long i = 0; i < iNum; ++i)
		for (long long j = 0; j < iNum; ++j)
		{
			if (i == j)
				continue;

			long long iNow = vecLiqud[i] + vecLiqud[j];
			long long iIndex[2] = { 0,0 };
			iIndex[0] = lower_bound(vecLiqud.begin(), vecLiqud.end(), -iNow) - vecLiqud.begin();
			iIndex[1] = iIndex[0] - 1;
			if ((iIndex[0] == i) || (iIndex[0] == j))
				++iIndex[0];
			if ((iIndex[0] == i) || (iIndex[0] == j))
				++iIndex[0];
			if ((iIndex[1] == i) || (iIndex[1] == j))
				--iIndex[1];
			if ((iIndex[1] == i) || (iIndex[1] == j))
				--iIndex[1];
			
			if (iIndex[0] < vecLiqud.size())
				if (abs(iAnswer[0]) > abs(iNow + vecLiqud[iIndex[0]]))
				{
					iAnswer[0] = iNow + vecLiqud[iIndex[0]];
					iAnswer[1] = i;
					iAnswer[2] = j;
					iAnswer[3] = iIndex[0];
				}
					
			if (iIndex[1] >= 0)
				if (abs(iAnswer[0]) > abs(iNow + vecLiqud[iIndex[1]]))
				{
					iAnswer[0] = iNow + vecLiqud[iIndex[1]];
					iAnswer[1] = i;
					iAnswer[2] = j;
					iAnswer[3] = iIndex[1];
				}
		}

	if (iAnswer[1] > iAnswer[2])
	{
		long long iBuffer = iAnswer[1];
		iAnswer[1] = iAnswer[2];
		iAnswer[1] = iBuffer;
	}

	if (iAnswer[2] > iAnswer[3])
	{
		long long iBuffer = iAnswer[2];
		iAnswer[2] = iAnswer[3];
		iAnswer[2] = iBuffer;
	}

	if (iAnswer[1] > iAnswer[2])
	{
		long long iBuffer = iAnswer[1];
		iAnswer[1] = iAnswer[2];
		iAnswer[1] = iBuffer;
	}


	cout << vecLiqud[iAnswer[1]] << " " << vecLiqud[iAnswer[2]] << " " << vecLiqud[iAnswer[3]];

	return 0;
}