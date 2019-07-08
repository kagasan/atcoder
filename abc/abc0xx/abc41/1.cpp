#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    string s;
    ll i;
    cin >> s >> i;
    cout << s[i - 1] << endl;

    return 0;
}
