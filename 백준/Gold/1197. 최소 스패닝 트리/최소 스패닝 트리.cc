#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> t;

static vector<int> U;
void Union(int a, int b);
int Find(int a);
bool compare(t a, t b);

int main()
{
    //가중치는 int 범위 안에 들어옴
    int V, E;
    cin >> V >> E;

    vector<t> N;

    for(int i = 0; i <= V; i++)
    {
        U.push_back(i);
    }

    for(int i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;

        N.push_back(make_tuple(a, b, c));
    }


    sort(N.begin(), N.end(), compare);

    int edge = 0;
    int i = 0;
    int cost = 0;
    while(edge < V - 1)
    {
        int s = get<0>(N[i]);
        int e = get<1>(N[i]);
        int c = get<2>(N[i]);

        if(Find(s) != Find(e))
        {
            Union(s, e);
            cost += c;
            edge++;
        }
        
        i++;
    }

    cout << cost << "\n";
}

bool compare(t a, t b)
{
    if(get<2>(a) >= get<2>(b)) return false;
    else return true;
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    
    if(a != b) U[b] = a;
}

int Find(int a)
{
    if(U[a] == a) return a;
    else return U[a] = Find(U[a]);
}