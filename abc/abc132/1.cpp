#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    Say(s[0] == s[1] && s[1] != s[2] && s[2] == s[3]);

    return 0;
}