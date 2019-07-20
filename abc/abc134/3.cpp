#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

typedef pair<ll, ll>P;

int main(){

    ll N;
    cin >> N;
    vector<P>v;
    for(ll i = 0; i < N; i++){
        ll a;
        cin >> a;
        v.push_back(P(a, i));
    }
    sort(v.begin(), v.end(), greater<P>());
    for(ll i = 0; i < N; i++){
        if(v[0].second == i)cout << v[1].first << endl;
        else cout << v[0].first << endl;
    }

    return 0;
}