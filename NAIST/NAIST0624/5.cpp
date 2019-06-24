#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

typedef pair<ll, ll>P;
typedef pair<P, P>PP;


ll dy[5] = {0, 1, 0, -1, 0};
ll dx[5] = {1, 0, -1, 0, 0};
ll change[5][5] = {
    {0, 1, 2, 3, 4},
    {1, 2, 3, 0, 4},
    {2, 3, 0, 1, 4},
    {3, 0, 1, 2, 4},
    {4, 4, 4, 4, 4}
};

ll mp[33][33];
ll mn[33][33][5];
ll c[5];
void init(){
    for(ll y = 0; y < 33; y++){
        for(ll x = 0; x < 33; x++){
            mp[y][x] = -1;
            for(ll i = 0; i < 5; i++){
                mn[y][x][i] = -1145141919;
            }
        }
    }

}

int main(){
    
    for(ll w, h; cin >> w >> h, w;){
        init();
        for(ll y = 1; y <= h; y++){
            for(ll x = 1; x <= w; x++){
                cin >> mp[y][x];
                for(ll i = 0; i < 5; i++){
                    mn[y][x][i] = 1145141919;
                }
            }
        }
        for(ll i = 0; i < 4; i++)cin >> c[i];
        priority_queue<PP, vector<PP>, greater<PP> >Q;
        Q.push(PP(P(0, 1), P(1, 0)));
        while(!Q.empty()){
            ll cost = Q.top().first.first;
            ll x = Q.top().first.second;
            ll y = Q.top().second.first;
            ll d = Q.top().second.second;
            Q.pop();
            if(mp[y][x] == -1)continue;
            if(mn[y][x][d] <= cost)continue;
            mn[y][x][d] = cost;            
            if(y == h && x == w){
                cout << cost << endl;
                break;
            }
            for(ll i = 0; i < 4; i++){
                ll nxtC = cost;
                if(mp[y][x] != i)nxtC += c[i];
                ll dd = change[d][i];
                ll yy = y + dy[dd];
                ll xx = x + dx[dd];
                if(mn[yy][xx][dd] > nxtC){
                    Q.push(PP(P(nxtC, xx), P(yy, dd)));
                }
            }
        }
    }
    
    return 0;    
}