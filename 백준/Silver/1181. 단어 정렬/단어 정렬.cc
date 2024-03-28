#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Compare(string a, string b)
{
    if(a.length() > b.length()) return false;
    else if(a.length() < b.length()) return true;
    else if(a.compare(b) > 0) return false;
    return true;
}

int main()
{
    int N;
    cin >> N;

    vector<string> v;
    for(int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        if(find(v.begin(), v.end(), a) == v.end()) v.push_back(a);
    }

    sort(v.begin(), v.end(), Compare);


    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << "\n";
    }

    return 0;
}