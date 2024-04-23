#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

bool Find_EmptyNum(vector<int*>* vecAnswer, int* iRow, int* iCol);
bool Input_Num(vector<vector<bool>>* vecRow, vector<vector<bool>>* vecCol, vector<vector<bool>>* vecSqure, vector<int*>* vecAnswer, int iRow, int iCol);
void Write_Num(vector<bool>::iterator vecRow, vector<bool>::iterator vecCol, vector<bool>::iterator vecSqure, int* vecAnswer, int iNum, int iCol);
void Erase_Num(vector<bool>::iterator vecRow, vector<bool>::iterator vecCol, vector<bool>::iterator vecSqure, int* vecAnswer, int iNum, int iCol);

int main()
{
	vector<vector<bool>> vecRow;  // [행][숫자] -> 존재여부 
	vector<vector<bool>> vecCol;  // [열][숫자] -> 존재여부 
	vector<vector<bool>> vecSqure;  // [((행/3)*3) + (열/3)][숫자] -> 존재여부 
	vector<int*> vecAnswer;  // [행][순서] -> 해당 순서에 올 숫자 
	
	vecRow.resize(9);
	vecCol.resize(9);
	vecSqure.resize(9);
	vecAnswer.resize(9);

	for (int i = 0; i < 9; ++i)
	{
		vecRow[i].resize(10);
		vecCol[i].resize(10);
		vecSqure[i].resize(10);
		vecAnswer[i] = new int[9];
	}

	for (int i = 0; i < 9; ++i)
	{
		int iInput = 0;
		cin >> iInput;

		for (int j = 8; j >= 0; --j)
		{
			int iNum = iInput / int(pow(10, j));

			vecAnswer[i][(8 - j)] = iNum;
			
			if (iNum)
			{
				vecRow[i][iNum] = true;
				vecCol[(8 - j)][iNum] = true;
				vecSqure[((i / 3) * 3) + ((8 - j) / 3)][iNum] = true;
			}

			iInput %= int(pow(10, j));
		}
	}

	int iRow = 0;
	int iCol = 0;

	if (Find_EmptyNum(&vecAnswer, &iRow, &iCol))
		if (!Input_Num(&vecRow, &vecCol, &vecSqure, &vecAnswer, iRow, iCol))
			cout << "이상 발생" << endl;
		
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
			cout << vecAnswer[i][j];

		cout << endl;
	}
		
	for (int i = 0; i < 9; ++i)
	{
		vecRow[i].clear();
		vecCol[i].clear();
		vecSqure[i].clear();
		delete[]vecAnswer[i];
		vecAnswer[i] = nullptr;
	}

	vecRow.clear();
	vecCol.clear();
	vecSqure.clear();
	vecAnswer.clear();

	return 0;
}

bool Find_EmptyNum(vector<int*>* vecAnswer, int* iRow, int* iCol)
{
	for (vector<int*>::iterator iter = vecAnswer->begin(); iter != vecAnswer->end(); ++iter)
		for (int i = 0; i < 9; ++i)
			if (!(*iter)[i])
			{
				*iRow = int(iter - vecAnswer->begin());
				*iCol = i;
				return true;
			}

	return false;
}

bool Input_Num(vector<vector<bool>>* vecRow, vector<vector<bool>>* vecCol, vector<vector<bool>>* vecSqure, vector<int*>* vecAnswer, int iRow, int iCol)
{
	queue<int> queueNum;

	vector<bool>::iterator iterRow = (*(vecRow->begin() + iRow)).begin();
	vector<bool>::iterator iterCol = (*(vecCol->begin() + iCol)).begin();
	vector<bool>::iterator iterSqure = (*(vecSqure->begin() + ((iRow / 3) * 3) + (iCol / 3))).begin();
	int* iAnswer = *(vecAnswer->begin() + iRow);

	for (int i = 1; i < 10; ++i)
	{
		++iterRow;
		++iterCol;
		++iterSqure;

		if (!*iterRow)
			if (!*iterCol)
				if (!*iterSqure)
					queueNum.push(i);
	}

	iterRow = (*(vecRow->begin() + iRow)).begin();
	iterCol = (*(vecCol->begin() + iCol)).begin();
	iterSqure = (*(vecSqure->begin() + ((iRow / 3) * 3) + (iCol / 3))).begin();

	int iOriginRow = iRow;
	int iOriginCol = iCol;

	while (queueNum.size())
	{
		int iNum = queueNum.front();
		queueNum.pop();

		iterRow = (*(vecRow->begin() + iOriginRow)).begin();
		iterCol = (*(vecCol->begin() + iOriginCol)).begin();
		iterSqure = (*(vecSqure->begin() + ((iOriginRow / 3) * 3) + (iOriginCol / 3))).begin();

		Write_Num(iterRow, iterCol, iterSqure, iAnswer, iNum, iOriginCol);

		//cout << "(추가)[" << iOriginRow << "][" << iOriginCol << "][" << iNum << "]" << endl;

		if (Find_EmptyNum(vecAnswer, &iRow, &iCol))
		{
			if(Input_Num(vecRow, vecCol, vecSqure, vecAnswer, iRow, iCol))
				return true;
		}
		else
			return true;

		iterRow = (*(vecRow->begin() + iOriginRow)).begin();
		iterCol = (*(vecCol->begin() + iOriginCol)).begin();
		iterSqure = (*(vecSqure->begin() + ((iOriginRow / 3) * 3) + (iOriginCol / 3))).begin();

		Erase_Num(iterRow, iterCol, iterSqure, iAnswer, iNum, iOriginCol);

		//cout << "(삭제)[" << iOriginRow << "][" << iOriginCol << "][" << iNum << "]" << endl;
	}

	return false;
}

void Write_Num(vector<bool>::iterator vecRow, vector<bool>::iterator vecCol, vector<bool>::iterator vecSqure, int* vecAnswer, int iNum, int iCol)
{
	*(vecRow + iNum) = true;
	*(vecCol + iNum) = true;
	*(vecSqure + iNum) = true;
	*(vecAnswer + iCol) = iNum;
}

void Erase_Num(vector<bool>::iterator vecRow, vector<bool>::iterator vecCol, vector<bool>::iterator vecSqure, int* vecAnswer, int iNum, int iCol)
{
	*(vecRow + iNum) = false;
	*(vecCol + iNum) = false;
	*(vecSqure + iNum) = false;
	*(vecAnswer + iCol) = 0;
}


