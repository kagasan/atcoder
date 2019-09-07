#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll D;
    cin >> D;
    stringstream ss;
    ss << D * 108;
    string s;
    ss >> s;
    for(ll i = 0; i < s.size(); i++){
        cout << s[i];
        if(i + 3 == s.size())cout << ".";
    }
    cout << endl;

    return 0;
}