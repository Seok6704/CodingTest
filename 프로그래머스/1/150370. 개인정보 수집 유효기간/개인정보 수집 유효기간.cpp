#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    map<char, int> term;
    int ty, tm, td;
    char nterm;
    ty = stoi(today.substr(0, 4));
    tm = stoi(today.substr(5, 2));
    td = stoi(today.substr(8, 2));
    
    for(int i = 0; i < terms.size(); i++)
    {
        term.insert(make_pair(terms[i][0], stoi(terms[i].substr(2, terms[i].length()))));
    }
    for(int i = 0; i < privacies.size(); i++)
    {
        nterm = privacies[i][privacies[i].length() - 1];
        int ny = stoi(privacies[i].substr(0, 4));
        int nm = stoi(privacies[i].substr(5, 2)) + term[nterm];
        int nd = stoi(privacies[i].substr(8, 2)) - 1;
        while(nm >= 13)
        {
            nm -= 12;
            ny++;
        }
        if(nd == 0)
        {
            nm--;
            nd = 28;
            if(nm == 0)
            {
                ny--;
                nm = 12;
            }
        }
        if(ny < ty) answer.push_back(i + 1);
        else if(ny == ty && ny == ty && nm < tm) answer.push_back(i + 1);
        else if(ny == ty && nm == tm && nd <= td - 1) answer.push_back(i + 1);
    }
    
    
    
    return answer;
}