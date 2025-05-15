using System;

class Solution
{
    public long solution(int price, int money, int count)
    {
        long llSum = (((1+count) * count) / 2);
        if (money < price * llSum) 
            return -(money - price * llSum);
        else 
            return 0;
    }
}