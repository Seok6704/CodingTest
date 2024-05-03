#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<bool> p;
    p.resize(10000001, true);
    p[0] = false;
    p[1] = false;

    //팰린드롬 = 수를 반전시켜도 이전 수와 똑같이 생긴 수 중 소수인 수
    // 팰린드롬 검출을 위해서는 수를 반전시킬 필요가 있음
    // 굳이 반전까지 안하고 맨 앞과 맨 뒤 숫자를 비교해 나가면서 가운데 수가 나오기 전까지 일치하는지 검사하면
    // 검사를 빨리 끝낼 수 있을듯?

    for(int i = 2; i < p.size(); i++)
    {
        if(p[i])
        {
            for(int j = i + i; j <= p.size(); j += i)
            {
                p[j] = false;
            }
        }
    }

    bool find = true;
    for(int i = n; i <= 10000001; i++)
    {
        if(p[i])
        {
            string temp = to_string(i);
            int s = 0;
            int e = temp.length() - 1;
            while(s < e)
            {
                if(temp[s] == temp[e])
                {
                    s++;
                    e--;
                }
                else
                {
                    find = false;
                    break;
                }
            }
            if(find)
            {
                cout << i << "\n";
                break;
            }
            else find = true;
        }
    }
}