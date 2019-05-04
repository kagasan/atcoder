#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

// あるノードを選び、根として、葉を全て削除する
// 最後の1つを選んだ人の勝ちt

int N;
vector<int>path[202020];
int flg[202020];
int mxx = 0;
void dfs(int x, int val){
    flg[x] = val;
    if(flg[mxx] < flg[x])mxx = x;
    for(int i = 0; i < path[x].size(); i++){
        int nxt = path[x][i];
        if(flg[nxt])continue;
        dfs(nxt, val + 1);
    }
}

int dp[202020];

int main(){

    cin >> N;
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    for(int i = 0; i < N; i++)flg[i] = 0;
    dfs(0, 1);
    for(int i = 0; i < N; i++)flg[i] = 0;
    dfs(mxx, 1);
    int depth = flg[mxx];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 1; i <= depth; i++){
        if(dp[i] == 0){
            if(dp[i - 1] == 1 && dp[i - 2] == 1){
                dp[i] = 2;
            }
            else{
                dp[i] = 1;
            }
        }
    }    
    if(dp[depth] == 1)cout << "First" << endl;
    else cout << "Second" << endl;

    return 0;
}