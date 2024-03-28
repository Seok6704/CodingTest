#include <string>
#include <vector>
#include <map>

using namespace std;

int score[8] = {0, 3, 2, 1, 0, 1, 2, 3};

string solution(vector<string> survey, vector<int> c) {
    string answer = "";
    map<char, int> m;
    
    for(int i = 0; i < survey.size(); ++i)
    {
        m[survey[i][c[i] / 4]] += score[c[i]];
    }
    
    answer += m['R'] >= m['T'] ? "R" : "T";
    answer += m['C'] >= m['F'] ? "C" : "F";
    answer += m['J'] >= m['M'] ? "J" : "M";
    answer += m['A'] >= m['N'] ? "A" : "N";
    
    
    return answer;
}