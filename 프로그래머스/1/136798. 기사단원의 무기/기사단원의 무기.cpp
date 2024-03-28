#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i <= number; ++i)
    {
        int num = 0;
        for(int j = 1; j <= sqrt(i); ++j)
        {
            if(i % j == 0)
            {
                if((i / j) * (i / j) == i)
                    num += 1;
                else num += 2;
            }
        }
        if(num > limit) num = power;
        answer += num;
    }
    
    return answer;
}