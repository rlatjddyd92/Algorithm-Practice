#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long> queueMin;
priority_queue<long long> queueMin_Delete;

priority_queue<long long> queueMax;
priority_queue<long long> queueMax_Delete;

void DeleteNumber(long long iInput);
void PushNumber(long long iInput);



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long iCase = 0;

	cin >> iCase;

	for (long long i = 0; i < iCase; ++i)
	{
		long long iCommand = 0;
		cin >> iCommand;

		for (long long j = 0; j < iCommand; ++j)
		{
			char szInput = {};
			long long iInput = 0;

			cin >> szInput >> iInput;

			if (szInput == 'I')
				PushNumber(iInput);
			else 
				DeleteNumber(iInput);
		}

		while (queueMin.empty() == false)
		{
			if ((queueMin_Delete.empty() == false) && (queueMin.top() == queueMin_Delete.top()))
			{
				queueMin.pop();
				queueMin_Delete.pop();
			}
			else
				break;
		}

		while (queueMax.empty() == false)
		{
			if ((queueMax_Delete.empty() == false) && (queueMax.top() == queueMax_Delete.top()))
			{
				queueMax.pop();
				queueMax_Delete.pop();
			}
			else
				break;
		}

		if (queueMin.empty() == true)
			cout << "EMPTY" << "\n";
		else
			cout << queueMax.top() << " " << -queueMin.top() << "\n";

		while (queueMin.empty() == false) queueMin.pop();
		while (queueMin_Delete.empty() == false) queueMin_Delete.pop();
		while (queueMax.empty() == false) queueMax.pop();
		while (queueMax_Delete.empty() == false) queueMax_Delete.pop();
	}

	return 0;
}

void DeleteNumber(long long iInput)
{
	if (iInput == -1)
	{
		while (queueMin.empty() == false)
		{
			long long iNow = queueMin.top();
			queueMin.pop();

			if ((queueMin_Delete.empty() == false) && (queueMin_Delete.top() == iNow))
				queueMin_Delete.pop();
			else
			{
				queueMax_Delete.push(-iNow);
				break;
			}
		}
	}
	else 
	{
		while (queueMax.empty() == false)
		{
			long long iNow = queueMax.top();
			queueMax.pop();

			if ((queueMax_Delete.empty() == false) && (queueMax_Delete.top() == iNow))
				queueMax_Delete.pop();
			else
			{
				queueMin_Delete.push(-iNow);
				break;
			}	
		}
	}
}

void PushNumber(long long iInput)
{
	queueMin.push(-iInput);
	queueMax.push(iInput);
}
