#include <iostream>
#include <map>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    map<string, bool> m;

    for(int i = 0; i < N; i++)
    {
        string s;
        cin >> s;

        m.insert(make_pair(s, true));
    }

    int count = 0;
    for(int i = 0; i < M; i++)
    {
        string s;
        cin >> s;

        if(m[s]) count++;
    }

    cout << count;



}