#include <iostream>

using namespace std;

int main ()
{
    int iSum = 0;
    int iMin = 1000;
    
    for (int i = 0; i < 7; ++i)
    {
        int iInput = 0;
        cin >> iInput;
        if (iInput % 2 == 1)
        {
            if (iMin > iInput)
                iMin = iInput;
            iSum += iInput;
        }
    }
    
    if (iSum == 0)
        cout << "-1";
    else 
    {
        cout << iSum << endl;
        cout << iMin;
    }
    
    return 0;
    
    
}