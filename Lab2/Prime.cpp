#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int number;
    int res;
    cin >> number;
    res = 1;
    for (int i = 2; i < (int)sqrt(number) + 1; i++){
        if (number % i == 0){
            res = 0;
        }
    }
    cout << res;
    return 0;
}
