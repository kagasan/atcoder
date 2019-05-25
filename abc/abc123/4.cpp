#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll>P;
typedef pair<P, P>PP;
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
    priority_queue<PP>Q;
    Q.push(PP(P(A[0] + B[0] + C[0], 0), P(0, 0)));
    map<PP, int>flg;
    for(int i = 0; i < K;){
        PP pp = Q.top();
        Q.pop();
        if(flg[pp])continue;
        flg[pp] = 1;
        i++;
        cout << pp.first.first << endl;
        int a = pp.first.second;
        int b = pp.second.first;
        int c = pp.second.second;
        if(a+1<X)Q.push(PP(P(A[a+1]+B[b]+C[c], a+1), P(b, c)));
        if(b+1<Y)Q.push(PP(P(A[a]+B[b+1]+C[c], a), P(b+1, c)));
        if(c+1<Z)Q.push(PP(P(A[a]+B[b]+C[c+1], a), P(b, c+1)));
    }

    return 0;
}