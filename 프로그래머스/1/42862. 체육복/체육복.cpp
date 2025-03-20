#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    answer = n;
    
    vector<int> vecCount;
    vecCount.resize(n + 1, 0);
    
    for(auto& iter : lost)
    vecCount[iter] -= 1;
    
    for(auto& iter : reserve)
    vecCount[iter] += 1;
    
    for(auto& iter : vecCount)
        if (iter < 0)
            --answer;
    
    bool bIsReserve = false;
    bool bIsLost = false;
    
    for (int i = 2; i < vecCount.size(); ++i)
    {
        if ((vecCount[i - 1] > 0) && (vecCount[i] < 0))
        {
            ++answer;
            vecCount[i] = 0;
        }
        else if ((vecCount[i - 1] < 0) && (vecCount[i] > 0))
        {
             ++answer;
            vecCount[i] = 0;
        }
    }
    
    
    
    
    
    
    
    
    return answer;
}