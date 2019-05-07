#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int>P;

int main(){
    for(int n; cin >> n, n;){
        vector<vector<P> >e(n + 1);
        vector<int>path(n + 1);
        for(int i = 2; i <= n; i++)cin >> path[i];
        for(int i = 2; i <= n; i++){
            ll w;
            cin >> w;
            e[i].push_back(P(path[i], w));
            e[path[i]].push_back(P(i, w));
        }
        ll ans = 0;
        ll tmp = 0;
        int idx = -1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < e[i].size(); j++){
                int to = e[i][j].first;
                if(e[i].size() == 1 || e[to].size() == 1){
                    ans += e[i][j].second;
                    e[i][j].first = -1;
                }
                else{
                    tmp += e[i][j].second;
                    idx = i;
                }
            }
        }
        ans /= 2;
        if(idx < 0){
            cout << ans << endl;
            continue;
        }
        tmp /= 2;
        ans += 3 * tmp;
        vector<ll>depth(n + 1);
        stack<ll>To, From, Depth;
        To.push(idx); From.push(-1); Depth.push(0);
        int mxIdx = idx;
        while(!To.empty()){
            ll x = To.top(); To.pop();
            ll from = From.top(); From.pop();
            ll dep = Depth.top(); Depth.pop();
            depth[x] = dep;
            if(depth[x] > depth[mxIdx]){
                mxIdx = x;
            }
            for(int i = 0; i < e[x].size(); i++){
                int to = e[x][i].first;
                if(to < 0)continue;
                if(to == from)continue;
                To.push(to); From.push(x); Depth.push(dep + e[x][i].second);
            }
        }
        To.push(mxIdx); From.push(-1); Depth.push(0);
        while(!To.empty()){
            ll x = To.top(); To.pop();
            ll from = From.top(); From.pop();
            ll dep = Depth.top(); Depth.pop();
            depth[x] = dep;
            if(depth[x] > depth[mxIdx]){
                mxIdx = x;
            }
            for(int i = 0; i < e[x].size(); i++){
                int to = e[x][i].first;
                if(to < 0)continue;
                if(to == from)continue;
                To.push(to); From.push(x); Depth.push(dep + e[x][i].second);
            }
        }
        ans -= depth[mxIdx];
        cout << ans << endl;
    }
    return 0;
}