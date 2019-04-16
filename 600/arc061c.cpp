#include "bits/stdc++.h"
using namespace std;

typedef pair<int, int> P;

map<int, vector<int> >m[101010];
map<int, int>flg[101010];
int ans[101010];

int main(){

    for(int i = 0; i < 101010; i++)ans[i] = 101010;

    int N, M;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int p, q, c;
        cin >> p >> q >> c;
        m[p][c].push_back(q);
        m[q][c].push_back(p);
    }
    priority_queue<P, vector<P>, greater<P> >Q;
    ans[1] = 0;
    Q.push(P(1, 1));
    while(!Q.empty()){
        int p = Q.top().second;
        Q.pop();
        for(auto it = m[p].begin(); it != m[p].end(); it++){
            int c = (*it).first;
            stack<int>S;
            S.push(p);
            flg[p][c] = 1;
            while(!S.empty()){
                int s = S.top();
                S.pop();
                if(ans[s] == 101010){
                    ans[s] = ans[p] + 1;
                    Q.push(P(ans[s], s));
                }
                for(int i = 0; i < m[s][c].size(); i++){
                    int nxt = m[s][c][i];
                    if(flg[nxt][c] == 0){
                        S.push(nxt);
                        flg[nxt][c] = 1;
                    }
                }
            }
        }
    }    
    if(ans[N] == 101010)cout << "-1" << endl;
    else cout << ans[N] << endl;

    return 0;
}