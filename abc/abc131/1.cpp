#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Yes(bool Yes){cout << (Yes ? "Yes" : "No") << endl;};
void YES(bool YES){cout << (YES ? "YES" : "NO") << endl;};

int main(){

    string s;
    cin >> s;
    if(s[0] == s[1] || s[1] == s[2] || s[2] == s[3])cout << "Bad" << endl;
    else cout << "Good" << endl;

    return 0;
}