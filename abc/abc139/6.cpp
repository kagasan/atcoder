#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

typedef pair<ll, ll>P;
typedef pair<double, P>DP;

int main(){
    ll N;
    cin >> N;

    vector<DP>v;
    for(ll i = 0; i < N; i++){
        ll x, y;
        cin >> x >> y;
        v.push_back(DP(atan2(y, x), P(x, y)));
    }
    sort(v.begin(), v.end());
    double ans = 0;
    for(ll i = 0; i < N; i++){
        for(ll j = 0; j < N; j++){
            ll x = 0, y = 0;
            for(ll k = i; ;k = (k + 1) % N){
                x += v[k].second.first;
                y += v[k].second.second;
                if(k == j)break;
            }
            ans = max(ans, hypot(x, y));
        }
    }
    printf("%.10f\n", ans);

    return 0;
}