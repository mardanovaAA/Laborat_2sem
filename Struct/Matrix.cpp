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

Matrix_str* native_mult(Matrix_str* mat_first, Matrix_str* mat_second){
    //!the sizes of matrix must be the same;
    //multiplies matrices and deletes them;
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
    delete_mat(mat_first);
    delete_mat(mat_second);
    return matrix_res;
}

int main(){

    return 0;
}






