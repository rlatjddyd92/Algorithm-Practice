#include <iostream>

using namespace std;

int main ()
{
    int iInput[3] = {0,0,0};
    cin >> iInput[0] >> iInput[1] >>iInput[2];
    if (iInput[0] + iInput[1]  == iInput[2])
        cout << "correct!"<<"\n";
    else
        cout << "wrong!"<<"\n";
    return 0;
}