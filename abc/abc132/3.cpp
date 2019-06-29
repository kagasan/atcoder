#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    ll N;
    cin >> N;
    vector<ll>v(N);
    for(ll i = 0; i < N; i++)cin >> v[i];
    sort(v.begin(), v.end());
    cout << v[N / 2] - v[N / 2 - 1] << endl;

    return 0;
}