#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

class hoge{
    public:
    ll sum, a, b, c;
    hoge(ll _sum, ll _a, ll _b, ll _c){
        sum = _sum;
        a = _a;
        b = _b;
        c = _c;
    }
    bool operator < (const hoge &h)const{
        return sum < h.sum;
    }
    ll hash(){
        return a + 10000LL * b + 100000000LL * c;
    }
};

int main(){

    ll X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll>A(X), B(Y), C(Z);
    for(int i = 0; i < X; i++)cin >> A[i];
    for(int i = 0; i < Y; i++)cin >> B[i];
    for(int i = 0; i < Z; i++)cin >> C[i];
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());
    
    priority_queue<hoge>Q;
    map<ll, ll>flg;
    Q.push(hoge(A[0] + B[0] + C[0], 0, 0, 0));
    flg[0] = 1;
    for(ll i = 0; i < K; i++){
        hoge h = Q.top();
        Q.pop();
        cout << h.sum << endl;
        if(h.a + 1 < X){
            h.a++;
            if(flg[h.hash()] == 0){
                flg[h.hash()] = 1;
                Q.push(hoge(A[h.a] + B[h.b] + C[h.c], h.a, h.b, h.c));
            }
            h.a--;
        }
        if(h.b + 1 < Y){
            h.b++;
            if(flg[h.hash()] == 0){
                flg[h.hash()] = 1;
                Q.push(hoge(A[h.a] + B[h.b] + C[h.c], h.a, h.b, h.c));
            }
            h.b--;
        }
        if(h.c + 1 < Z){
            h.c++;
            if(flg[h.hash()] == 0){
                flg[h.hash()] = 1;
                Q.push(hoge(A[h.a] + B[h.b] + C[h.c], h.a, h.b, h.c));
            }
            h.c--;
        }
    }

    return 0;
}