#include <iostream>

using namespace std;

int what_quater(int x, int y){
    int quater = 0;
    if ((x > 0) && (y > 0)){
        quater = 1;
    }
    if ((x < 0) && (y > 0)){
        quater = 2;
    }
    if ((x < 0) && (y < 0)){
        quater = 3;
    }
    if ((x > 0) && (y < 0)){
        quater = 4;
    }
    return quater;
}

int main(){
    int n = 0;
    cin >> n;
    int quaters[5] = {0};
    int max_sum = 0;
    int x, y;
    int qrt_now = 0;
    for (int i = 0; i < n; i++){
        cin >> x;
        cin >> y;
        qrt_now = what_quater(x, y);
        quaters[qrt_now] += 1;
        if ((max_sum < quaters[qrt_now]) && (qrt_now != 0)){
            max_sum = quaters[qrt_now];
        }
    }
    qrt_now = 1;
    while (max_sum != quaters[qrt_now]){
            qrt_now += 1;
    }
    cout << qrt_now << " " << quaters[qrt_now];
    return 0;
}
