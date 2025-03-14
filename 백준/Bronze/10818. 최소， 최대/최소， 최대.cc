#include <iostream>

using namespace std;

int main ()
{
    int iNum = 0;
    
    int iMax = -1000001;
    int iMin = 1000001;
    
    cin >> iNum;
    
    for (int i = 0; i <iNum; ++i)
    {
        int iInput = 0;
        cin >> iInput;
        
        if (iMax < iInput) 
            iMax = iInput;
        
        if (iMin > iInput)
            iMin = iInput;
    }
    
    cout << iMin << " " << iMax;
    
    return 0;
}