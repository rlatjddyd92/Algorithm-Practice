#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

vector<int> vecPrime;
vector<bool> vecVisit;
int iAnswer = 0;

void DFS(string& strNumbers, int iNowNum, int iCount)
{
    if (vecPrime[iNowNum] == 0)
    {
        ++iAnswer;
        vecPrime[iNowNum] = -1;
    }
    
    if ((int)strNumbers.size() > iCount)
    {
        iNowNum *= 10;
        for(int i = 0; i < strNumbers.size(); ++i)
        {
            if (vecVisit[i] == true)
                continue;
            
            
                cout << iNowNum + (strNumbers[i] - '0') << "\n";
                vecVisit[i] = true;
                DFS(strNumbers, (iNowNum + (strNumbers[i] - '0')), iCount + 1);
                vecVisit[i] = false;
            
        }
        iNowNum /= 10;
    }
    
}

void MakePrime()
{
    vecPrime[0] = 1;
    vecPrime[1] = 1;
    
    for(int i = 2; i < vecPrime.size(); ++i)
    {
        if (vecPrime[i] != 1)
        {
            int iNow = i + i;
            while (iNow < vecPrime.size())
            {
                vecPrime[iNow] = 1;
                iNow += i;
            }
        }
    }
}

int solution(string numbers) {
    vecPrime.resize((int)pow(10,numbers.size() + 1));
    vecVisit.resize(numbers.size());
    
    MakePrime();
    DFS(numbers, 0, 0);
    
    return iAnswer;
}