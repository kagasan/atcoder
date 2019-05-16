#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

const double EPS = 1e-10;
double add(double a, double b){
    if(abs(a + b) < EPS * (abs(a) + abs(b)))return 0;
    return a + b;
}

class Point{
    public:
    double x, y;
    Point(double _x = 0, double _y = 0){
        x = _x;
        y = _y;
    }
    Point operator + (const Point p){
        return Point(add(x, p.x), add(y, p.y));
    }
    void operator += (const Point p){
        x = add(x, p.x);
        y = add(y, p.y);
    }
    Point operator - (const Point p){
        return Point(add(x, -p.x), add(y, -p.y));
    }
    void operator -= (const Point p){
        x = add(x, -p.x);
        y = add(y, -p.y);
    }
    Point operator * (const double d){
        return Point(x * d, y * d);
    }
    void operator *= (const double d){
        x *= d;
        y *= d;
    }
    Point operator / (const double d){
        return Point(x / d, y / d);
    }
    void operator /= (const double d){
        x /= d;
        y /= d;
    }
    // naiseki
    double dot(const Point p){
        return add(x * p.x, y * p.y);
    }
    // gaiseki
    double det(const Point p){
        return add(x * p.y, -y * p.x);
    }
    bool operator < (const Point &p)const{
        if(x != p.x)return x < p.x;
        return y < p.y;
    }
    double norm(){
        return hypot(x, y);
    }
    void rot(double rad){
        double X = add(x * cos(rad), -y * sin(rad));
        double Y = add(x * sin(rad), +y * cos(rad));
        x = X;
        y = Y;
    }
    Point roted(double rad){
        return Point(add(x * cos(rad), -y * sin(rad)), add(x * sin(rad), +y * cos(rad)));
    }
    void normalize(){
        double d = norm();
        x /= d;
        y /= d;
    }
    Point normalized(){
        double d = norm();
        return Point(x / d, y / d);
    }
    string str(){
        stringstream ss;
        ss << "(" << x << ", " << y << ")";
        return ss.str();
    }
};

void ConvexHull(const vector<Point>&in, vector<Point>&out){
    vector<Point>ps = in;
    int n = ps.size();
    sort(ps.begin(), ps.end());
    int k = 0;
    out = vector<Point>(n * 2);
    for(int i = 0; i < n; i++){
        while(k > 1 && (out[k-1] - out[k-2]).det(ps[i]-out[k-1]) <= 0)k--;
        out[k++] = ps[i];
    }
    for(int i = n - 2, t = k; i >= 0; i--){
        while(k > t && (out[k-1] - out[k-2]).det(ps[i]-out[k-1]) <= 0)k--;
        out[k++] = ps[i];
    }
    out.resize(k-1);
}

int main(){
    
    int N;
    cin >> N;
    vector<Point>pts(N);
    for(int i = 0; i < N; i++){
        cin >> pts[i].x >> pts[i].y;
    }
    vector<Point>ch;
    ConvexHull(pts, ch);
    if(ch.size() == 2){
        for(int i = 0; i < N; i++){
            int idx = -1;
            for(int j = 0; j < ch.size(); j++){
                if((pts[i] - ch[j]).norm() < 0.5)idx = j;
            }
            if(idx < 0)cout << 0 << endl;
            else cout << 0.5 << endl;
        }
        return 0;
    }
    for(int i = 0; i < N; i++){
        int idx = -1;
        for(int j = 0; j < ch.size(); j++){
            if((pts[i] - ch[j]).norm() < 0.5)idx = j;
        }
        if(idx < 0){
            printf("0\n");
            continue;
        }
        int nxt = (idx + 1) % ch.size();
        int pre = (idx + ch.size() - 1) % ch.size();
        Point A = (ch[idx] - ch[pre]).roted(0.5 * acos(-1));
        Point B = (ch[nxt] - ch[idx]).roted(0.5 * acos(-1));
        double rad = acos(A.dot(B) / A.norm() / B.norm());
        printf("%.9f\n", rad / (2 * acos(-1)));
    }

    return 0;
}