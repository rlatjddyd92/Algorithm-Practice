#include <iostream>

using namespace std;

long long iNum = 0;

void Hanoi_Count(long long iNum);
void Hanoi_4(char szStart, char szViaA, char szViaB, char szEnd, long long iNow);
void Hanoi_3(char szStart, char szVia, char szEnd, long long iNow);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iNum;

	Hanoi_Count(iNum);
	Hanoi_4('A', 'B', 'C', 'D', iNum);

	return 0;
}

void Hanoi_Count(long long iNum)
{
	long long iReturn = 0;

	/*
	n == 1
	Hanoi_4 1회 -> 1번 이동 

	n==2 
	Hanoi_4 1회 -> 3번 이동 

	n == 3
	Hanoi_4 2회 3 + 1
	Hanoi_3 (1) = 1

	n == 4
	Hanoi_4 2회 3 + 3
	Hanoi_3 (2), Hanoi_3(1) = 3 + 1 = 4

	Hanoi_3 
	사용 횟수 = n

	1, 3, 7, 11

	((n + 1) * n) / 2 
	 -> 1 부터 N까지 합 

	Hanoi_4
	자체 이동 횟수 : (N / 2) * 3 + (N % 2) 

	Hanoi_3 이용 횟수 
	Hanoi_3(n-2) 이동 횟수 + Hanoi_3(n-4) 이동 횟수 

	*/

	// Hanoi_4 이동 횟수 

	iReturn = ((iNum / 2) * 3) + (iNum % 2);

	// Hanoi_3 이동 횟수 

	long long iCount = 0;
	long long iNow = 1;

	for (long long i = 0; i < iNum - 2; ++i)
	{
		iCount += iNow;
		if ( (i % 2) != (iNum % 2))
			iReturn += iCount;

		iNow *= 2;
	}



	cout << iReturn << "\n";
}

void Hanoi_4(char szStart, char szViaA, char szViaB, char szEnd, long long iNow)
{
	if (iNow > 2)
		Hanoi_3(szStart, szViaA, szViaB, iNow - 2); // n-1보다 작은 것을 모두 ViaB로

	if (iNow > 1)
		cout << szStart << " " << szViaA << "\n"; // n-1을 ViaA로 

	cout << szStart << " " << szEnd << "\n"; // n을 End로 

	if (iNow > 1)
		cout << szViaA << " " << szEnd << "\n"; // n-1을 End로 

	if (iNow > 2)
		Hanoi_4(szViaB, szStart, szViaA, szEnd, iNow - 2); // N이 2보다 클 경우 나머지 처리하기 위해 함수 다시 실행 
}

void Hanoi_3(char szStart, char szVia, char szEnd, long long iNow)
{
	if (iNow > 1)
		Hanoi_3(szStart, szEnd, szVia, iNow - 1); // 전달 받은 n보다 작은 값을 szVia로, 도착지점과 버퍼 반대로 

	cout << szStart << " " << szEnd << "\n";

	if (iNow > 1)
		Hanoi_3(szVia, szStart, szEnd, iNow - 1); // 다시 n-1보다 작은 값들을 szStart로 보낸다 
}
