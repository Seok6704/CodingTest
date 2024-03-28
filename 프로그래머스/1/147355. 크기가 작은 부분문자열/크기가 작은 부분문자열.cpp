#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    double ip = stod(p);
    
    for(int i = 0; i <= t.length() - (p.length()); i++)
    {
        if(ip >= stod(t.substr(i, p.length()))) answer++;
    }
    
    return answer;
}