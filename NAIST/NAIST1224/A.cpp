#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

void write(){
    for(int i = 1; i <= 64; i++){
        stringstream ss, ss2, ss3;
        ss << "pieces/p_" << i << ".png";
        ss2 << "out/" << i << ".png";
        ss3 << i;
        string s = ss.str(), s2 = ss2.str(), s3 = ss3.str();
        cv::Mat img = cv::imread(s), dst;
        cv::resize(img, dst, cv::Size(64, 64));
        cv::putText(dst, s3, cv::Point(0, 16), CV_FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 255));
        cv::imwrite(s2, dst);
    }
}

cv::Mat imgs[65];
int pos[65];
void out(){
    cv::Mat img(512, 512, CV_8UC3, cv::Scalar(255, 255, 255));
    for(int i = 1; i <= 64; i++){
        int y = pos[i] / 8;
        int x = pos[i] % 8;
        cv::Mat mat = (cv::Mat_<double>(2,3)<<1.0, 0.0, x * 64, 0.0, 1.0, y * 64);
        cv::warpAffine(imgs[i], img, mat, img.size(), CV_INTER_LINEAR, cv::BORDER_TRANSPARENT);
        // PinP_tr(img, imgs[i], x * 64, y * 64);
    }
    cv::imwrite("tmp.png", img);
}


void solve(){

    for(int i = 1; i <= 64; i++){
        pos[i] = i - 1;
        stringstream ss;
        ss << "out/" << i << ".png";
        imgs[i] = cv::imread(ss.str());
    }

    out();
    for(int a, b; cin >> a >> b;){
        if(a == 0 && b == 0)break;
        if(a < 1 || b < 1 || a > 64 || b > 64)continue;
        swap(pos[a], pos[b]);
        out();
    }
}

int main(){

    solve();

    return 0;
}