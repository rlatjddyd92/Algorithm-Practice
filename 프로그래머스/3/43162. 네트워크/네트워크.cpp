#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> vecHead;

int Find_Head(int iIndex)
{
    if (vecHead[iIndex] != iIndex)
        vecHead[iIndex] = Find_Head(vecHead[iIndex]);
    
    return vecHead[iIndex];
}
void Merge_Head(int iFirst, int iSecond)
{
    Find_Head(iFirst);
    Find_Head(iSecond);
    int iNewHead = min(vecHead[iFirst], vecHead[iSecond]);
    vecHead[vecHead[iFirst]] = iNewHead;
    vecHead[vecHead[iSecond]] = iNewHead;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vecHead.resize(n);
    
    for (int i = 0; i < n; ++i)
        vecHead[i] = i;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (computers[i][j] == 1)
                Merge_Head(i,j);
        }
    }
    
    set<int> setHead;
    
    for (int i = 0; i < n; ++i)
    {
        int iHead = Find_Head(i);
        if (setHead.find(iHead) == setHead.end())
            setHead.insert(iHead);
    }
        
    answer = setHead.size();
    
    
    
    
    return answer;
}