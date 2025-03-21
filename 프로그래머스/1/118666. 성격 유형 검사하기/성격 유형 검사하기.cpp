#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "ZZZZ";
    
    vector<long long> vecScore;
    vecScore.resize('Z'-'A' + 1,0);
    
    for(int i = 0; i < survey.size(); ++i)
    {
        if (choices[i] < 4)
            vecScore[survey[i][0] - 'A'] += (long long)4 - (long long)choices[i];
        else if (choices[i] > 4)
            vecScore[survey[i][1] - 'A'] += (long long)choices[i] - (long long)4;
    }
    
    if (vecScore['R'- 'A'] > vecScore['T'- 'A'])
        answer[0] = 'R';
    else if (vecScore['R'- 'A'] < vecScore['T'- 'A'])
        answer[0]= 'T';
    else 
        answer[0]= min('R','T');
    
    if (vecScore['C'- 'A'] > vecScore['F'- 'A'])
        answer[1]= 'C';
    else if (vecScore['C'- 'A'] < vecScore['F'- 'A'])
        answer[1]= 'F';
    else 
        answer[1]= min('C','F');
    
    if (vecScore['J'- 'A'] > vecScore['M'- 'A'])
        answer[2]= 'J';
    else if (vecScore['J'- 'A'] < vecScore['M'- 'A'])
         answer[2]= 'M';
    else 
         answer[2]= min('J','M');
    
    if (vecScore['A'- 'A'] > vecScore['N'- 'A'])
         answer[3]= 'A';
    else if (vecScore['A'- 'A'] < vecScore['N'- 'A'])
        answer[3]= 'N';
    else 
        answer[3]= min('A','N');
    
    return answer;
}