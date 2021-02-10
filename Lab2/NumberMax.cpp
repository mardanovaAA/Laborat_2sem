#include <iostream>

using namespace std;

int main(){
    int number;
    int maxi;
    int res;
    maxi = 0;
    res = 0;
    do {
        cin >> number;
        if (maxi < number){
            res = 1;
            maxi = number;
        } else if (maxi == number) {
            ++res;
        }
    } while (number != 0);
    cout << res;
    return 0;
}
