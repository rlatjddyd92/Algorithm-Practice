#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int iRMin = n >= m ? m : n;
    int iRMax = n <= m ? m : n;
    
    while(iRMax * iRMin > 0)
    {
        if (iRMax > iRMin)
            iRMax %= iRMin;
        else 
            iRMin %= iRMax;
    }
    
    answer.push_back(iRMax > 0 ? iRMax : iRMin);
    answer.push_back((n * m) / answer[0]);
    
    return answer;
}