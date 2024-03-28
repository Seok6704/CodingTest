#include <iostream>
#include <map>

using namespace std;

int main()
{
    int s, p;

    map<char, int> key;

    cin >> s >> p;

    string dna;

    cin >> dna;

    int A, C, G, T;
    cin >> A >> C >> G >> T;

    key.insert(make_pair('A', 0));
    key.insert(make_pair('C', 0));
    key.insert(make_pair('G', 0));
    key.insert(make_pair('T', 0));

    int count = 0;

    for(int i = 0; i < p; i++)
    {
        key[dna[i]]++;
    }
    if(key['A'] >= A && key['C'] >= C && key['G'] >= G && key['T'] >= T) count++;

    int i = 1;

    while(i <= dna.length() - p)
    {
        key[dna[i - 1]]--;
        key[dna[i + p - 1]]++;
        if(key['A'] >= A && key['C'] >= C && key['G'] >= G && key['T'] >= T) count++;
        i++;
    }

    cout << count << "\n";
}