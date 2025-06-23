#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    vector<pair<int,int>> vecTime;
    vector<int> vecOut;
    priority_queue<int> queueOccupied;
    
    for(int i = 0; i < book_time.size(); ++i)
    {
        pair<int,int> TIME;
        
        TIME.first = 0;
        TIME.first += (((book_time[i][0][0] - '0') * 10) + (book_time[i][0][1] - '0')) * 60;
        TIME.first += (((book_time[i][0][3] - '0') * 10) + (book_time[i][0][4] - '0'));
        
        TIME.second = 0;
        TIME.second += (((book_time[i][1][0] - '0') * 10) + (book_time[i][1][1] - '0')) * 60;
        TIME.second += (((book_time[i][1][3] - '0') * 10) + (book_time[i][1][4] - '0'));
        
        vecTime.push_back(TIME);
    }
        
    sort(vecTime.begin(), vecTime.end(), [](pair<int,int> LEFT, pair<int,int> RIGHT)
         {
             if (LEFT.first < RIGHT.first)
                 return true;
             else if (LEFT.first > RIGHT.first)
                 return false;
             
             return false;
         });
    
    for(int i = 0; i < vecTime.size(); ++i)
        cout << vecTime[i].first << " " << vecTime[i].second << "\n";
    
    cout << "\n";
    
    
    vecOut.push_back(0);
    
    for(int i = 0; i < vecTime.size(); ++i)
    {
        sort(vecOut.begin(), vecOut.end());
        
        int iIndex = lower_bound(vecOut.begin(), vecOut.end(), vecTime[i].first) - vecOut.begin();
        if (iIndex > vecOut.size())
            vecOut.back() = vecTime[i].second + 10;
        else if (vecOut[iIndex] > vecTime[i].first)
        {
            if (iIndex == 0)
                vecOut.push_back(vecTime[i].second + 10);
            else 
                vecOut[iIndex - 1] = vecTime[i].second + 10;
        }
        else 
        {
            vecOut[iIndex] = vecTime[i].second + 10;
        }
        
        //for(int i = 0; i < vecOut.size() ; ++i)
            //cout << vecOut[i] << " ";
        //cout << "\n";
    }
    
    
    
    return vecOut.size();
}