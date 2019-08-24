#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

ll path[555][555];
ll cnt[555];
ll done = 0;

int main(){

    ll N;
    cin >> N;
    for(ll i = 1; done < N; i++){
        vector<ll>flg(555, 0);
        for(ll j = 1; j <= N; j++){
            if(cnt[j] == N - 1)continue;
            flg[j] = 1;
            queue<ll>Q;
            Q.push(j);
            while(!Q.empty()){
                ll idx = Q.front();
                Q.pop();
                for(ll k = 1; k <= N; k++){
                    if(path[idx][k])continue;
                    if(flg[k])continue;
                    if(flg[idx] == 1)flg[k] = 2;
                    else flg[k] = 1;
                    cout << "p" << " " << idx << " -> " << k << endl;
                    Q.push(k);
                    path[idx][k] = i;
                    path[k][idx] = i;
                    cnt[idx]++;
                    cnt[k]++;
                    if(cnt[idx] == N - 1)done++;
                    if(cnt[k] == N - 1)done++;
                    break;
                }
            }
            Q.push(j);
            while(!Q.empty()){
                ll idx = Q.front();
                Q.pop();
                for(ll k = 1; k <= N; k++){
                    if(path[idx][k])continue;
                    if(flg[k])continue;
                    if(flg[idx] == 1)flg[k] = 2;
                    else flg[k] = 1;
                    Q.push(k);
                    path[idx][k] = i;
                    path[k][idx] = i;
                    cnt[idx]++;
                    cnt[k]++;
                    if(cnt[idx] == N - 1)done++;
                    if(cnt[k] == N - 1)done++;
                    break;
                }
            }
        }
        for(ll j = 1; j <= N; j++){
            for(ll k = 1; k <= N; k++){
                if(path[j][k])continue;
                if(flg[j] == flg[k])continue;
                path[j][k] = i;
                path[k][j] = i;
                cnt[j]++;
                cnt[k]++;
                if(cnt[j] == N - 1)done++;
                if(cnt[k] == N - 1)done++;
            }
        }
    }
    for(ll i = 1; i < N; i++){
        for(ll j = i + 1; j <= N; j++){
            cout << path[i][j];
            if(j < N)cout << " ";
            else cout << endl;
        }
    }
    
    return 0;
}