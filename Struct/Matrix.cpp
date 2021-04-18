#include <iostream>
#include <complex>

struct Matrix_str{
    int mat_size;
    int** mat_arr;
};

Matrix_str* create_N(int N){
    //creates the empty matrix N*N;
    Matrix_str* matrix = new Matrix_str;
    matrix->mat_size = N;
    matrix->mat_arr = new int*[matrix->mat_size];
    for (int i = 0; i < matrix->mat_size; i++){
        matrix->mat_arr[i] = new int[matrix->mat_size];
    }
    return matrix;
}

void delete_mat(Matrix_str* mat2del){
    //deletes the matrix;
    for (int i = 0; i < mat2del->mat_size; i++){
        delete [] mat2del->mat_arr[i];
    }
    delete [] mat2del->mat_arr;
    mat2del->mat_size = 0;
}

Matrix_str* get_mat(int N){
    Matrix_str* Mat = new Matrix_str;
    Mat = create_N(N);
    for (int line = 0; line < N; line++){
        for (int colomn = 0; colomn < N; colomn++){
            std::cin >> Mat->mat_arr[line][colomn];
        }
    }
    return Mat;
}

Matrix_str* native_mult(Matrix_str* mat_first, Matrix_str* mat_second){
    //!the sizes of matrix must be the same;
    //multiplies matrices and return the pointer to the result;
    Matrix_str* matrix_res = new Matrix_str;
    matrix_res = create_N(mat_first->mat_size);
    for (int line = 0; line < mat_first->mat_size; line++){
        for (int column = 0; column < mat_first->mat_size; column++){
            matrix_res->mat_arr[line][column] = 0;
            //fill the element [line][column];
            for (int i = 0; i < mat_first->mat_size; i++){
                matrix_res->mat_arr[line][column] += mat_first->mat_arr[line][i] * mat_second->mat_arr[i][column];
            }
        }
    }
    return matrix_res;
}

void print_mat(Matrix_str* Mat2print){
    for (int line = 0; line < Mat2print->mat_size; line++){
        for (int column = 0; column < Mat2print->mat_size; column++){
            std::cout << Mat2print->mat_arr[line][column] << " ";
        }
        std::cout << std:: endl;
    }
}

Matrix_str* sum_mat(Matrix_str* Mat_first, Matrix_str* Mat_second, bool Del = false){
    //!The sizes must be the same!
    //If Del == true, then Mat_first and Mat_second will be deleted;
    Matrix_str* Mat_res = new Matrix_str;
    Mat_res = create_N(Mat_first->mat_size);
    for (int line = 0; line < Mat_first->mat_size; line++){
        for (int column = 0; column < Mat_first->mat_size; column++){
            Mat_res->mat_arr[line][column] = Mat_first->mat_arr[line][column] + Mat_second->mat_arr[line][column];
        }
    }
    if (Del){
        delete_mat(Mat_first);
        delete_mat(Mat_second);
    }
    return Mat_res;
}

Matrix_str* minus_mat(Matrix_str* Mat_first, Matrix_str* Mat_second, bool Del = false){
    //!The sizes must be the same!
    Matrix_str* Mat_res = new Matrix_str;
    Mat_res = create_N(Mat_first->mat_size);
    for (int line = 0; line < Mat_first->mat_size; line++){
        for (int column = 0; column < Mat_first->mat_size; column++){
            Mat_res->mat_arr[line][column] = Mat_first->mat_arr[line][column] - Mat_second->mat_arr[line][column];
        }
    }
    if (Del){
        delete_mat(Mat_first);
        delete_mat(Mat_second);
    }
    return Mat_res;
}

Matrix_str* add_nulls(Matrix_str* Mat2add, bool Del = false){
    //complete the matrix with null lines and columns to the size of the nearest degree of 2;
    //the function returns the completed matrix and don't change the initial;
    int New_size = 1;
    while (New_size < Mat2add->mat_size){
        New_size *= 2;
    }
    Matrix_str* Mat_new = new Matrix_str;
    Mat_new = create_N(New_size);
    for (int line = 0; line < Mat2add->mat_size; line++){
        //complete first lines with the initial matrix data and nulls;
        for (int column = 0; column < Mat2add->mat_size; column++){
            Mat_new->mat_arr[line][column] = Mat2add->mat_arr[line][column];
        }
        for (int column = Mat2add->mat_size; column < New_size; column++){
            Mat_new->mat_arr[line][column] = 0;
        }
    }
    for (int line = Mat2add->mat_size; line < New_size; line++){
        //completed the new lines with nulls;
        for (int column = 0; column < New_size; column++){
            Mat_new->mat_arr[line][column] = 0;
        }
    }
    if (Del){
        delete_mat(Mat2add);
    }
    return Mat_new;
}

Matrix_str* cut_nulls(Matrix_str* Mat2cut, int size2cut, bool Del = false){
    //cut matrix to the size2cut (delete the null lines and columns);
    //delete the initial matrix and return the pointer to the new;
    Matrix_str* Mat_new = new Matrix_str;
    Mat_new = create_N(size2cut);
    for (int line = 0; line < size2cut; line++){
        for (int column = 0; column < size2cut; column++){
            Mat_new->mat_arr[line][column] = Mat2cut->mat_arr[line][column];
        }
    }
    if (Del){
        delete_mat(Mat2cut);
    }
    return Mat_new;
}

Matrix_str* copy_part(Matrix_str* Mat2copy, int line_start, int line_finish, int column_start, int column_finish){
    //copy the Mat2copy and return the pointer to the part of Mat2copy.
    //!The part to copy must be the square matrix (line_finish - line_start == column_finish - column_start);
    Matrix_str* Mat_res = new Matrix_str;
    Mat_res = create_N(line_finish - line_start + 1);
    for (int line = line_start; line <= line_finish; line++){
        for (int column = column_start; column <= column_finish; column++){
            Mat_res->mat_arr[line - line_start][column - column_start] = Mat2copy->mat_arr[line][column];
        }
    }
    return Mat_res;
}

