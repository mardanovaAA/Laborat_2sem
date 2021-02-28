
int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new){
    if (n_new != 0){
        int* arr_new = new int[n_new];
        if (source != NULL){
            if (n_old < n_new){
                for (unsigned i = 0; i < n_old; i++){
                    arr_new[i] = source[i];
                }
            } else {
                for (unsigned i = 0; i < n_new; i++){
                    arr_new[i] = source[i];
                }
            }
        }
        delete [] source;
        return arr_new;
    } else {
        delete [] source;
        return NULL;
    }
}

