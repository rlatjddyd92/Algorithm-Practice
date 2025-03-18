#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    long long llMax = (long long)d *  (long long)d;
    
    vector<long long> vecPow;
    
    for(int i = 0; i <= (long long)d; ++i)
    {
        vecPow.push_back((long long)i * (long long)i);
    }
    
     for(int i = 0; i <= (long long)d; )
     {
        long long llRemain = llMax - vecPow[i];
        long long llNow = upper_bound(vecPow.begin(), vecPow.end(), llRemain) - vecPow.begin() - 1;
       
         llNow /= (long long)k;
         llNow += 1;
         answer += llNow;
         i += k;
     }

    return answer;
}