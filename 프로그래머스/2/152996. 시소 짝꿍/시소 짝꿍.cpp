#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    // 한 사람 당 짝꿍의 몸무게는 최대 세 종류 존재함.
    // 전부 비교해 보는 것은 시간이 너무 오래걸림
    // 무게가 같은 사람들은 짝꿍의 수가 같음
    // 자신과 몸무게가 같은 사람과 이미 비교해 본 몸무게는 확인 해 볼 필요가 없음
    // 같은 몸무게가 아닐 경우, 2배 3배 4배가 중복으로 겹치는 경우의 수는 없음
    // map과 삽입한 기록을 이용해서 카운트를 세고, 2 이상인 경우의 수를 세면 됨
    // 2 이상일 경우 합 공식 사용 n(n-1) / 2 가 짝꿍 수
    // 나온 짝꿍 수는 똑같은 몸무게의 사람이 있을 경우 그 사람수 만큼 반복
    
//     vector<int> isIn(1001, 0);
//     map<int, int> tork;

//     for(int i = 0; i < weights.size(); i++)
//     {
//         if(isIn[weights[i]] == 0)
//         {
//             isIn[weights[i]]++;
//             for(int j = 2; j <= 4; j++)
//             {
//                 tork[weights[i] * j]++;
//             }
//         }
//         else
//         {
//             isIn[weights[i]]++;
//         }
//     }
//     // 중복된 값은 빼고 같은 배수를 갖는 수의 수를 구함
    
//     map<int, int>::iterator iter;
//     for(iter = tork.begin(); iter != tork.end(); iter++)
//     {
//         // 같은 배수를 갖는 수가 2개 이상일 경우 각 수들은 서로가 서로의 짝꿍임
//         // 짝꿍은 쌍방통행임으로 nC2의 경우의수를 가짐
//         // 중복된 수가 있었을 경우, 자신과 같은 수가 가진 짝꿍의 수를 해당 중복 수도 가지게 됨
//         if(iter->second >= 2)
//         {
//             // ((iter->second * (iter->second - 1)) / 2) // 현재 짝꿍 경우의 수
//             int dup = 0;
//             long long count = iter->second;
//             long long dupdup = 0;
//             if(isIn[iter->first / 2] > 1)
//             {
//                 dup = isIn[iter->first / 2] - 1;
//                 count += dup;
//                 dupdup += (long long)(isIn[iter->first / 2] * (isIn[iter->first / 2] - 1)) / 2;
//                 //answer += ((iter->second * (iter->second - 1)) / 2) * dup; // 중복 수만큼 반복
//             }
//             if(isIn[iter->first / 3] > 1)
//             {
//                 dup = isIn[iter->first / 3] - 1;
//                 count += dup;
//                 dupdup += (long long)(isIn[iter->first / 3] * (isIn[iter->first / 3] - 1)) / 2;
//                 //answer += ((iter->second * (iter->second - 1)) / 2) * dup; // 중복 수만큼 반복
//             }
//             if(isIn[iter->first / 4] > 1)
//             {
//                 dup = isIn[iter->first / 4] - 1;
//                 count += dup;
//                 dupdup += (long long)(isIn[iter->first / 4] * (isIn[iter->first / 4] - 1)) / 2;
//                 //answer += ((iter->second * (iter->second - 1)) / 2) * dup; // 중복 수만큼 반복
//             }
            
//             answer += (long long)((count * (count - 1)) / 2);
//             answer -= dupdup;
//             //answer += ((iter->second * (iter->second - 1)) / 2);
//             // 중복이 /2값 /3값 /4값 모두 있었을 수 있음
//             // 현재는 한 값의 중복 밖에 계산을 안해줌
//             // 중복된 값들은 동일한 수의 짝꿍을 가짐
//         }
//     }
    
//     for(int i = 100; i < isIn.size(); i++)
//     {
//         if(isIn[i] > 1)
//         {
//             answer += (long long)(isIn[i] * (isIn[i] - 1)) / 2;
//         }
//     }
    
    // 2 : 3, 2 : 4, 3 : 4 비율이 성립할 경우 짝꿍임
    // 기준 수를 2로 나누고 3배한 수, 2배한 수, 3으로 나누고 4배한 수의 숫자가 짝꿍의 수
    map<long long, long long> m;
    for(int i = 0; i < weights.size(); i++)
    {
        m[weights[i]]++;
    }
    // 각 몸무게 인원 수 기록
    
    for(int i = 0; i < weights.size(); i++)
    {
        if(weights[i] % 2 == 0)
        {
            int now = (weights[i] / 2) * 3;
            answer += m[now];
        }
        if(weights[i] % 3 == 0)
        {
            int now = (weights[i] / 3) * 4;
            answer += m[now];
        }
        int now = weights[i] * 2;
        answer += m[now];
    }
    
    for(int i = 100; i < 1001; i++)
    {
        if(m[i] > 1)
        {
            answer += (m[i] * (m[i] - 1)) / 2;
        }
    }
    
    return answer;
}