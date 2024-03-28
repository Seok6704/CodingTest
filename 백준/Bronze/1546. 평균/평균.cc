#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c;
    float answer = 0;
    
    cin >> c;

    int p[1000];

    for(int i = 0; i < c; i++)
    {
        cin >> p[i];
    }

    int max = 0;

    for(int i = 0; i < c; i++)
    {
        if(p[i] >= max) max = p[i];
        answer += p[i];
    }

    cout << answer * 100 / max / c << "\n";
}