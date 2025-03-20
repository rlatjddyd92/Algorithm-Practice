#include <string>
#include <vector>

using namespace std;

int InterPretDate(string strInput)
{
    int iReturn = 0;
    
    int iYear = 0;
    
    for (int i = 1; i < 4; ++i)
    {
        iYear *= 10;
        iYear += strInput[i] - '0';
    }
    
    iReturn += iYear * 28 * 12;
    
    int iMonth = 0;
    
    for (int i = 5; i < 7; ++i)
    {
        iMonth *= 10;
        iMonth += strInput[i] - '0';
    }
    
    iReturn += (iMonth - 1) * 28;
    
    int iDate = 0;
    
     for (int i = 8; i < 10; ++i)
    {
        iDate *= 10;
        iDate += strInput[i] - '0';
    }
    
    iReturn += iDate;
    
    return iReturn;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    vector<int> vecExpire;
    vecExpire.resize('Z' - 'A' + 1);
    
    int iToday = InterPretDate(today);
    
    for (int i = 0 ; i < terms.size() ; ++i)
    {
        string strNow = terms[i];
        int iIndex = strNow[0] - 'A';
        
         int iDate = 0;
        
        for (int i = 2 ; i < strNow.size(); ++i)
        {
             iDate *= 10;
            iDate += strNow[i] - '0';
        }
        
       
        vecExpire[iIndex] = iDate * 28;
    }
        
    int iEndIndex = privacies[0].size() - 1;
        
    for (int i = 0 ; i < privacies.size() ; ++i)
    {
        int iStartDate = InterPretDate(privacies[i]);
        int iIndex = privacies[i][iEndIndex] - 'A';
    
        int iExpire = iStartDate + vecExpire[iIndex];
    
        if (iToday >= iExpire)
            answer.push_back(i + 1);
    }
    
    
    
    return answer;
}