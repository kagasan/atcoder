#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;
typedef pair<ll, P>PP;

ll path[101][101];
ll flg[101];
ll tim[101][101];
void init(){
    for(ll i = 0; i < 101; i++){
        for(ll j = 0; j < 101; j++){
            path[i][j] = 1000;
            tim[i][j] = 1145141919;
        }
        flg[i] = 0;
    }
}

int main(){
    
    for(ll N, M, L, K, A, H; cin >> N >> M >> L >> K >> A >> H, N;){
        init();
        for(ll i = 0; i < L; i++){
            ll x;
            cin >> x;
            flg[x] = 1;
        }
        for(ll i = 0; i < K; i++){
            ll x, y, t;
            cin >> x >> y >> t;
            path[x][y] = t;
            path[y][x] = t;   
        }
        priority_queue<PP, vector<PP>, greater<PP> >Q;
        Q.push(PP(0, P(A, M)));
        ll help = 1;
        while(!Q.empty() && help){
            ll t = Q.top().first;
            ll pos = Q.top().second.first;
            ll m = Q.top().second.second;
            Q.pop();
            if(tim[pos][m] <= t)continue;
            // cout << t << " " << pos << " " << m << endl;
            tim[pos][m] = t;
            if(pos == H){
                cout << t << endl;
                help = 0;
                break;
            }
            for(ll i = 0; i < N; i++){
                if(pos == i && flg[i] && m < M){
                    if(tim[i][m + 1] > t + 1){
                        Q.push(PP(t + 1, P(i, m + 1)));
                    }
                }
                if(path[pos][i] <= m){
                    if(tim[i][m - path[pos][i]] > t + path[pos][i]){
                        Q.push(PP(t + path[pos][i], P(i, m - path[pos][i])));
                    }
                }
            }
        }
        if(help)cout << "Help!" << endl;
    }
    
    return 0;    
}