Matrix_str* take_part(Matrix_str* Mat2part, int number_part){
    //If you divided matrix A into 4 parts. number_part of A 1,1 = 1; 1,2 = 2; 2,1 = 3; 2,2 = 4;
    Matrix_str* Mat_new = new Matrix_str;
    switch (number_part){
        case 1:
            Mat_new = copy_part(Mat2part, 0, Mat2part->mat_size / 2 - 1, 0, Mat2part->mat_size / 2 - 1);
            break;
        case 2:
            Mat_new = copy_part(Mat2part, 0, Mat2part->mat_size / 2 - 1, Mat2part->mat_size / 2, Mat2part->mat_size - 1);
            break;
        case 3:
            Mat_new = copy_part(Mat2part, Mat2part->mat_size / 2, Mat2part->mat_size - 1, 0, Mat2part->mat_size / 2 - 1);
            break;
        case 4:
            Mat_new = copy_part(Mat2part, Mat2part->mat_size / 2, Mat2part->mat_size - 1, Mat2part->mat_size / 2, Mat2part->mat_size - 1);
            break;
    }
    return Mat_new;
}

void add_to_C(Matrix_str* C, Matrix_str* what_add, int place, bool Del = false){
    int line_start, line_finish, column_start, column_finish;
    switch (place){
        case 1:
            line_start = 0;
            line_finish = C->mat_size / 2 - 1;
            column_start = 0;
            column_finish = C->mat_size / 2 - 1;
            break;
        case 2:
            line_start = 0;
            line_finish = C->mat_size / 2 - 1;
            column_start = C->mat_size / 2;
            column_finish = C->mat_size - 1;
            break;
        case 3:
            line_start = C->mat_size / 2;
            line_finish = C->mat_size - 1;
            column_start = 0;
            column_finish = C->mat_size / 2 - 1;
            break;
        case 4:
            line_start = C->mat_size / 2;
            line_finish = C->mat_size - 1;
            column_start = C->mat_size / 2;
            column_finish = C->mat_size - 1;
            break;
    }
    for (int line = line_start; line < line_finish + 1; line++){
        for (int column = column_start; column < column_finish + 1; column++){
            C->mat_arr[line][column] = what_add->mat_arr[line - line_start][column - column_start];
        }
    }
    if (Del) {
        delete_mat(what_add);
    }
}

void calc_C(Matrix_str* C, Matrix_str** P){
    add_to_C(C, sum_mat(sum_mat(P[0], P[6]), minus_mat(P[3], P[4]), true), 1, true);
    add_to_C(C, sum_mat(P[2], P[4]), 2, true);
    add_to_C(C, sum_mat(P[1], P[3]), 3, true);
    add_to_C(C, sum_mat(sum_mat(P[2], P[5]), minus_mat(P[0], P[1]), true), 4, true);
}

Matrix_str* multi_mat(Matrix_str* Mat_first, Matrix_str* Mat_second, bool Del = false, bool recurs = false){
    //multiply matrices with the Strassen algoritm;
    //Del is true, if you need to delete initial matix;
    //You are not to use recurse;
    int initial_size = Mat_first->mat_size;
    Matrix_str* A = new Matrix_str;
    Matrix_str* B = new Matrix_str;
    Matrix_str* C = new Matrix_str;
    //A*B=C;
    if (recurs){
        A = Mat_first;
        B = Mat_second;
    } else {
        A = add_nulls(Mat_first);
        B = add_nulls(Mat_second);
    }
    if (A->mat_size <= 64){
        C = native_mult(A,B);
    } else {
        Matrix_str** P = new Matrix_str*[7];
        P[0] = multi_mat(sum_mat(take_part(A, 1), take_part(A, 4), true), sum_mat(take_part(B, 1), take_part(B, 4), true), true, true);
        P[1] = multi_mat(sum_mat(take_part(A, 3), take_part(A, 4), true), take_part(B, 1), true, true);
        P[2] = multi_mat(take_part(A, 1), minus_mat(take_part(B, 2), take_part(B, 4), true), true, true);
        P[3] = multi_mat(take_part(A, 4), minus_mat(take_part(B, 3), take_part(B, 1), true), true, true);
        P[4] = multi_mat(sum_mat(take_part(A, 1), take_part(A, 2), true), take_part(B, 4), true, true);
        P[5] = multi_mat(minus_mat(take_part(A, 3), take_part(A, 1), true), sum_mat(take_part(B, 1), take_part(B, 2), true), true, true);
        P[6] = multi_mat(minus_mat(take_part(A, 2), take_part(A, 4), true), sum_mat(take_part(B, 3), take_part(B, 4), true), true, true);
        C = create_N(A->mat_size);
        calc_C(C, P);
        for (int i = 0; i < 7; i++){
            delete [] P[i];
        }
        delete [] P;
    }
    delete_mat(A);
    delete_mat(B);
    if ((Del) && (!recurs)){
        delete_mat(Mat_first);
        delete_mat(Mat_second);
    }
    if (recurs){
        return C;
    } else {
        return cut_nulls(C, initial_size, true);
    }
}

int main(){
    Matrix_str* Mat1 = new Matrix_str;
    int N = 5;
    Mat1 = get_mat(N);
    Matrix_str* Mat2 = new Matrix_str;
    Mat2 = get_mat(N);
    Matrix_str* Mat_res = new Matrix_str;
    Mat_res = multi_mat(Mat1, Mat2, true);
    print_mat(Mat_res);
    delete_mat(Mat_res);
    return 0;
}






