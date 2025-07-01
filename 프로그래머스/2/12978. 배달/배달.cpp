#include <iostream>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct NODE 
{
    int iAnswer = 1;
    vector<pair<int,int>> vecRoute;
};

priority_queue<pair<int,int>> queueNext;
vector<NODE> vecNode;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    vecNode.resize(N + 1);
    
    for(int i = 0; i < road.size(); ++i)
    {
        pair<int,int> New;
        New.first = -1 * road[i][2];
        New.second = road[i][1];
        vecNode[road[i][0]].vecRoute.push_back(New);
        New.second = road[i][0];
        vecNode[road[i][1]].vecRoute.push_back(New);
    }
    
    pair<int,int> Start;
    Start.first = 0;
    Start.second = 1;
    vecNode[1].iAnswer = 0;
    queueNext.push(Start);
    
    while(queueNext.empty() == false)
    {
        pair<int,int> Now = queueNext.top();
        queueNext.pop();
        
        int iNow = Now.second;
        
        for(int i = 0; i < vecNode[iNow].vecRoute.size(); ++i)
        {
            int iNext = vecNode[iNow].vecRoute[i].second;
            int iCost = vecNode[iNow].vecRoute[i].first;
            
            if ((vecNode[iNext].iAnswer == 1) || (vecNode[iNext].iAnswer < vecNode[iNow].iAnswer + iCost))
            {
                vecNode[iNext].iAnswer = vecNode[iNow].iAnswer + iCost;
                queueNext.push(vecNode[iNow].vecRoute[i]);
            }
        }
    }
    
    for(int i = 0; i < vecNode.size(); ++i)
        if ((vecNode[i].iAnswer != 1) && (vecNode[i].iAnswer * -1 <= K))
            ++answer;
        
    return answer;
}