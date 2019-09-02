#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
void Say(bool say, string a = "Yes", string b = "No"){cout << (say ? a : b) << endl;};

typedef pair<ll, ll>P;

ll N;
ll lst[1010];
ll cnt[1010];
ll A[1010][1010];

ll solve(){
    cin >> N;    
    for(ll i = 1; i <= N; i++){
        for(ll j = 0; j < N - 1; j++){
            scanf("%lld", &A[i][j]);
        }
    }
    ll day = 0;
    for(ll ct = 0; ct < N * (N - 1) / 2;){
        day++;
        ll flg = 0;
        for(ll i = 1; i <= N; i++){
            if(lst[i] == day)continue;
            if(cnt[i] == N - 1)continue;
            ll to = A[i][cnt[i]];
            if(lst[to] == day)continue;
            if(A[to][cnt[to]] != i)continue;
            ct++;
            flg = 1;
            lst[i] = day;
            lst[to] = day;
            cnt[i]++;
            cnt[to]++;
        }
        if(flg == 0)return -1;
    }
    return day;
}

int main(){

    cout << solve() << endl;

    return 0;
}