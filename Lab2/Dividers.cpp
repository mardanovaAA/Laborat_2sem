#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int number;
    int res;
    cin >> number;
    res = 1;
    for (int i = 2; i < number + 1; i++){
        while (number % i == 0){
            number /= i;
            cout << i << endl;
        }
    }
    return 0;
}
