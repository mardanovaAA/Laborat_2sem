#include <iostream>

void print_arr(int* arr, int len){
    for (int i = 0; i < len; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void bubble_sort(int* arr, int len, bool mod){
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

void shaker_sort(int* arr, int len, bool mod){
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

void insertion_sort(int* arr, int len, bool mod){
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

void shell_sort(int* arr, int len, bool mod){
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

void selection_sort(int* arr, int len, bool mod){
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

void merge_sort(int* arr, int left_board, int right_board, bool mod){
    //!Do not work yet.
    //mod = true - from small to big;
    //mod = false - from big to small;
    if ((right_board > left_board)){
        int middle = (right_board + left_board) / 2;
        merge_sort(arr, left_board, middle, mod);
        merge_sort(arr, middle + 1, right_board, mod);

    }
}

int main(){
    int N;
    std::cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++){
        std::cin >> arr[i];
    }
    selection_sort(arr, N, true);
    print_arr(arr, N);
    selection_sort(arr, N, false);
    print_arr(arr, N);
    delete [] arr;
    return 0;
}
