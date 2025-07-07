#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int iD_Row[4] = {0,0,1,-1};
int iD_Col[4] = {1,-1,0,0};

bool Check_Distance(int iRow, int iCol, vector<string>& places)
{
    if (places[iRow][iCol] != 'P')
        return true;
    
    queue<pair<int,int>> queueNext;
    pair<int,int> Start;
    Start.first = iRow;
    Start.second = iCol;
    queueNext.push(Start);
    
    while(queueNext.empty() == false)
    {
        pair<int,int> Now = queueNext.front();
        queueNext.pop();
        
        for(int i = 0; i < 4; ++i)
        {
            if ((Now.first + iD_Row[i] < 0) || (Now.first + iD_Row[i] >= places.size()))
                continue;
            
            if ((Now.second + iD_Col[i] < 0) || (Now.second + iD_Col[i] >= places[i].size()))
                continue;
            
            if ((Now.first + iD_Row[i] == iRow) && (Now.second + iD_Col[i] == iCol))
                continue;
            
            if (places[Now.first + iD_Row[i]][Now.second + iD_Col[i]] == 'X')
                continue;
            
            if (places[Now.first + iD_Row[i]][Now.second + iD_Col[i]] == 'P')
            {
                //cout << iRow << " " << iCol << ":"<<Now.first + iD_Row[i] << " "<< Now.second + iD_Col[i]<< "\n";
                return false;
            }
                
                
            if ((Now.first == iRow) && (Now.second == iCol))
            {
                pair<int,int> Next;
                Next.first = Now.first + iD_Row[i];
                Next.second = Now.second + iD_Col[i];
                queueNext.push(Next);
            }
        }
    }
    
    return true;
}





vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for(int i = 0; i < places.size(); ++i)
    {
        bool bIsOk = true;
        for(int j = 0; j < places[i].size(); ++j)
            for(int k = 0; k < places[i][j].size(); ++k)
                if ((bIsOk == true) && (Check_Distance(j, k, places[i]) == false))
                    bIsOk = false;
                
        //cout << "\n";
        answer.push_back((int)bIsOk);
    }
    
    return answer;
}