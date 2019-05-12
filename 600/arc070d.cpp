#include "bits/stdc++.h"
using namespace std;

int A[5050];
int L[5050][5050];
int R[5050][5050];

int main(){
    
    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++)cin >> A[i];
    L[0][0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= 5000; j++){
            L[i][j] |= L[i - 1][j];
            if(j - A[i] >= 0)L[i][j] |= L[i - 1][j - A[i]];
        }
    }
    R[N + 1][0] = 1;
    for(int i = N; i >= 1; i--){
        for(int j = 0; j <= 5000; j++){
            R[i][j] |= R[i + 1][j];
            if(j - A[i] >= 0)R[i][j] |= R[i + 1][j - A[i]];
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(A[i] >= K)continue;
        int f = 1;
        set<int>S;
        for(int r = 0; r < K; r++)if(R[i + 1][r])S.insert(r);
        S.insert(K);
        for(int l = 0; l < K; l++){
            if(L[i - 1][l] == 0)continue;
            int mn = *S.lower_bound(K - A[i] - l);
            if(mn < K - l){
                f = 0;
                break;
            }
        }
        if(f)ans++;
    }
    cout << ans << endl;

    return 0;
}