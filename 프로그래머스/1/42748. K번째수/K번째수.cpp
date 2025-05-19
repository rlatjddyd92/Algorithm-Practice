#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(auto & iter : commands)
    {
        vector<int> NowArray = array;
        sort(NowArray.begin() + iter[0] - 1, NowArray.begin() + iter[1]);
        answer.push_back(NowArray[iter[0] - 1 + iter[2] - 1]);
    }
    
    return answer;
}