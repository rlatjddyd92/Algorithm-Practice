#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    
    int iIndex[2] = {0,200000000};
    
    int iNow = 0;
    
    while(iIndex[0] < iIndex[1])
    {
        iNow = (iIndex[1] + iIndex[0]) / 2;
        
        int iCount = 0;
        
        for(int i = 0; i < stones.size(); ++i)
        {
            if (stones[i] > iNow)
                iCount = 0;
            else 
                ++iCount;
            
            if (iCount >= k)
                break;
        }
        
        if (iCount >= k)
            iIndex[1] = iNow;
        else 
            iIndex[0] = iNow + 1;
    }
    
    answer = max(iIndex[0], iIndex[1]);
    
    return answer;
}