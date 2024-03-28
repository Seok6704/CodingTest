#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    string S_a = to_string(a);
    string S_b = to_string(b);
    
    string S_answer = S_a + S_b;
    string S_answer2 = S_b + S_a;
    
    if(stoi(S_answer) >= stoi(S_answer2)) answer = stoi(S_answer);
    else answer = stoi(S_answer2);
    
    return answer;
}