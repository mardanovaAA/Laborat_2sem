#include <iostream>
#include <cstdlib>
#include <chrono>
#include <fstream>

void print_arr(int* arr, int len){
    for (int i = 0; i < len; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void bubble_sort(int* arr, int len, bool mod = true){
    //mod = true - from small to big;
    //mod = false - from big to small;
    int change;
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len - i - 1; j++){
            if ((mod) && (arr[j] > arr[j+1])){
                change = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = change;
            }
            if ((!mod) && (arr[j] < arr[j+1])){
                change = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = change;
            }
        }
    }
}

void shaker_sort(int* arr, int len, bool mod = true){
    //mod = true - from small to big;
    //mod = false - from big to small;
    int change;
    int left_board = 0;
    int right_board = len - 1;
    while (right_board >= left_board){
        for (int j = left_board; j < right_board; j++){
                if ((mod) && (arr[j] > arr[j+1])){
                    change = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = change;
                }
                if ((!mod) && (arr[j] < arr[j+1])){
                    change = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = change;
                }
        }
        right_board--;
        for (int j = right_board; j > left_board; j--){
                if ((!mod) && (arr[j] > arr[j-1])){
                    change = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = change;
                }
                if ((mod) && (arr[j] < arr[j-1])){
                    change = arr[j];
                    arr[j] = arr[j-1];
                    arr[j-1] = change;
                }
        }
        left_board++;
    }
}

void insertion_sort(int* arr, int len, bool mod = true){
    //mod = true - from small to big;
    //mod = false - from big to small;
    int change;
    for (int i = 1; i < len; i++){
        for (int j = i; j >0; j--){
            if ((!mod) && (arr[j] > arr[j-1])){
                change = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = change;
            }
            if ((mod) && (arr[j] < arr[j-1])){
                change = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = change;
            }
        }
    }
}

void shell_sort(int* arr, int len, bool mod = true){
    //mod = true - from small to big;
    //mod = false - from big to small;
    int step = len / 2;
    while (step > 0){
        for (int i = step; i < len; i++){
            for (int j = i; j >= step; j -= step){
                if ((!mod) && (arr[j] > arr[j - step])){
                    int change = arr[j];
                    arr[j] = arr[j - step];
                    arr[j - step] = change;
                }
                if ((mod) && (arr[j] < arr[j - step])){
                    int change = arr[j];
                    arr[j] = arr[j - step];
                    arr[j - step] = change;
                }
            }
        }
        if (step == 2){
            step = 1;
        } else {
            step /= 2;
        }
        }
}

void selection_sort(int* arr, int len, bool mod = true){
    //mod = true - from small to big;
    //mod = false - from big to small;
    for (int i = 0; i < len; i++){
        int extreme_pos = i;
        for (int j = i + 1; j < len; j++){
            if ((mod) && (arr[j] < arr[extreme_pos])){
                //find minimum
                extreme_pos = j;
            }
            if ((!mod) && (arr[j] > arr[extreme_pos])){
                //find maximum
                extreme_pos = j;
            }
        }
        if (i != extreme_pos){
            int change = arr[i];
            arr[i] = arr[extreme_pos];
            arr[extreme_pos] = change;
        }
    }
}

void merge_sort(int* arr, int len, bool mod = true){
    //mod = true - from small to big;
    //mod = false - from big to small;
    int len_left = len / 2;
    int len_right = len - len / 2;
    if (len > 1){
        merge_sort(&arr[0], len_left, mod);
        merge_sort(&arr[len_left], len_right, mod);
        int* arr2merge = new int [len];
        int i = 0;
        int start_left = 0;
        int start_right = len_left;
        while ((start_left < len_left) || (start_right < len)){
            if (mod){
                if (arr[start_left] < arr[start_right]){
                    arr2merge[i] = arr[start_left];
                    start_left++;
                    i++;
                } else {
                    arr2merge[i] = arr[start_right];
                    start_right++;
                    i++;
                }
            }
            if (!mod){
                if (arr[start_left] > arr[start_right]){
                    arr2merge[i] = arr[start_left];
                    start_left++;
                    i++;
                } else {
                    arr2merge[i] = arr[start_right];
                    start_right++;
                    i++;
                }
            }
            if (start_left == len_left){
                while (start_right < len){
                    arr2merge[i] = arr[start_right];
                    start_right++;
                    i++;
                }
            }
            if (start_right == len){
                while (start_left < len_left){
                    arr2merge[i] = arr[start_left];
                    start_left++;
                    i++;
                }
            }
        }
        //replace the part of initial arr with arr2merge
        for (int i = 0; i < len; i++){
            arr[i] = arr2merge[i];
        }
        delete [] arr2merge;
    }
}

void quick_sort(int* arr, int len, bool mod = true){
    //!This sort is based on the random.
    //mod = true - from small to big;
    //mod = false - from big to small;
    int left = 0;
    int right = len - 1;
    int opor = rand() % len;
    int mid = arr[opor];
    do {
        while ((mod) && (arr[left] < mid)) {
            left++;
        }
        while ((mod) && (arr[right] > mid)) {
            right--;
        }
        while ((!mod) && (arr[left] > mid)) {
            left++;
        }
        while ((!mod) && (arr[right] < mid)) {
            right--;
        }
        if (left <= right) {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    } while (left <= right);
    if (right > 0) {
        quick_sort(arr, right + 1, mod);
    }
    if (left < len) {
        quick_sort(&arr[left], len - left, mod);
    }
}

int main(){
    int N = 10;
    std::ofstream out;
    out.open("Time_data.txt");
    while (N < 500000){
        int* arr = new int[N];
        for (int i = 0; i < N; i++){
            arr[i] = rand();
        }
        auto time_begin = std::chrono::steady_clock::now();
        quick_sort(arr, N, true);
        auto time_finish = std::chrono::steady_clock::now();
        //print_arr(arr, N);
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_finish - time_begin);
        if (out.is_open()){
            out << elapsed_ms.count() << std::endl;
        }
        std::cout << N << std::endl;
        delete [] arr;
        N *= 5;
    }
    out.close();
    return 0;
}
