#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        int iInput[2] = { 0,0 };
        cin >> iInput[0] >> iInput[1];

        if (cin.eof() == false)
            cout << iInput[0] + iInput[1] << "\n";
        else
            break;
    }

    return 0;
}