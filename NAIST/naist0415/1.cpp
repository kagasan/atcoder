#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    for(int N, L, R; cin >> N >> L >> R;){
        if(N == 0)break;
        vector<int>A(N + 1);
        for(int i = 1; i <= N; i++)cin >> A[i];
        int ans = 0;
        for(int x = L; x <= R; x++){
            int flg = -1;
            for(int i = 1; i <= N; i++){
                if(x % A[i] == 0){
                    if(i & 1)flg = 1;
                    else flg = 0;
                    break;
                }
            }
            if(flg < 0){
                if(N & 1)flg = 0;
                else flg = 1;
            }
            if(flg)ans++;
        }
        cout << ans << endl;
    }

    return 0;
}