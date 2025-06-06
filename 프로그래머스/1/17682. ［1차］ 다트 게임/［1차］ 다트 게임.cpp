#include <string>
#include <list>

using namespace std;

int solution(string dartResult) {
    //dartResult = "10T#1T*2D*";
    
    long long answer = (long long)0;
    list<long long> Numlist;
    long long iNow = (long long)0;
    for(int i = 0; i < dartResult.size(); ++i)
    {   
        if ((dartResult[i] >= '0') && (dartResult[i] <= '9'))
        {
            iNow *= (long long)10;
            iNow += (long long)(dartResult[i] - '0');
            continue;
        }
        else if (dartResult[i] == 'S')
        {
            Numlist.push_back(iNow);
        }
        else if (dartResult[i] == 'D')
        {
            Numlist.push_back(iNow * iNow);
        }
        else if (dartResult[i] == 'T')
        {
            Numlist.push_back(iNow * iNow * iNow);
        }
        else if (dartResult[i] == '#')
        {
            Numlist.back() *= (long long)-1;
        }
        else if (dartResult[i] == '*')
        {
            list<long long> Buffer;
            for (int j = 0; j < 2; ++j)
            {
                if (Numlist.empty() == false)
                {
                    Buffer.push_front(Numlist.back() * (long long)2);
                    Numlist.pop_back();
                }
            }
            
            while(Buffer.empty() == false)
            {
                Numlist.push_back(Buffer.front());
                Buffer.pop_front();
            }
            
            
        }
        iNow = (long long)0;
    }
    
    while(Numlist.empty() == false)
    {
        answer += Numlist.front();
        Numlist.pop_front();
    }
    
    return (int)answer;
}