#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> t;
void preO(int s);
void inO(int s);
void posO(int s);

int main()
{
    int N;
    cin >> N;

    t.resize(N);

    for(int i = 0; i < N; i++)
    {
        char n, l, r;
        cin >> n >> l >> r;

        int node, left, right;
        node = n - 'A';
        if(l == '.') left = -1;
        else left = l - 'A';
        if(r == '.') right = -1;
        else right = r - 'A';

        t[node].push_back(left);
        t[node].push_back(right);
    }
    preO(0);
    cout << "\n";
    inO(0);
    cout << "\n";
    posO(0);
    cout << "\n";
}

void preO(int s)
{
    if(s == -1) return;

    cout << (char)(s + 'A');
    preO(t[s][0]);
    preO(t[s][1]);
}

void inO(int s)
{
    if(s == -1) return;

    inO(t[s][0]);
    cout << (char)(s + 'A');
    inO(t[s][1]);
}

void posO(int s)
{
    if(s == -1) return;

    posO(t[s][0]);
    posO(t[s][1]);
    cout << (char)(s + 'A');
}