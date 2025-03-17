#include <iostream>
#include <queue>

using namespace std;

priority_queue<string> queueType;
queue<long long> queueNumber;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long iCase = 0;

    cin >> iCase;

    for (long long i = 0; i < iCase; ++i)
    {
        long long iNumber = 0;
        long long llAnswer = (long long)0;

        cin >> iNumber;

        if (iNumber == 0)
        {
            cout << 0 << "\n";
            continue;
        }
            

        for (long long j = 0; j < iNumber; ++j)
        {
            string strName = {};
            string strType = {};
            cin >> strName >> strType;
            queueType.push(strType);
        }

        string strBefore = {};
        long long iTypeNum = 0;

        if (queueType.empty() == false)
        {
            strBefore = queueType.top();
            iTypeNum = 1;
            queueType.pop();
        }

        while (queueType.empty() == false)
        {
            if (strBefore == queueType.top())
            {
                ++iTypeNum;
            }
            else
            {
                strBefore = queueType.top();
                queueNumber.push(iTypeNum);
                iTypeNum = 1;
            }

            queueType.pop();
        }

        queueNumber.push(iTypeNum);

        if (queueNumber.empty() == false)
        {
            llAnswer = queueNumber.front() + 1;
            queueNumber.pop();
        }

        while (queueNumber.empty() == false)
        {
            llAnswer *= (queueNumber.front() + 1);
            queueNumber.pop();
        }
        cout << (llAnswer - 1) << "\n";
    }
    return 0;
}