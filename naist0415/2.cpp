#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int check(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3, double r){
    double abx = x2 - x1;
    double aby = y2 - y1;
    double abz = z2 - z1;
    double acx = x3 - x1;
    double acy = y3 - y1;
    double acz = z3 - z1;
    double AB = sqrt(abx * abx + aby * aby + abz * abz);
    double AC = sqrt(acx * acx + acy * acy + acz * acz);
    double dot = (abx * acx + aby * acy + abz * acz);
    double rad = acos(dot / AB / AC);
    if(dot < 0)return 0;
    if(AC * cos(rad) > AB)return 0;

    double L = AC * sin(rad);
    if(L - r <= 1e-9)return 1;
    return 0;
}

int main(){

    int N, Q;
    cin >> N >> Q;
    double X[50], Y[50], Z[50], R[50];
    ll L[50];
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i] >> Z[i] >> R[i] >> L[i];
    }
    for(int i = 0; i < Q; i++){
        ll ans = 0;
        double x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        double x2, y2, z2;
        cin >> x2 >> y2 >> z2;
        for(int j = 0; j < N; j++){
            int f = check(x1, y1, z1, x2, y2, z2, X[j], Y[j], Z[j], R[j]);
            if(f){
                ans += L[j];
            }
        }
        cout << ans << endl;
    }

    return 0;
}