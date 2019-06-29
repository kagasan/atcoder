#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N, K;
    cin >> N >> K;
    vector<double>w(N), p(N);
    for(ll i = 0; i < N; i++){
        cin >> w[i] >> p[i];
    }
    double ok = 0, ng = 101;
    for(ll q = 0; q < 1000; q++){
        double x = (ok + ng) / 2;
        vector<double>v(N);
        for(ll i = 0; i < N; i++){
            v[i] = (x - p[i]) * w[i] * 0.01;
        }
        sort(v.begin(), v.end());
        double sum = 0;
        for(ll i = 0; i < K; i++){
            sum += v[i];
        }
        if(sum > 0)ng = x;
        else ok = x;
    }
    printf("%.9f\n", ok);

    return 0;
}
