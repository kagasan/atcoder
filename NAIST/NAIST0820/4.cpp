#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;

ll flg[101010];

int main(){

    ll N;
    cin >> N;
    vector<P>v;
    for(ll i = 1; i <= N; i++){
        ll a;
        cin >> a;
        v.push_back(P(a, i));
    }
    v.push_back(P(0, -1));
    sort(v.begin(), v.end(), greater<P>());
    ll ans = 0;
    ll tmp = 0, lst = 1000000007;
    for(ll i = 0; i < v.size(); i++){
        if(v[i].first != lst)ans = max(ans, tmp);
        lst = v[i].first;
        if(v[i].first == 0)break;
        ll idx = v[i].second;
        flg[idx] = 1;
        if(flg[idx - 1] == 1 && flg[idx + 1] == 1)tmp--;
        if(flg[idx - 1] == 0 && flg[idx + 1] == 0)tmp++;
    }
    cout << ans << endl;

    return 0;    
}