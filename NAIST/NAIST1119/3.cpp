#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
const ll INF = 1145141919;
const ll MOD = 1000000007;
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}

// 1indexed2dimention[]
class bit2d{
    public:
    vector<vector<ll> >v;
    ll h, w;
    bit2d(ll H = 0, ll W = 0){
        h = H + 5;
        w = W + 5;
        v = vector<vector<ll> >(h + 5, vector<ll>(w + 5, 0));
    }
    void add(ll x, ll y, ll val){
        for(ll yy = y; yy <= h; yy += yy & -yy){
            for(ll xx = x; xx <= w; xx += xx & -xx){
                v[yy][xx] += val;
            }
        }
    }
    ll sum_of_1_to_idx(ll x, ll y){
        if(x <= 0 || y <= 0)return 0;
        if(x > w || y > h)return 0;
        ll s = 0;
        for(ll yy = y; yy > 0; yy -= yy & -yy){
            for(ll xx = x; xx > 0; xx -= xx & -xx){
                s += v[yy][xx];
            }
        }
        return s;
    }
    ll sum(ll x1, ll y1, ll x2, ll y2){
        ll s = 0;
        s += sum_of_1_to_idx(x2, y2);
        s -= sum_of_1_to_idx(x2, y1 - 1);
        s -= sum_of_1_to_idx(x1 - 1, y2);
        s += sum_of_1_to_idx(x1 - 1, y1 - 1);
        return s;
    }
};

int main(){

	ll H, W, h, w;
	cin >> H >> W >> h >> w;
	if(H % h == 0 && W % w == 0){
		cout << "No" << endl;
		return 0;
	}
	bit2d bit(H, W);
	rep1(y, H)rep1(x, W){
		ll pre_y = y - h + 1;
		ll pre_x = x - w + 1;
		if(pre_x < 1 || pre_y < 1)bit.add(x, y, 3000);
		else{
			ll sum = bit.sum(pre_x, pre_y, x, y);
			bit.add(x, y, -(sum + 1));
		}
	}
	if(bit.sum(1, 1, W, H) <= 0)cout << "No" << endl;
	else{
		cout << "Yes" << endl;
		rep1(y, H){
			rep1(x, W){
				cout << bit.sum(x, y, x, y);
				if(x < W)cout << " ";
				else cout << endl;
			}
		}
	}

    return 0;
}