#include <iostream>
#include <queue>

using namespace std;

int main ()
{
int iArr = 0;
    int iNum = 0;
    cin >> iArr >> iNum;
    queue<int> queueAnswer;
    for (int i = 0; i < iArr; ++i)
    {
        int iInput = 0;
        cin >> iInput;
        if (iInput < iNum)
            queueAnswer.push(iInput);
}
    while (!queueAnswer.empty())
    {
        cout << queueAnswer.front() << " ";
        queueAnswer.pop();
    }
    
    return 0;
}