#include <iostream>
#include <math.h>

using namespace std;

bool if_prime(int n){
    bool res = true;
    for (int i = 2; i < (int)sqrt(n) + 1; i++){
        if (n % i == 0){
            res = false;
        }
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    int num_prime = 0;
    int now_number = 1;
    while (num_prime < n){
        now_number++;
        if (if_prime(now_number)){
            num_prime++;
        }
    }
    cout << now_number;

}
