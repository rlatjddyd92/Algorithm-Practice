#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<string> vecBuffer(board);
    while(1)
    {
        int iCount = 0;
        vector<string> vecNewBuffer(vecBuffer);
        bool bIsSuccess = false;
        for(int i = 0; i < m - 1 ; ++i)
            for(int j = 0; j < n - 1 ; ++j)
            {
                bool bIsDestroy = true;
                
                if (vecBuffer[i][j] == 'x')
                    continue;
                
                if (vecBuffer[i + 1][j] != vecBuffer[i][j])
                    bIsDestroy = false;
                
                if (vecBuffer[i + 1][j + 1] != vecBuffer[i][j])
                    bIsDestroy = false;
                
                if (vecBuffer[i][j + 1] != vecBuffer[i][j])
                    bIsDestroy = false;
                
                if (bIsDestroy == true)
                {
                    vecNewBuffer[i][j] = 'x';
                    vecNewBuffer[i + 1][j] = 'x';
                    vecNewBuffer[i][j + 1] = 'x';
                    vecNewBuffer[i + 1][j + 1] = 'x';
                    bIsSuccess = true;
                }
            }
        
        if (bIsSuccess == false)
            break;
        
        
        for(int j = 0; j < n ; ++j)
        {
            int iNow = m - 1;
            
            for(int i = m - 1; i >= 0 ; --i)
            {
                if (iNow == i)
                {
                    if(vecNewBuffer[i][j] != 'x')
                        --iNow;
                }
                else 
                {
                    if(vecNewBuffer[i][j] != 'x')
                    {
                        vecNewBuffer[iNow][j] = vecNewBuffer[i][j];
                        vecNewBuffer[i][j] = 'x';
                        --iNow;
                    }
                }
            }
        }
        
        //for(int i = 0; i < vecNewBuffer.size(); ++i)
            //cout << vecNewBuffer[i] << "\n";
        
        //cout << "\n";
        
        
        vecBuffer.swap(vecNewBuffer);
        vecNewBuffer.clear();
    }
    
    for(int i = 0; i < m ; ++i)
        for(int j = 0; j < n ; ++j)
            answer += (vecBuffer[i][j] == 'x');
    
    return answer;
}