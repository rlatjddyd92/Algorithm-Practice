#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = enemy.size();
    
    priority_queue<int> queueEnemy;
    
    for(int i = 0; i < enemy.size(); ++i)
    {
        n -= enemy[i];
        queueEnemy.push(enemy[i]);
        
        while((queueEnemy.empty() == false) && (n < 0))
        {
            if (k <= 0)
                break;
            
            --k;
            n += queueEnemy.top();
            queueEnemy.pop();
        }
        
        if (n < 0)
        {
            answer = i;
            break;
        }
    }
    
    return answer;
}