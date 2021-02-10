#include <iostream>

using namespace std;

int main(){
    int number;
    int res;
    res = 0;
    do {
        cin >> number;
        if (number != 0 && number % 2 == 0){
            ++res;
        }
    } while (number != 0);
    cout << res;
    return 0;
}
