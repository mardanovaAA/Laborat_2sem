#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int min1 = 1000001;
    int min2 = 1000001;
    int max1 = 0;
    int max2 = 0;
    int elem;
    for (int i = 0; i < n; i++){
        cin >> elem;
        if (elem <= min2){
            if (elem <= min1){
                min2 = min1;
                min1 = elem;
            } else {
                min2 = elem;
            }
        }
        if (elem >= max2){
            if (elem >= max1){
                max2 = max1;
                max1 = elem;
            } else {
                max2 = elem;
            }
        }
    }
    cout << min1 + min2 << " " << max1 + max2;
    return 0;
}
