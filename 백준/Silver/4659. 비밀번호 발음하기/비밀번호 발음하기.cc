#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        string strInput = {};
        cin >> strInput;
        if (strInput == "end")
            break;

        int iCount_Aeiou = 0;
        bool bIsContain_Aeiou = false;
        bool bIsSame = false;

        for (int i = 0; i < strInput.size(); ++i)
        {
            if (i > 0)
                if ((strInput[i] != 'e') && (strInput[i] != 'o'))
                    if (strInput[i - 1] == strInput[i])
                    {
                        bIsSame = true;
                        break;
                    }


            bool bIsAeiou = false;

            bIsAeiou += strInput[i] == 'a' ? 1 : 0;
            bIsAeiou += strInput[i] == 'e' ? 1 : 0;
            bIsAeiou += strInput[i] == 'i' ? 1 : 0;
            bIsAeiou += strInput[i] == 'o' ? 1 : 0;
            bIsAeiou += strInput[i] == 'u' ? 1 : 0;

            if (bIsAeiou == true)
            {
                iCount_Aeiou = iCount_Aeiou < 0 ? 1 : iCount_Aeiou + 1;
                bIsContain_Aeiou = true;
            }
            else
            {
                iCount_Aeiou = iCount_Aeiou > 0 ? -1 : iCount_Aeiou - 1;
            }

            if (abs(iCount_Aeiou) >= 3)
                break;
        }

        if ((abs(iCount_Aeiou) < 3) && (bIsContain_Aeiou == true))
            if (bIsSame == false)
            {
                cout << "<" << strInput << ">" << " is acceptable." << "\n";
                continue;
            }

        cout << "<" << strInput << ">" << " is not acceptable." << "\n";


    }


    return 0;
}