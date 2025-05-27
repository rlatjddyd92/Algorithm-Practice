#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    vector<int> vecCount;
    vecCount.resize(number + 1, 1);
    vecCount[0] = 0;
    
    for(int i = 2; i <= number; ++i)
        for(int j = i; j <= number;)
        {
            ++vecCount[j];
            j += i;
        }
    
    for(auto& iter : vecCount)
        answer += iter > limit ? power : iter;

    return answer;
}