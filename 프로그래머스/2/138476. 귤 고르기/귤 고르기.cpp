#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    // 귤 크기가 다른 종류의 수를 최소화 해서 담으면 됨
    // 귤의 크기 정보는 필요 없음
    // 크기가 같은 귤을 묶고, 갯수가 많은 크기의 귤부터 순서대로 담아서 채워나나갈 때, 들어가는 종류의 수를 카운트 하면 됨
    vector<int> S;
    S.resize(10000001);
    
    for(int i = 0; i < tangerine.size(); i++)
    {
        S[tangerine[i]]++;
    }
    
    sort(S.begin(), S.end(), greater<>());
    
    for(int i = 0; i < S.size(); i++)
    {
        if(S[i] >= k)
        {
            answer++;
            break;
        }
        else
        {
            k -= S[i];
            answer++;
        }
    }
    
    return answer;
}