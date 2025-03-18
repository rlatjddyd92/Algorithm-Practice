#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int iCount = 0;
    
    for (int i = 0; i < s.size(); ++i)
    {
        iCount += s[i] == '(' ? 1 : -1;
        if (iCount < 0)
            break;
    }
    
    if (iCount == 0)
        answer = true;
    else 
        answer = false;

    return answer;
}