#include <string>
#include <vector>

using namespace std;

int result = 0;

int cola(int a, int b, int n)
{
    if(n != 0) cola(a, b, n);
}

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n != 0)
    {
        if(n < a) break;
        int re = (n / a) * b;
        n = re + n % a;
        answer += re;
    }
    
    return answer;
}