#include <iostream>
#include <string>

using namespace std;

string vavilon(int x){
    string vav;
    string ten(x / 10, '<');
    string one(x % 10, 'v');
    vav = ten + one;
    return vav;
}

int main(){
    string res = "";
    int num;
    cin >> num;
    while (num != 0){
        res = vavilon(num % 60) + res;
        num = num / 60;
        if (num != 0){
            res = "." + res;
        }
    }
    cout << res;
    return 0;
}
