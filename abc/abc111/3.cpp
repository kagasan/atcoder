#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;

int main(){

    ll N;
    cin >> N;
    map<ll, ll>A, B;
    for(ll i = 0; i < N; i++){
        ll v;
        cin >> v;
        if(i & 1)A[v]++;
        else B[v]++;
    }
    vector<P>av, bv;
    av.push_back(P(N / 2, -1));
    bv.push_back(P(N / 2, -2));
    for(map<ll, ll>::iterator it = A.begin(); it != A.end(); it++){
        av.push_back(P(N/2-(*it).second, (*it).first));
    }
    sort(av.begin(), av.end());
    for(map<ll, ll>::iterator it = B.begin(); it != B.end(); it++){
        bv.push_back(P(N/2-(*it).second, (*it).first));
    }
    sort(bv.begin(), bv.end());
    P a0 = av[0];
    P a1 = av[1];
    P b0 = bv[0];
    P b1 = bv[1];
    ll ans = N;
    if(a0.second != b0.second)ans = min(ans, a0.first + b0.first);
    if(a1.second != b0.second)ans = min(ans, a1.first + b0.first);
    if(a0.second != b1.second)ans = min(ans, a0.first + b1.first);
    if(a1.second != b1.second)ans = min(ans, a1.first + b1.first);
    cout << ans << endl;

    return 0;
}