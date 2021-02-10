#include <iostream>

using namespace std;

int repeated (string number){
    //the function return the number of repeated digits;
    int n;
    if ((number[1] == number[2]) && (number[2] == number[3])){
        n = 3;
    } else if ((number[1] == number[2]) || (number[2] == number[3]) || (number[1] == number[3])){
        n = 2;
    } else {
        n = 1;
    }
    return n;
}

int main(){
    int flag = 0;
    int vel;
    string num;
    int money = 0;
    while (flag == 0){
        cin >> vel;
        cin >> num;
        if (num != "A999AA"){
            if (vel > 60){
                    int n = repeated(num);
                    if (n == 3) {
                        money += 1000;
                    } else if (n == 2) {
                        money += 500;
                    } else {
                        money += 100;
                    }
            }
        } else {
            flag = 1;
        }
    }
    cout << money;
    return 0;
}
