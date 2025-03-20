#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    int iFullBox[2] = {0,0};
    int iFindBox[2] = {0,0};
    
    iFullBox[0] = (n/w) + (n%w>0);
    iFullBox[1] = n%w == 0 ? w : n%w;
    
    iFindBox[0] = (num/w) + (num%w>0);
    iFindBox[1] = num%w == 0 ? w : num%w;
    
    answer = iFullBox[0] - iFindBox[0] + 1;
    
    if (iFullBox[0] % 2 == iFindBox[0] % 2)
        if (iFullBox[1] < iFindBox[1])
            --answer;
    
    if (iFullBox[0] % 2 != iFindBox[0] % 2)
        if (w - iFullBox[1] >= iFindBox[1])
            --answer;
    
    return answer;
}