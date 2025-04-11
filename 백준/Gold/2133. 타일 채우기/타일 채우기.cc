#include <iostream>
#include <vector>

using namespace std;

// 2*3 타일링 

/*
예시 n=8

[6]*[2] + [4]*[4] + [2]*[6] + 2

[4]*[4] 에서 뒤의 [4] 부분에 길이 4짜리 경우의 수(2개) 가 아닌 것이 들어가면 [6]*[2]에서 계산한 경우의 수와 겹친다 
뒤에 나오는 [2]*[6]도 마찬가지 

따라서 

[6]*[2] + [4]*2 + [2]*2 + 2


점화식 

[n-2]*[2] + [n-4]*2 + .... [2]*2 + 2

*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<long long> vecAnswer;
	vecAnswer.push_back(1);

	long long iNum = 0;

	cin >> iNum;

	for (long long i = 1; i <= iNum; ++i)
	{
		long long iAnswer = 0;

		if (i % 2 == 0)
			for (long long j = i - 2; j >= 0;)
			{
				iAnswer += vecAnswer[j] * (j == i - 2 ? 3 : 2);
				--j;
			}
			
		vecAnswer.push_back(iAnswer);
	}

	cout << vecAnswer.back();

	vecAnswer.clear();

	return 0;
}