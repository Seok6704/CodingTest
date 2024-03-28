#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(int a = 0; a < str.length(); a++)
    {
        cout << str[a] << endl;
    }
    return 0;
}