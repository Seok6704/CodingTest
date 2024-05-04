#include <iostream>
#include <vector>

using namespace std;

static vector<int> city;
void Union(int a, int b);
int Find(int a);

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i <= n; i++)
    {
        city.push_back(i);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <=n; j++)
        {
            int a;
            cin >> a;

            if(a == 1)
            {
                Union(i, j);
            }
        }
    }

    vector<int> answer;
    for(int i = 0; i < m; i++)
    {
        int a;
        cin >> a;

        answer.push_back(Find(a));
    }

    int start = answer[0];
    for(int i = 0; i < answer.size(); i++)
    {
        if(start != answer[i])
        {
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if(a != b) city[b] = city[a];
}

int Find(int a)
{
    if(a == city[a]) return a;
    else return city[a] = Find(city[a]);
}