#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    set<string>S;
    ll N;
    cin >> N;
    for(ll i = 1; i * i <= N; i++){
        if(N % i)continue;
        ll a = N / i;
        ll b = i;
        stringstream s1, s2;
        s1 << a << b;
        s2 << b << a;
        S.insert(s1.str());
        S.insert(s2.str());
    }
    cout << S.size() << endl;

    return 0;
}