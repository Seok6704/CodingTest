#include <iostream>
#include <vector>

static long F[21];

using namespace std;

int main()
{
    int N;
    cin >> N;

    int P;
    cin >> P;

    long K = 1;
    vector<long> V;
    V.resize(N + 1);
    
    F[0] = 1;

    vector<bool> Visit;
    Visit.resize(N + 1, false);

    vector<int> answer;

    for(int i = 1; i <= N; i++)
    {
        F[i] = F[i - 1] * i;
    }

    if(P == 1)
    {
        cin >> K;

        for(int i = 1; i <= N; i++)
        {
            int cnt = 1;
            for(int j = 1; j <= N; j++)
            {
                if(Visit[j]) continue;

                if(K <= cnt * F[N - i])
                {
                    K -= ((cnt - 1) * F[N - i]);
                    answer.push_back(j);
                    Visit[j] = true;
                    break;
                }
                cnt++;
            }
        }

        for(int i = 0; i < answer.size(); i++)
        {
            cout << answer[i] << " ";   
        }
    }
    else
    {
        K = 1;

        for(int i = 1; i <= N; i++)
        {
            cin >> V[i];

            long cnt = 0;

            for(int j = 1; j < V[i]; j++)
            {
                if(Visit[j] == false) cnt++;
            }
            K += cnt * F[N - i];
            Visit[V[i]] = true;
        }

        cout << K << "\n";

    }

    // 순열의 순서와 순열을 구하는 문제
    // 모든 순열은 1부터 N까지의 숫자를 가지게 됨
    // 자릿수에 따라 순열의 경우의 수가 N!로 변함
    // 1 3 2 4 -> 4! 총 24개의 경우의 수 중 1로 시작하는 경우의 수 1 ~ 6번 3으로 시작하는 경우 3 ~ 4번 그 뒤가 2인 경우 3번이므로 3번째 경우의 수
}