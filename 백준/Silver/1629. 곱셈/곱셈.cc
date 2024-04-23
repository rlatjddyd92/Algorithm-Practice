#include <iostream>

using namespace std;

long long Power(long long A, long long B, long long C);

int main()
{
	long long llA = 0;
	long long llB = 0;
	long long llC = 0;
	long long llAnswer = 0;

	cin >> llA >> llB >> llC;

	llAnswer = Power(llA, llB, llC);

	cout << llAnswer;

	return 0;
}

long long Power(long long A, long long B, long long C)
{
	if (1 == B)
		return A % C;

	long long iTemp = Power(A, B / 2, C);

	if (0 == B % 2)
		return (iTemp * iTemp) % C;
	else
		return (iTemp * iTemp) % C * A % C;
}
