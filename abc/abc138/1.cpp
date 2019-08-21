#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll a;
    string s;
    cin >> a >> s;
    if(a >= 3200)cout << s << endl;
    else cout << "red" << endl;

    return 0;
}