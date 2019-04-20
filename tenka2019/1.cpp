#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int B[201010];
int W[201010];

int b(int l, int r){
    return B[r] - B[l-1];
}
int w(int l, int r){
    return W[r] - W[l-1];
}

int main(){

    int N;
    cin >> N;
    int ans = N;
    for(int i = 2; i <= N + 1; i++){
        char c;
        cin >> c;
        B[i] = B[i - 1];
        W[i] = W[i - 1];
        if(c == '#')B[i]++;
        else W[i]++;
    }
    B[N + 2] = B[N + 1];
    W[N + 2] = W[N + 1];
    for(int i = 1; i <= N + 1; i++){
        int tmp = b(1, i) + w(i + 1, N + 2);
        ans = min(ans, tmp);
    }
    cout << ans << endl;

    return 0;
}