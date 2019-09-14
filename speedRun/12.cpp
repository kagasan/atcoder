#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    vector<ll>a(N+1, 0), p(N+1, 0);
    for(ll i = 1; i <= N; i++){
        cin >> a[i];
        p[a[i]] = i;
    }
    for(ll i = 1; i <= N; i++){
        if(a[i] == i)continue;
        ll j = p[i];
        swap(a[i], a[j]);
        p[a[i]] = i;
        p[a[j]] = j;
        N--;
    }
    Say(N % 2 == 0, "YES", "NO");

    return 0;
}