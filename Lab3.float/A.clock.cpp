#include <iostream>

using namespace std;

int str2sec (string time){
    int res = 0;
    res = (int(time[0]) * 10 + int(time[1]))*60*60; //hours
    res += (int(time[3])*10 + int(time[4]))*60; //minutes
    res += (int)time[6]*10 + (int)time[7]; //seconds
    return res;
}

int main(){
    string time_1;
    string time_2;
    cin >> time_1 >> time_2;
    int sec_1, sec_2;
    sec_1 = str2sec(time_1);
    sec_2 = str2sec(time_2);
    if (sec_1 > sec_2){
        cout << (sec_2 + 24*60*60) - sec_1;
    } else {
        cout << (sec_2 - sec_1);
    }
    return 0;
}
