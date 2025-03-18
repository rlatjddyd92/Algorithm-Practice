#include <iostream> 
using namespace std;
int main ()
{
    int iNum = 0;
    string strInput = {};
    cin >> iNum;
    cin >> strInput;
    int iAnswer = 0;
    
    for (int i = 0; i < strInput.size(); ++i)
    iAnswer += strInput[i] - '0';
    cout << iAnswer;
    return 0;
}