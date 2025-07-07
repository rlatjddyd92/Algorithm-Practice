#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    vector<vector<int>> vecVisit;
    vector<int> vecMax; 
    
    vecVisit.resize(n + 1);
    
    for(int i = 0; i < vecVisit.size(); ++i)
        vecVisit[i].resize(n + 1, n * 2);
    
    for(int i = 0; i < results.size(); ++i)
    {
        vecVisit[results[i][0]][results[i][1]] = 1;
        vecVisit[results[i][1]][results[i][0]] = -1;
    }
    
    for(int i = 0; i < n; ++i)
        vecVisit[i][i] = 0;
    
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
            {
                if ((vecVisit[i][k] == 1) && (vecVisit[k][j] == 1))
                {
                    vecVisit[i][j] = 1;
                    vecVisit[j][i] = -1;
                }
            }
                
    for(int i = 1; i < vecVisit.size(); ++i)
    {
        int iCount = 0;
        for(int j = 1; j < vecVisit[i].size(); ++j)
            if ((vecVisit[i][j] == 1) || (vecVisit[i][j] == -1))
                ++iCount;
        
        if (iCount + 1 == n)
            ++answer;
    }
    
    return answer;
}