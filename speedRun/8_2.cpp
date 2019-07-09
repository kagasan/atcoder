#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

int main(){

    vector<ll>tail(101010, 114514);
    tail[0] = -114514;
    ll N, ans = 0;
    cin >> N;
    for(ll i = 0; i < N; i++){
        ll a;
        cin >> a;
        ll ok = 0, ng = N;
        while(ok + 1 < ng){
            ll p = (ok + ng) / 2;
            if(tail[p] > a)ng = p;
            else ok = p;
        }
        tail[ok + 1] = a;
        ans = max(ans, ok + 1);
    }
    cout << ans << endl;

    return 0;
}
