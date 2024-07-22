#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int iSensor = 0;
	int iOffice = 0;
	int iAnswer = 0;

	cin >> iSensor >> iOffice;

	priority_queue<int> queueSensor;

	for (int i = 0; i < iSensor; ++i)
	{
		int iInput = 0;
		cin >> iInput;
		queueSensor.push(iInput);
	}

	int iNow = queueSensor.top();
	queueSensor.pop();

	priority_queue<int> queueGap;

	while (!queueSensor.empty())
	{
		queueGap.push(iNow - queueSensor.top());
		iNow = queueSensor.top();
		queueSensor.pop();
	}

	while (!queueGap.empty())
	{
		--iOffice;
		if (iOffice <= 0)
			iAnswer += queueGap.top();

		queueGap.pop();
	}

	cout << iAnswer;

	return 0;
}