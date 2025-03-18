#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iCase = 0;
    cin >> iCase;

    for (int i = 0; i < iCase; ++i)
    {
        int iInput[3] = { 0,0,0 };
        cin >> iInput[0] >> iInput[1] >> iInput[2];
        int iAnswer = (iInput[2] % iInput[0]) == 0 ? iInput[0] : (iInput[2] % iInput[0]);
        iAnswer *= 100;
        iAnswer += (iInput[2] / iInput[0]);
        iAnswer += (iInput[2] % iInput[0]) > 0 ? 1 : 0;
        cout << iAnswer << "\n";
    }

    return 0;
}