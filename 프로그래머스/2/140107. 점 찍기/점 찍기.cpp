#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    // 원점에서 특정 좌표까지의 거리 = sqrt(pow(x, 2) + pow(y, 2));
    
    for(int i = 0; i <= d; i += k)
    {
        long long temp = sqrt((long long)pow(d, 2) - (long long)pow(i, 2));
        answer +=  temp / k + 1;
    }
    
    return answer;
}