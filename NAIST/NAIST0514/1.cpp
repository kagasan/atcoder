#include <bits/stdc++.h>
using namespace std;

int main(){
    
    for(int m, mn, mx; cin >> m >> mn >> mx;){
        if(m == 0)break;
        vector<int>vec(m);
        for(int i = 0; i < m; i++)cin >> vec[i];
        int n = 0, mxg = 0;
        for(int ok = 0; ok < m; ok++){
            int cnt = 0;
            int okmin = 1919;
            int ngmax = -1919;
            for(int i = 0; i < m; i++){
                if(vec[i] >= vec[ok]){
                    cnt++;
                    okmin = vec[i];
                }
                else ngmax = max(ngmax, vec[i]);
            }
            if(mn <= cnt && cnt <= mx){
                if(okmin - ngmax > mxg){
                    n = cnt;
                    mxg = okmin - ngmax;
                }
                if(okmin - ngmax == mxg){
                    n = max(cnt, n);
                }
            }
        }
        cout << n << endl;
    }
    
    return 0;    
}