#include <string>
#include <vector>
#include <queue>

using namespace std;




int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    queue<pair<int,int>> queueBFS;
    queueBFS.push({1,0});
    
    vector<queue<int>> vectorRoute;
    vector<int> vecvisit;
    vectorRoute.resize(n + 1);
    vecvisit.resize(n + 1);
    vecvisit[1] = -1;
    
    for(int i = 0; i < edge.size(); ++i)
    {
        vectorRoute[edge[i][0]].push(edge[i][1]);
        vectorRoute[edge[i][1]].push(edge[i][0]);
    }
    
    while(queueBFS.empty() == false)
    {
        pair<int,int> Now = queueBFS.front();
        queueBFS.pop();
        
        while (vectorRoute[Now.first].empty() == false)
        {
            int iNext = vectorRoute[Now.first].front();
            vectorRoute[Now.first].pop();
            if (vecvisit[iNext] == 0)
            {
                vecvisit[iNext] = Now.second + 1;
                queueBFS.push({iNext, vecvisit[iNext]});
            }
        }
    }
    
    int iMax = 0;
    
    for (auto & iter : vecvisit)
    {
        if (iter > iMax)
        {
            answer = 1;
            iMax = iter;
        }
        else if (iter == iMax)
        {
            ++answer;
        }
    }
        
    
    
    return answer;
}