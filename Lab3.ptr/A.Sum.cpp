#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int* arr = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    int res = 0;
    for (int i = 0; i < n; i++){
        if (n * arr[i] > sum){
            res += arr[i];
        }
    }
    cout << res;
    delete [] arr;
    return 0;
}
