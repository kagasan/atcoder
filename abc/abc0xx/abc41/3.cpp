#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

typedef pair<ll, ll>P;

int main(){
    
    ll N;
    cin >> N;
    vector<P>vec;
    for(ll i = 0; i < N; i++){
        ll t;
        cin >> t;
        vec.push_back(P(-t, i + 1));
    }
    sort(vec.begin(), vec.end());
    for(ll i = 0; i < N; i++)cout << vec[i].second << endl;

    return 0;
}
