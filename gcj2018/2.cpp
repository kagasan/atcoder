#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    ll T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        cout << "Case #" << t << ": ";
        int N;
        cin >> N;
        vector<int>v(N), a[2];
        for(int i = 0; i < N; i++){
            scanf("%d", &v[i]);
            a[i & 1].push_back(v[i]);
        }
        sort(v.begin(), v.end());
        sort(a[0].begin(), a[0].end());
        sort(a[1].begin(), a[1].end());
        vector<int>b;
        for(int i = 0, j = 0, k = 0; i < N; i++){
            if((i & 1) == 0){
                if(j < a[0].size()){
                    b.push_back(a[0][j]);
                    j++;
                }
            }
            else{
                if(k < a[1].size()){
                    b.push_back(a[1][k]);
                    k++;
                }
            }
        }
        int ans = -1;
        for(int i = 0; i < N && ans < 0; i++){
            if(v[i] != b[i])ans = i;
        }
        if(ans < 0)cout << "OK" << endl;
        else cout << ans << endl;
    }

    return 0;
}