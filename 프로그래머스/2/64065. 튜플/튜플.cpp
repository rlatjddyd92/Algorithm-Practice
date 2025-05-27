#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int,int> mapNum;
    queue<int> queueNum;
    int iNowNum = 0;
    int iSize = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if ((s[i] >= '0') && (s[i] <= '9'))
        {
            iNowNum *= 10;
            iNowNum += s[i] - '0';
        }
        else if ((s[i] == ',') && (iNowNum > 0))
        {
            queueNum.push(iNowNum);
            iNowNum = 0;
        }
        else if (s[i] == '}')
        {
            if (iNowNum > 0)
            {
                queueNum.push(iNowNum);
                iNowNum = 0;
            }
            
            int iLimit = queueNum.size() - 1;
            iSize = max((int)queueNum.size(), iSize);
            while(queueNum.empty() == false)
            {
                int iNow = queueNum.front();
                queueNum.pop();
                if (mapNum.find(iNow) == mapNum.end())
                    mapNum.insert({iNow, iLimit});
                else 
                    mapNum.find(iNow)->second = min(mapNum.find(iNow)->second, iLimit);
            }
        }
    }
    
    answer.resize(iSize);
    for(auto& pair : mapNum)
        answer[pair.second] = pair.first;
    
    return answer;
}