#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

double Find_Distance(pair<double, double> First, pair<double, double> Second)
{
    return sqrt(pow(First.first - Second.first, 2) + pow(First.second - Second.second, 2));
}

int main()
{
    vector<pair<double, double>> vecPoint;
    vecPoint.resize(3);

    for (int i = 0; i < 3; ++i)
        cin >> vecPoint[i].first >> vecPoint[i].second;

    double dMin = (double)100000;
    double dMax = (double)0;

    double dCheck = (vecPoint[0].first * vecPoint[1].second) + (vecPoint[1].first * vecPoint[2].second) + (vecPoint[2].first * vecPoint[0].second);
    dCheck -= (vecPoint[1].first * vecPoint[0].second) + (vecPoint[2].first * vecPoint[1].second) + (vecPoint[0].first * vecPoint[2].second);

    if (dCheck == double(0))
    {
        cout << -1;

        vecPoint.clear();

        return 0;
    }

    for (int i = 0; i < 3; ++i)
    {
        double dNow = (double)0;
        int iOpponent[2] = { (i + 1) % 3, (i + 2) % 3 };
        dNow += Find_Distance(vecPoint[i], vecPoint[iOpponent[0]]) * 2;
        dNow += Find_Distance(vecPoint[i], vecPoint[iOpponent[1]]) * 2;

        if (dNow < dMin)
            dMin = dNow;

        if (dNow > dMax)
            dMax = dNow;
    }

    cout << setprecision(15) << dMax - dMin;

    vecPoint.clear();

    return 0;
}