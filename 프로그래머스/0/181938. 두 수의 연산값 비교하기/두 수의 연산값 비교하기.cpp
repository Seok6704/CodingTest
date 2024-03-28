#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int answer = 0;
    
    int s_answer = stoi(to_string(a) + to_string(b));
    answer = 2 * a * b;
    if(s_answer >= answer) return s_answer;
    else return answer;
}