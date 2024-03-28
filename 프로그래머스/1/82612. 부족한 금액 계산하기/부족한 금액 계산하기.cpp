#include <iostream>

using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;
    long long sum = 0;
    
    for(int i = 1; i <= count; ++i)
    {
        sum += i;
    }
    
    long long result = sum * price;
    
    if(result > money) answer = result - money;
    else answer = 0;

    return answer;
}