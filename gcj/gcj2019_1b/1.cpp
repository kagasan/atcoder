#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

void solve(int t){
    int P, Q;
    cin >> P >> Q;
    set<int>xSet, ySet;
    xSet.insert(0); xSet.insert(Q);
    ySet.insert(0); ySet.insert(Q);
    map<int, int>N, S, E, W;
    for(int i = 0; i < P; i++){
        int x, y;
        char d;
        cin >> x >> y >> d;
        for(int j = -1; j <= 1; j++){
            xSet.insert(x + j);
            ySet.insert(y + j);
        }
        if(d == 'N')N[y + 1] = N[y + 1] + 1;
        if(d == 'S')S[y - 1] = S[y - 1] + 1;
        if(d == 'W')W[x - 1] = W[x - 1] + 1;
        if(d == 'E')E[x + 1] = E[x + 1] + 1;
    }
    vector<int>xVec, yVec;
    for(set<int>::iterator it = xSet.begin(); it != xSet.end(); it++){
        int x = *it;
        if(0 <= x && x <= Q)xVec.push_back(x);
    }
    for(set<int>::iterator it = ySet.begin(); it != ySet.end(); it++){
        int y = *it;
        if(0 <= y && y <= Q)yVec.push_back(y);
    }
    vector<int>nVec(yVec.size(), 0);
    for(int i = 1; i < yVec.size(); i++){
        int y = yVec[i];
        nVec[i] = nVec[i - 1] + N[y];
    }
    vector<int>sVec(yVec.size(), 0);
    for(int i = yVec.size() - 2; i >= 0; i--){
        int y = yVec[i];
        sVec[i] = sVec[i + 1] + S[y];
    }    
    vector<int>eVec(xVec.size(), 0);
    for(int i = 1; i < xVec.size(); i++){
        int x = xVec[i];
        eVec[i] = eVec[i - 1] + E[x];
    }
    vector<int>wVec(xVec.size(), 0);
    for(int i = xVec.size() - 2; i >= 0; i--){
        int x = xVec[i];
        wVec[i] = wVec[i + 1] + W[x];
    }

    int xIdx = 0, yIdx = 0;
    for(int i = 0; i < yVec.size(); i++){
        if(nVec[yIdx] + sVec[yIdx] < nVec[i] + sVec[i]){
            yIdx = i;
        }
    }
    for(int i = 0; i < xVec.size(); i++){
        if(eVec[xIdx] + wVec[xIdx] < eVec[i] + wVec[i]){
            xIdx = i;
        }
    }
    cout << "Case #" << t << ": " << xVec[xIdx] << " " << yVec[yIdx] << endl;
    
    // cout << "x";
    // for(int i = 0; i < xVec.size(); i++)cout << " " << xVec[i];
    // cout << endl;
    // cout << "W";
    // for(int i = 0; i < xVec.size(); i++)cout << " " << wVec[i];
    // cout << endl;
    // cout << "E";
    // for(int i = 0; i < xVec.size(); i++)cout << " " << eVec[i];
    // cout << endl;
    
    // cout << "y";
    // for(int i = 0; i < yVec.size(); i++)cout << " " << yVec[i];
    // cout << endl;
    // cout << "N";
    // for(int i = 0; i < yVec.size(); i++)cout << " " << nVec[i];
    // cout << endl;
    // cout << "S";
    // for(int i = 0; i < yVec.size(); i++)cout << " " << sVec[i];
    // cout << endl;
}

int main(){

    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        solve(t);
    }

    return 0;
}