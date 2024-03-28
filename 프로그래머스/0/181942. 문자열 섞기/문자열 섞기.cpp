#include <string>
#include <vector>

using namespace std;

string solution(string str1, string str2) {
    string answer = "";
    
    for(int a = 0; a < str1.length(); a++)
    {
        answer += str1[a];
        answer += str2[a];
    }
    return answer;
}