#include <string>
#include <vector>

using namespace std;

int CheckCell(vector<int>& Answer, vector<vector<int>>& vecArr, int iRow, int iCol, int iInterval)
{
    if (iInterval == 0)
        return vecArr[iRow][iCol];
    
    int iCount = 0;
    int iTotal = 4;
    
    iCount += CheckCell(Answer, vecArr, iRow, iCol, iInterval / 2);
    iCount += CheckCell(Answer, vecArr, iRow + iInterval, iCol + iInterval, iInterval / 2);
    iCount += CheckCell(Answer, vecArr, iRow + iInterval, iCol, iInterval / 2);
    iCount += CheckCell(Answer, vecArr, iRow, iCol + iInterval, iInterval / 2);
    
    iTotal -= (iCount / 10);
    iCount %= 10;
    
    if ((iTotal == 4) && (iCount == 4))
        return 1;
    else if ((iTotal == 4) && (iCount == 0))
        return 0;
    else
    {
        Answer[0] += iTotal - iCount;
        Answer[1] += iCount;
        return 10;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    answer.resize(2);
    
    int iCheck = CheckCell(answer, arr, 0,0, arr.size() / 2);
    
    if (answer[0] + answer[1] == 0)
        ++answer[iCheck];
    
    return answer;
}