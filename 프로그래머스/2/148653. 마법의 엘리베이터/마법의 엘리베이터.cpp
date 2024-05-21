#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    // int 범위를 벗어나는 일은 없음
    // 버튼을 최소한으로 눌러서 0층으로 이동하면 됨
    // 각 자리의 수가 5 이하일 경우, 해당 자리의 수를 누르는게 한 자리수 높여서 누르는 것보다 적게 누르게 됨
    // 현재 있는 층수를 일의 자리수부터 검사를 진행해서, 10으로 나누어떨어지는 수로 변경하면 됨
    int count = 0;
    while(storey > 0)
    {
        int now = storey % 10;
        storey = storey / 10;
        //현재 자리수가 5보다 클 경우 층을 올리는게 이득
        if(now > 5)
        {
            storey += 1; // 층을 올렸으므로, 1 증가
            count += 10 - now; // 층을 올린 횟수만큼 마법의 돌 사용 수 증가
        }
        else if(now < 5) // 현재 자리수가 5보다 작을 경우 층을 내리는게 이득
        {
            count += now; // 층을 내린 횟수만큼 마법의 돌 사용 수 증가
        }
        else // 현재 자리수가 5일 경우, 다음 자리수가 5 이상일 경우 올리는게 이득, 아닐경우 내리는게 이득
        {
            if(storey % 10 >= 5)
            {
                storey += 1; // 층을 올렸으므로, 1 증가
                count += 10 - now; // 층을 올린 횟수만큼 마법의 돌 사용 수 증가
            }
            else
            {
                count += now; // 층을 내린 횟수만큼 마법의 돌 사용 수 증가
            }
        }
    }
    
    return count;
}