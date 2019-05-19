#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll N, K;
    cin >> N >> K;
    map<ll,ll>cnt;
    for(ll i = 1; i <= N; i++){
        ll tmp = 0;
        for(ll I = i;I < K;){
            I += I;
            tmp++;
        }
        cnt[tmp]++;
    }
    double ans = 0;
    for(map<ll, ll>::iterator it = cnt.begin(); it != cnt.end(); it++){
        ll m = (*it).first;
        double tmp = (*it).second;
        for(ll i = 0; i < m; i++){
            tmp *= 0.5;
        }
        ans += tmp;
    }
    printf("%.12f\n", ans / N);

    return 0;
}