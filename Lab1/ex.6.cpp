#include <iostream>
#include <math.h>

using namespace std;

void stars(int n){
    for (int i = 0; i < n / 2 + 1; i++){
        cout << string(i, ' ') << string(n - 2*i, '*') << endl;
    }
}

int main(){
    int N;
    cin >> N;
    stars(N);
    return 0;
}
