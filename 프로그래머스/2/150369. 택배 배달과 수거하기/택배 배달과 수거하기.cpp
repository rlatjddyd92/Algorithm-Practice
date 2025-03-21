#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    pair<int,int> INDEX = {n-1,n-1}; // 배달, 수거
    
    while(INDEX.first >= 0 || INDEX.second >= 0)
    {
        int iMax = 0;
        int iCap = cap;
        
        while (1)
        {   
            if ((INDEX.first >= 0) && (deliveries[INDEX.first] == 0))
                --INDEX.first;
            else if  ((INDEX.first >= 0) && (iCap > 0))
            {
                if (INDEX.first + 1 > iMax)
                iMax = INDEX.first + 1;
                
                int iNow = deliveries[INDEX.first];
                 deliveries[INDEX.first] -= min(iCap, deliveries[INDEX.first]);
                iCap -= iNow;
            }
            else 
                 break;
            
            if (INDEX.first < 0)
                 break;
               
            if (iCap <= 0)
            {
                break;
            }
        }
        
        iCap = cap;
            
         while (1)
        {   
            if ((INDEX.second >= 0) && (pickups[INDEX.second] == 0))
                --INDEX.second;
            else if  ((INDEX.second >= 0) && (iCap > 0))
            {
                if (INDEX.second + 1 > iMax)
                iMax = INDEX.second + 1;
                
                int iNow = pickups[INDEX.second];
                 pickups[INDEX.second] -= min(iCap, pickups[INDEX.second]);
                iCap -= iNow;
            }
             else 
                 break;
             
             if (INDEX.second < 0)
                 break;
               
            if (iCap <= 0)
            {
                break;
            }
        }
        
        answer += iMax * 2;
    }
    
    
    
    
    
    
    return answer;
}