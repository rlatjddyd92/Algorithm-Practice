#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct NODE
{
    queue<int> queueRoute;
    int iInput = 0;
    int iVisit = 0;
};

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    map<int, NODE> mapRoute;
    answer.resize(4);
    
    for (int i = 0; i < edges.size(); ++i)
    {
        if (mapRoute.find(edges[i][0]) == mapRoute.end())
        {
            NODE New{};
            mapRoute.insert({edges[i][0], New});
        }
        if (mapRoute.find(edges[i][1]) == mapRoute.end())
        {
            NODE New{};
            mapRoute.insert({edges[i][1], New});
        }
        mapRoute.find(edges[i][0])->second.queueRoute.push(edges[i][1]);
        mapRoute.find(edges[i][1])->second.iInput += 1;
    }
    
    int iStartNode = 0;
    
    for(auto& pair : mapRoute)
    {
        if ((pair.second.iInput == 0) && (pair.second.queueRoute.size() >= 2))
        {
            iStartNode = pair.first;
            break;
        }
    }
    
    answer[0] = iStartNode;
    
    while(mapRoute.find(iStartNode)->second.queueRoute.empty() == false)
    {
        int iNowNode = mapRoute.find(iStartNode)->second.queueRoute.front();
        mapRoute.find(iStartNode)->second.queueRoute.pop();
        
        queue<int> queueNext;
        queueNext.push(iNowNode);
        mapRoute.find(iNowNode)->second.iVisit = 1;
        
        int iResult = 0; // 도넛, 막대, 8자 
        
        while(queueNext.empty() == false)
        {
            iNowNode = queueNext.front();
            queueNext.pop();
            
            while (mapRoute.find(iNowNode)->second.queueRoute.empty()== false)
            {
                int iNext = mapRoute.find(iNowNode)->second.queueRoute.front();
                mapRoute.find(iNowNode)->second.queueRoute.pop();
                
                if (mapRoute.find(iNext)->second.iVisit == 1)
                {
                    if (iResult == 0)
                        iResult = 1;
                    else if (iResult == 1)
                        iResult = 3;
                }
                else 
                    mapRoute.find(iNext)->second.iVisit = 1;
                
                queueNext.push(iNext);
            }
            
        }
        
        if (iResult == 0)
                iResult = 2;
            
            ++answer[iResult];
        
    }
    
    return answer;
}