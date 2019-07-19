#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

typedef pair<ll, ll>P;
bool check(P a, P b){
    return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second) < 400;
}

vector<P>coins[555][555];

int main(){
    
    ll N, ans = 0;
    cin >> N;
    for(ll i = 0; i < N; i++){
        ll x, y;
        cin >> x >> y;
        x += 100;
        y += 100;
        P p(x, y);
        ll xidx = x / 40;
        ll yidx = y / 40;
        ll flg = 1;
        for(ll j = -1; j <= 1; j++){
            for(ll k = -1; k <= 1; k++){
                ll X = xidx + j;
                ll Y = yidx + k;
                for(ll l = 0; l < coins[X][Y].size(); l++){
                    if(check(coins[X][Y][l], p))flg = 0;
                }
            }
        }
        if(flg){
            ans++;
            coins[xidx][yidx].push_back(p);
        }
    }
    cout << ans << endl;

    return 0;
}