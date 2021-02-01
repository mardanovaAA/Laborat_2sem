#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    for (int i = 1; i < N + 1; i++){
        cout << string(i, '*') << endl;
    }
    return 0;
}
