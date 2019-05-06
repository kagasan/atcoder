#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

class Tree{
    public:
    vector<vector<int> >edge;
    vector<int>depth;
    Tree(int num){
        edge = vector<vector<int> >(num);
        depth = vector<int>(num, 0);
    }
    void add(int a, int b){
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    void dfs(int x = 0, int from = -1, int dep = 1){
        depth[x] = dep;
        for(int i = 0; i < edge[x].size(); i++){
            int nxt = edge[x][i];
            if(from == nxt)continue;
            dfs(nxt, x, dep + 1);
        }
    }
    int diameter(){
        dfs();
        int mxIdx = 0;
        for(int i = 0; i < depth.size(); i++){
            if(depth[mxIdx] < depth[i]){
                mxIdx = i;
            }
        }
        dfs(mxIdx);
        int mxDepth = 0;
        for(int i = 0; i < depth.size(); i++){
            mxDepth = max(mxDepth, depth[i]);
        }
        return mxDepth;
    }
};
int main(){

    int N;
    cin >> N;
    Tree tree(N);
    for(int i = 1; i < N; i++){
        int a, b;
        cin >> a >> b;
        tree.add(a - 1, b - 1);
    }
    if(tree.diameter() % 3 == 2)cout << "Second" << endl;
    else cout << "First" << endl;

    return 0;
}