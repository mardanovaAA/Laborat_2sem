#include <iostream>

using namespace std;

bool horses_homes(int n, int* stoila, int K, int x){
    int horses = 1;
    int stl_now = stoila[0];
    for (int i = 1; i < n; i++){
        if (stoila[i] - stl_now >= x){
            horses++;
            stl_now = stoila[i];
        }
    }
    if (horses >= K){
        return true;
    } else {
        return false;
    }
}

int main(){
    int N, K;
    cin >> N >> K;
    int* stoila = new int [N];
    for (int i = 0; i < N; i++){
        cin >> stoila[i];
    }
    int max_dist = 0;
    for (int i = stoila[0]; i < stoila[N - 1] - stoila[0] + 1; i++){
        if ((max_dist <= i) && (horses_homes(N, stoila, K, i))){
            max_dist = i;
        }
    }
    cout << max_dist;
    delete [] stoila;
    return 0;
}

