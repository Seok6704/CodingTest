#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;

    for (int i = 1; i < r2; ++i) {
        int BR = 0;
        int SR = 0;

        BR = (int)floor(sqrt(pow(r2, 2) - pow(i, 2))); // 큰원의 최대치   // 내림
        
        if(i < r1) {
            SR = (int)ceil(sqrt(pow(r1, 2) - pow(i, 2))); // 작은원 최소치 / 올림
        } 
        else {
            SR = 1;
        }
              
        answer += (BR - SR + 1);
    }
    
    answer = (answer  + r2 - r1 + 1)*4;
    
    return answer;
}