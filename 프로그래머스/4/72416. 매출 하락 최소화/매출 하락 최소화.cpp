#include <string>
#include <vector>
#include <queue>

using namespace std;

struct PEOPLE
{
    int iBoss = 0;
    int iMate = 0;
    int iNow = 0;
    int iMin = 0;
};

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    
    // 위상정렬 
    vector<PEOPLE> vecPeople;
    vecPeople.resize(sales.size() + 1);
    
    for (int i = 0; i < sales.size(); ++i)
        vecPeople[i + 1].iNow = vecPeople[i + 1].iMin = sales[i];
    
    for (int i = 0; i < links.size(); ++i)
    {
        ++vecPeople[links[i][0]].iMate;
        vecPeople[links[i][1]].iBoss = links[i][0];
    }
    
    queue<int> queueNowPeople;
    
    for (int i = 1; i < vecPeople.size(); ++i)
    {
         if (vecPeople[i].iMate == 0)
         {
             queueNowPeople.push(i);
                vecPeople[i].iMin = 0;
        }
            
    }
   
    
    while (queueNowPeople.empty() == false)
    {
        int iNowPeople = queueNowPeople.front();
        queueNowPeople.pop();
        vecPeople[iNowPeople].iNow -= vecPeople[iNowPeople].iMin;
        answer += vecPeople[iNowPeople].iMin;
        
        if (iNowPeople == 1)
            break;
        
        int iNowBoss = vecPeople[iNowPeople].iBoss;
        if (vecPeople[iNowBoss].iMin > vecPeople[iNowPeople].iNow)
        vecPeople[iNowBoss].iMin = vecPeople[iNowPeople].iNow;
        
        --vecPeople[iNowBoss].iMate;
        if (vecPeople[iNowBoss].iMate == 0)
            queueNowPeople.push(iNowBoss);
    }
    
    
    
    
    
    
    
    
    return answer;
}