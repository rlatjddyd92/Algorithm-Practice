#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = (long long)0;
    
    long long llMin = (long long)1;
    long long llMax = sqrt(n);
    
    while (llMax >= llMin)
    {
        long long llMid = (llMin + llMax) / 2;
        long long llPow = llMid * llMid;
        if (llPow == n)
            return ((llMid + 1) * (llMid + 1));
        else if (llPow < n)
            llMin = llMid + 1;
        else 
            llMax = llMid - 1;
    }
    return -1;
}