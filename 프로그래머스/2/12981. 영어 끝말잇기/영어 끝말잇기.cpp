#include <string>
#include <vector>
#include <iostream>
#include <set> 

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.resize(2,0);
    
    set<string> setWord;
    
    for(int i = 0; i < words.size(); ++i)
    {
        if ((setWord.find(words[i]) != setWord.end())
            || ((i > 0)&&(words[i - 1][words[i - 1].size() - 1] != words[i][0])))
        {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            break;
        }
        
        setWord.insert(words[i]);
    }

    return answer;
}