#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int iTime = bandage[0];
    int iDotHeal = bandage[1];
    int iComHeal = bandage[2];
    int iNowHealth = health;
    int iBeforeAttackTime = 0;
    
    for (int i = 0 ; i < attacks.size(); ++i)
    {
        int iNowSecond = attacks[i][0];
        int iNowDamege = attacks[i][1];
        
        int iCountHeal = (iNowSecond - iBeforeAttackTime - 1);
        iNowHealth += (iCountHeal * iDotHeal) + ((iCountHeal / iTime) * iComHeal);
        iNowHealth = min(iNowHealth, health);
        
        iNowHealth -= iNowDamege;
        iBeforeAttackTime = iNowSecond;
        if (iNowHealth < 1)
        {
            iNowHealth = -1;
            break;
        }
            
    }
    
    answer = iNowHealth;
    return answer;
}