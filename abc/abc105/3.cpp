#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N;
    cin >> N;
    string s = "";
    while(N){
        ll r = N % 2;
        if(r < 0)r += 2;
        N = (N - r) / (-2);
        s += (char)('0' + r);
    }
    reverse(s.begin(), s.end());
    if(s == "")s = "0";
    cout << s << endl;

    return 0;
}