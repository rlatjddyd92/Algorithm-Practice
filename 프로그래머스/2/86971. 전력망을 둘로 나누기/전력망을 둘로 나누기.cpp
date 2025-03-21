#include <string>
#include <vector>
#include <queue>
#include <list>

using namespace std;

struct NODE
{
    queue<int> queueConnect;
    int iConnect = 0;
    int iCount = 0;
    bool bIsVisit = false;
};

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    list<int> Maxlist;
    Maxlist.push_back(1);
    
    vector<NODE> vecNode;
    vecNode.resize(n + 1);
    
    for (int i = 0; i < n - 1; ++i)
    {
        vecNode[wires[i][0]].queueConnect.push(wires[i][1]);
        vecNode[wires[i][0]].iConnect += 1;
        vecNode[wires[i][1]].queueConnect.push(wires[i][0]);
        vecNode[wires[i][1]].iConnect += 1;
    }
    
    queue<int> queueNext;
    
    for (int i = 1; i <= n ; ++i)
    {
        vecNode[i].iCount = 1;
        if (vecNode[i].iConnect == 1)
        {
            queueNext.push(i);
        }
    }
    
        
    
    
    while(queueNext.empty() == false)
    {
        int iNow = queueNext.front();
        queueNext.pop();
        vecNode[iNow].bIsVisit = true;
        
        if (Maxlist.back() < vecNode[iNow].iCount)
                Maxlist.push_back(vecNode[iNow].iCount);
        
        while(vecNode[iNow].queueConnect.empty() == false)
        {   
            int iNext = vecNode[iNow].queueConnect.front();
            vecNode[iNow].queueConnect.pop();
            if (vecNode[iNext].bIsVisit == true)
                continue;
            
            --vecNode[iNext].iConnect;
            vecNode[iNext].iCount += vecNode[iNow].iCount;
            
            
            
            if (vecNode[iNext].iConnect == 1)
                queueNext.push(iNext);
        }
    }
        
    while (Maxlist.empty() == false)
    {
        int iNow = Maxlist.back();
        Maxlist.pop_back();
        if (iNow == n)
            continue;
        
        if (abs(n - (iNow * 2)) < answer)
            answer = abs(n - (iNow * 2));
    }
        
    
    
    
    
    return answer;
}