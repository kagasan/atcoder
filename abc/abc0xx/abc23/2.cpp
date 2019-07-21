#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    string s = "b";
    map<string, ll>flg;
    for(ll i = 1; i < 100; i++){
        flg[s] = i;
        if(i % 3 == 1)s = "a" + s + "c";
        if(i % 3 == 2)s = "c" + s + "a";
        if(i % 3 == 0)s = "b" + s + "b";
    }
    ll N;
    cin >> N;
    cin >> s;
    cout << flg[s] - 1 << endl;
    
    return 0;
}