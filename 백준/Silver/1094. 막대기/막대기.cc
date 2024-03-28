#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int X;
    cin >> X;

    vector<int> v;

    int now = 64;
    int result = 64;
    v.push_back(now);
    while(result != X)
    {
        if(now / 2 >= X)
        {
            v.pop_back();
            now = now / 2;
            v.push_back(now);
            if(now == X)
            {
                cout << v.size() << "\n";
                return 0;
            }
        }
        else
        {
            if(v.front() > X) v.pop_back();
            now = now / 2;
            v.push_back(now);
            result = 0;
            for(int i = 0; i < v.size(); i++)
            {
                result += v[i];
            }
            if(result > X)
            {
                result -= v[v.size()-1];
                v.pop_back();
            }
        }
        if(now / 2 == 0) break;
    }
    cout << v.size();
}