#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

ll N, A, B, C, D;
char s[202020];
ll dpA[202020];
ll dpB[202020];
ll flg = 0;

int main(){

    cin >> N >> A >> B >> C >> D;
    for(ll i = 1; i <= N; i++)cin >> s[i];
    dpA[A] = 1;
    for(ll i = 1; i <= N; i++){
        if(dpA[i]){
            if(s[i + 1] == '.')dpA[i + 1] = 1;
            if(s[i + 2] == '.')dpA[i + 2] = 1;
        }
    }
    dpB[B] = 1;
    for(ll i = 1; i <= N; i++){
        if(dpB[i]){
            if(s[i + 1] == '.')dpB[i + 1] = 1;
            if(s[i + 2] == '.')dpB[i + 2] = 1;
        }
    }
    if(C < D)flg = 1;
    else{
        for(ll b = B; b <= D; b++){
            if(s[b - 1] == '.' && s[b] == '.' && s[b + 1] == '.')flg = 1;
        }
    }
    if(flg && dpA[C] && dpB[D])cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
