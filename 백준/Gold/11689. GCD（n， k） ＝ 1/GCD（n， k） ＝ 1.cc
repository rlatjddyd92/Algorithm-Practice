#include <iostream>
#include <queue>

using namespace std;

long long Number = 0; // 해체해야 하는 수 
long long Answer = 0; // 정답 취합 

queue<long long> queuePart; // 소인수 목록 

long long Divide_Number(long long Number, long long Divide);
void Check_Answer();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Number;

	Answer = Number;

	Check_Answer();

	cout << Answer;

	return 0;
}

long long Divide_Number(long long Number, long long Divide)
{
	if (Number % Divide == 0)
		Answer -= Answer / Divide;

	while (Number % Divide == 0)
		Number /= Divide;

	return Number;
}

void Check_Answer()
{
	Number = Divide_Number(Number, 2);
	Number = Divide_Number(Number, 3);

	long long Divide = 5;

	do
	{
		Number = Divide_Number(Number, Divide);
		Divide += 2;
		Number = Divide_Number(Number, Divide);
		Divide += 4;
	} while (Divide * Divide <= Number);

	if (Number > 1) // 마지막 소수 처리 
		Answer -= Answer / Number;
}
