#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    int ans = 0, mxTmp = 0;
    for(int i = 0; i < 5; i++){
        int m;
        cin >> m;
        ans += m;
        if(m % 10){
            int tmp = 10 - m % 10;
            ans += tmp;
            mxTmp = max(mxTmp, tmp);
        }
    }
    cout << ans - mxTmp << endl;

    return 0;
}