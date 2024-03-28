#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 1;
    int answer2 = 0;
    
    for(int a = 0; a < size(num_list); a++)
    {
        answer *= num_list[a];
        answer2 += num_list[a];
    }
    if(answer <= answer2*answer2) answer = 1;
    else answer = 0;
    
    return answer;
}