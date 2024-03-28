#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    sort(X.begin(), X.end(), greater<int>());
    sort(Y.begin(), Y.end(), greater<int>());
    int xp = 0, yp = 0;
    
    while(xp < X.length() || yp < Y.length())
    {
        if(X[xp] > Y[yp]) xp++;
        else if(X[xp] < Y[yp]) yp++;
        else if(X[xp] == Y[yp])
        {
            answer += X[xp];
            xp++; yp++;
        }
    }
    if(answer == "") answer = "-1";
    else if(answer[0] == '0') answer = "0";
    
    return answer;
}