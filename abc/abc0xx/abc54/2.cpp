#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){
    
    ll N, M;
    cin >> N >> M;
    char A[55][55];
    char B[55][55];
    for(ll y = 0; y < N; y++){
        for(ll x = 0; x < N; x++){
            cin >> A[y][x];
        }
    }
    for(ll y = 0; y < M; y++){
        for(ll x = 0; x < M; x++){
            cin >> B[y][x];
        }
    }
    for(ll l = 0; ;l++){
        ll r = l + M - 1;
        if(r >= N)break;
        for(ll u = 0; ; u++){
            ll d = u + M - 1;
            if(d >= N)break;
            ll f = 1;
            for(ll y = 0; y < M; y++){
                for(ll x = 0; x < M; x++){
                    if(B[y][x] != A[y + l][x + u])f = 0;
                }
            }
            if(f){
                cout << "Yes" << endl;
                return 0;
            }

        }
    }

    cout << "No" <<endl;
    
    return 0;
}