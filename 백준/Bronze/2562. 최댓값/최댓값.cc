#include <iostream>
using namespace std;
int main ()
{
    int iIndex = 0;
    int iMax = 0;
    
    for (int i = 1 ; i <= 9; ++i)
    {
        int iInput = 0;
        cin >> iInput;
        if (iInput > iMax)
        {
            iIndex = i;
            iMax = iInput;
        }
    }
    
    cout << iMax << "\n";
     cout << iIndex;
    
    return 0;
}