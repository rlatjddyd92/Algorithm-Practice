#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<long long> vecSqure; // 2^N - 1 까지의 1의 개수를 [N]에 저장, N개의 자리수를 가지는 수들의 1의 개수 합 N:1 -> 자리수 1개인 숫자들까지 합 
pair<long long, long long> Numbers;

void MakeSqure();
long long CountOne(long long iNum);

/* 
2^0 - 1 : 0 : 0
2^1 - 1 : 1 : 1
2^2 - 1 : 3 : 4 (2^1 + [2^1 - 1]*2)
2^3 - 1 : 7 : 12 (2^2 + [2^2 - 1]*2)







*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Numbers.first >> Numbers.second;
	
	MakeSqure();

	cout << CountOne(Numbers.second) - CountOne(Numbers.first - 1);

	vecSqure.clear();

	return 0;
}

void MakeSqure()
{
	long long Limit = 1;
	long long Power = 10;
	
	for (long long i = 0; i < 18; ++i)
		Limit *= Power;

	vecSqure.push_back(0);
	long long llPower = 1;

	do
	{
		long long iNow = vecSqure.size(); // 현재 확인하려는 자릿수 
		long long llNew = llPower + (vecSqure[iNow - 1] * 2); // (2^(N-1) + [2^(N-1) - 1]*2)
		vecSqure.push_back(llNew);
		llPower *= 2;
	} while (vecSqure.back() <= Limit);
}

long long CountOne(long long iNum)
{
	stack<bool> stackOne;
	long long llReturn = 0;
	long long llNum = iNum;
	
	while (llNum > 0)
	{
		stackOne.push(llNum % 2);
		llNum /= 2;
	}

	while (stackOne.empty() == false)
	{
		if (stackOne.top() == 1)
		{
			llReturn += vecSqure[stackOne.size() - 1];

			long long llDiff = 1;

			for (long long i = 0; i < stackOne.size() - 1; ++i)
				llDiff *= 2;

			iNum -= llDiff;
			llReturn += iNum + 1;
		}
		stackOne.pop();
	}

	return llReturn;
}
