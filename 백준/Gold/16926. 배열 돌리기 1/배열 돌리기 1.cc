#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int iRow = 0;
    int iCol = 0;
    int iCount = 0;

    cin >> iRow >> iCol >> iCount;

    vector<vector<int>> vecMatrix;

    vecMatrix.resize(iRow);

    for (int i = 0; i < iRow; ++i)
    {
        vecMatrix[i].resize(iCol);

        for (int j = 0; j < iCol; ++j)
        {
            cin >> vecMatrix[i][j];
        }
    }

    vector<list<int>> vecRotate;

    vecRotate.resize(min(iRow, iCol) / 2);

    for (int i = 0; i < vecRotate.size(); ++i)
    {
        for (int j = i; j < (iRow - i); ++j)
            vecRotate[i].push_back(vecMatrix[j][i]);

        for (int j = i + 1; j < (iCol - i); ++j)
            vecRotate[i].push_back(vecMatrix[(iRow - i) - 1][j]);

        for (int j = (iRow - i) - 2; j >= i; --j)
            vecRotate[i].push_back(vecMatrix[j][(iCol - i) - 1]);

        for (int j = (iCol - i) - 2; j > i; --j)
            vecRotate[i].push_back(vecMatrix[i][j]);
    }

    for (int i = 0; i < vecRotate.size(); ++i)
    {
        int iRotateCount = iCount % vecRotate[i].size();

        while (iRotateCount > 0)
        {
            vecRotate[i].push_front(vecRotate[i].back());
            vecRotate[i].pop_back();
            --iRotateCount;
        }
    }

    for (int i = 0; i < vecRotate.size(); ++i)
    {
        for (int j = i; j < (iRow - i); ++j)
        {
            vecMatrix[j][i] = vecRotate[i].front();
            vecRotate[i].pop_front();
        }

        for (int j = i + 1; j < (iCol - i); ++j)
        {
            vecMatrix[(iRow - i) - 1][j] = vecRotate[i].front();
            vecRotate[i].pop_front();
        }
            
        for (int j = (iRow - i) - 2; j >= i; --j)
        {
            vecMatrix[j][(iCol - i) - 1] = vecRotate[i].front();
            vecRotate[i].pop_front();
        }
            
        for (int j = (iCol - i) - 2; j > i; --j)
        {
            vecMatrix[i][j] = vecRotate[i].front();
            vecRotate[i].pop_front();
        }
    }

    for (int i = 0; i < iRow; ++i)
    {
        for (int j = 0; j < iCol; ++j)
            cout << vecMatrix[i][j] << " ";
        cout << "\n";
    }

    for (auto& iter : vecRotate)
        iter.clear();

    vecRotate.clear();
       
    for (auto& iter : vecMatrix)
        iter.clear();

    vecMatrix.clear();

    return 0;
}