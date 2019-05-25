#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    int N;
    cin >> N;
    vector<int>H(N);
    int ans = 0;
    for(int i = 0; i < N; i++){
        cin >> H[i];
        int flg = 1;
        for(int j = 0; j < i; j++){
            if(H[j] > H[i])flg = 0;
        }
        if(flg)ans++;
    }
    cout << ans << endl;


    return 0;
}