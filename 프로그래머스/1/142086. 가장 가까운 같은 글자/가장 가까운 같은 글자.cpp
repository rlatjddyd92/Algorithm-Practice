#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> vecCount;
    vecCount.resize('z' - 'a' + 1, -1);
    for(int i = 0; i < s.size(); ++i)
    {
        int iNow = (vecCount[s[i] - 'a'] == -1) ? -1 : (i - vecCount[s[i] - 'a']);
        answer.push_back(iNow);
        vecCount[s[i] - 'a'] = i;
    }
    return answer;
}