#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)

class KG{
    public:
    ll x, y, d, cnt, step, a, b;
    KG(ll _x, ll _y, ll _d, ll _cnt, ll _step, ll _a, ll _b){
        x = _x;
        y = _y;
        d = _d;
        cnt = _cnt;
        step = _step;
        a = _a;
        b = _b;
    }
    bool operator > (const KG &kg)const{
        return cnt * a - step * b > kg.cnt * kg.a - kg.step * kg.b;
    }
};

const ll MOD = 40;
ll N, M, B;
ll gy, gx;

const ll dy[5] = {-1, 1, 0, 0, 0};
const ll dx[5] = {0, 0, -1, 1, 0};
char UDLR[5] = {'U', 'D', 'L', 'R'};
ll arrow[40][40];
ll block[40][40];

ll ry[100], rx[100];
char rc[100];
ll by[300], bx[300];

void move(ll &y, ll &x, ll d){
    y = (y + MOD + dy[d]) % MOD;
    x = (x + MOD + dx[d]) % MOD;
}

void solve(ll a = 10, ll b = 1){
    rep(y, 40)rep(x, 40)arrow[y][x] = 4;
    priority_queue<KG, vector<KG>, greater<KG> >Q;
    ll rv[4] = {1, 0, 3, 2};
    rep(i, 4)Q.push(KG(gx, gy, i, 0, 1, a, b));
    while(!Q.empty()){
        KG kg = Q.top();
        Q.pop();
        ll x = kg.x, y = kg.y, d = kg.d, cnt = kg.cnt, step = kg.step;
        if(block[y][x])continue;
        if(arrow[y][x] < 4)continue;
        arrow[y][x] = d;
        rep(i, 4){
            ll ny = y, nx = x;
            move(ny, nx, i);
            if(arrow[ny][nx] == 4 && block[ny][nx] == 0){
                Q.push(KG(nx, ny, rv[i], cnt + (d != rv[i]), step + 1, a, b));
            }
        }
    }
}

ll rm_tmp[40][40];
ll rm_flg[100][40][40];

ll rm(){
    ll ctod[256];
    ctod['U'] = 0;
    ctod['D'] = 1;
    ctod['L'] = 2;
    ctod['R'] = 3;

    ll score = 0;
    rep(i, 40)rep(j, 40)rm_tmp[i][j] = 0;
    rep(i, 100)rep(j, 40)rep(k, 40)rm_flg[i][j][k] = 0;
    rep(i, M){
        ll y = ry[i], x = rx[i], d = ctod[rc[i]];
        ll ok = 0;
        for(ll j = 0; j < 1600; j++){
            if(block[y][x])break;
            rm_tmp[y][x] = 1;
            if(y == gy && x == gx){
                score += 1000;
                break;
            }
            if(arrow[y][x] != d){
                d = arrow[y][x];
                rm_flg[i][y][x] = 1;
            }
            move(y, x, d);
        }
    }
    rep(i, 40)rep(j, 40){
        ll flg = 0;
        rep(k, 100)if(rm_flg[k][i][j])flg = 1;
        if(flg == 0)arrow[i][j] = 4;
        if(arrow[i][j] < 4)score -= 10;
        if(rm_tmp[i][j])score++;
    }
    return score;
}

void write(){
    ll k = 0;
    rep(y, 40)rep(x, 40)if(arrow[y][x] < 4)k++;
    cout << k << endl;
    rep(y, 40)rep(x, 40)if(arrow[y][x] < 4)cout << y << " " << x << " " << UDLR[arrow[y][x]] << endl;
}

int main(){
    std::chrono::system_clock::time_point  start, end;
    start = std::chrono::system_clock::now(); // 計測開始時間
    random_device rd;
    mt19937 mt(rd());

    cin >> N >> M >> B;
    cin >> gy >> gx;
    rep(i, M)cin >> ry[i] >> rx[i] >> rc[i];
    rep(i, B){
        cin >> by[i] >> bx[i];
        block[by[i]][bx[i]] = 1;
    }
    ll ba = 10, bb = 1;
    solve();
    ll score = rm();
    cerr << score << endl;
    
    for(ll a = 1; a <= 100; a++){
        for(ll b = 1; b <= 10; b++){
            solve(a, b);
            ll sc = rm();
            if(sc > score){
                ba = a;
                bb = b;
                score = sc;
            }
        }
    }
    solve(ba, bb);
    score = rm();
    cerr << score << endl;
    write();

    return 0;
}
