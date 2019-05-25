#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main(){

    string g;
    int y, m, d;
    while(cin >> g){
        if(g=="#")break;
        cin >> y >> m >> d;
        int hoge = y * 10000 + m * 100 + d;
        if(hoge > 310430){
            cout << "?" << " " << y - 30 << " " << m << " " << d << endl;
        }
        else{
            cout << g << " " << y << " " << m << " " << d << endl;
        }
    }


    return 0;
}