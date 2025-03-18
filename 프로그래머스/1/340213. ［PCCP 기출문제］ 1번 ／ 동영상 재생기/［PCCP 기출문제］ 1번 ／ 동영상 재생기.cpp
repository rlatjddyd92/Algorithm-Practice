#include <string>
#include <vector>

using namespace std;

int InterpretTime(string Time)
{
    int iReturn = 0;
    
    iReturn = ((int(Time[0]) - int('0')) * 10) + (int(Time[1]) - int('0'));
    iReturn *= 60;
    iReturn += ((int(Time[3]) - int('0')) * 10) + (int(Time[4]) - int('0'));
    
    return iReturn;
}
string MakeString(int iSecond)
{
    string strReturn = {};
    int Min = iSecond / 60;
    strReturn += (Min / 10) + '0';
    strReturn += (Min % 10) + '0';
    iSecond %= 60;
    strReturn += ":";
    strReturn += (iSecond / 10) + '0';
    strReturn += (iSecond % 10) + '0';
    return strReturn;
}

string AddTime(string Time, int iLimit, int iSecond)
{
    int iNewTime = InterpretTime(Time) + iSecond;
    iNewTime = max(0, iNewTime);
    iNewTime = min(iLimit, iNewTime);
    return MakeString(iNewTime);
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int iLen = InterpretTime(video_len);
    int iPos = InterpretTime(pos);
    int iOp_start = InterpretTime(op_start);
    int iOp_end = InterpretTime(op_end);
    int iNow = iPos;
    
    for (int i = 0; i < commands.size(); ++i)
    {
        if ((iNow >= iOp_start) && (iNow <= iOp_end))
            iNow = iOp_end;
        
        if (commands[i] == "prev")
            iNow = max(0, iNow - 10);
        else 
            iNow = min(iLen, iNow + 10);
    }
    
     if ((iNow >= iOp_start) && (iNow <= iOp_end))
            iNow = iOp_end;
    
    answer = MakeString(iNow);
    
    
    
    return answer;
}


