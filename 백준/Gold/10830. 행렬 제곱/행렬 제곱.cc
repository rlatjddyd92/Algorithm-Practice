#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void Divide_PowNum(); // 제곱수 분해 
void Pow_Matrix(); // 분해된 제곱수에 따라 곱셈 함수 불러온다 
long long Modula_Func(int iRow, int iCol, int iNow, int iCommand);  // 2는 지금까지 곱한거 제곱하기, 1은 원래 행렬 곱하기 -> 1000 나머지 

const long long llModula = (long long)1000;
long long llPowNum = (long long)0;
long long llSize = (long long)0 ;
vector<vector<long long>> vecMatrix;
vector<vector<long long>> vecBuffer;
vector<vector<long long>> vecAnswer;
stack<long long> stackDivided_PowNum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> llSize >> llPowNum;

	vecMatrix.resize(llSize);
	vecAnswer.resize(llSize);
	vecBuffer.resize(llSize);

	for (auto& iter : vecMatrix)
		iter.resize(llSize);

	for (auto& iter : vecAnswer)
		iter.resize(llSize);

	for (auto& iter : vecBuffer)
		iter.resize(llSize);

	for (int i = 0; i < llSize; ++i)
		for (int j = 0; j < llSize; ++j)
		{
			cin >> vecMatrix[i][j];
			vecAnswer[i][j] = vecMatrix[i][j];
		}
			
	Divide_PowNum();
	Pow_Matrix();

	for (int i = 0; i < llSize; ++i)
	{
		for (int j = 0; j < llSize; ++j)
			cout << vecAnswer[i][j] << " ";

		cout << "\n";
	}
		
	for (auto& iter : vecMatrix)
		iter.clear();

	vecMatrix.clear();

	for (auto& iter : vecAnswer)
		iter.clear();

	vecAnswer.clear();

	for (auto& iter : vecBuffer)
		iter.clear();

	vecBuffer.clear();


	return 0;
}

void Divide_PowNum()
{
	while (llPowNum > 1)
	{
		if (llPowNum % 2 == 1)
		{
			--llPowNum;
			stackDivided_PowNum.push(1);
		}
		else
		{
			llPowNum /= 2;
			stackDivided_PowNum.push(2);
		}
	}
}

void Pow_Matrix()
{
	while (stackDivided_PowNum.empty() == false)
	{
		int iNow = stackDivided_PowNum.top();
		stackDivided_PowNum.pop();

		for (int i = 0; i < llSize; ++i)
			for (int j = 0; j < llSize; ++j)
			{
				vecBuffer[i][j] = 0;

				for (int k = 0; k < llSize; ++k)
					vecBuffer[i][j] += Modula_Func(i, j, k, iNow);

				vecBuffer[i][j] %= llModula;
			}

		for (int i = 0; i < llSize; ++i)
			for (int j = 0; j < llSize; ++j)
				vecAnswer[i][j] = vecBuffer[i][j];
	}

	for (int i = 0; i < llSize; ++i)
		for (int j = 0; j < llSize; ++j)
			vecAnswer[i][j] %= llModula;
}

long long Modula_Func(int iRow, int iCol, int iNow, int iCommand)
{
	if (iCommand == 1)
		return ((vecAnswer[iRow][iNow] % llModula) * (vecMatrix[iNow][iCol] % llModula)) % llModula;
	else 
		return ((vecAnswer[iRow][iNow] % llModula) * (vecAnswer[iNow][iCol] % llModula)) % llModula;
}

// 모듈러 공식 (a*b)%c == ((a%c) * (b%c)) % c