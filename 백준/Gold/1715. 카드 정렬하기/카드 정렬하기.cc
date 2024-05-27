#include <iostream>
#include <queue>

using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int iNum = 0;
    
    cin >> iNum;
  
    priority_queue<int> queueNum;
    
    for(int i = 0; i < iNum; ++i)
    {
        int input = 0;
        cin >> input;
        queueNum.push(-input);
    }
    
    if(iNum == 1) 
    {
        cout << 0;
        return 0;
    }
    
    int iAnswer = 0;
    
    for(int i = 0; i < 2; ++i)
    if(!queueNum.empty())
    {
        iAnswer += -queueNum.top();
        queueNum.pop();
    }
    
    int iTemp = iAnswer;
    
    while(!queueNum.empty())
    {
        if(iTemp <= -queueNum.top())
        {
            iTemp += -queueNum.top();
            iAnswer += iTemp;
            queueNum.pop();
        }
        else
        {
            queueNum.push(-iTemp);
            iTemp = -queueNum.top();
            queueNum.pop();
            
            iTemp += -queueNum.top();
            queueNum.pop();
            iAnswer += iTemp;
        }
        
        
    }
    
    cout << iAnswer;
    
    return 0;
}