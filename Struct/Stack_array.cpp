#include <iostream>

struct Stack_str{
    int* base_arr;
    int len_elem; //it is how much elements in stack
    int len_real; //it is the length of the array (the degree of 2)
};

Stack_str* create_empty(){
    //creates new stack.
    Stack_str* Stack_new = new Stack_str;
    Stack_new->len_elem = 0;
    Stack_new->len_real = 16;
    Stack_new->base_arr = new int[Stack_new->len_real];
    return Stack_new;
}

void delete_stack(Stack_str* Stack2del){
    delete [] Stack2del->base_arr;
    delete Stack2del;
}

void more_space(Stack_str* Stack){
    //increases the space twice
    int* arr_old = new int[Stack->len_real];
    arr_old = Stack->base_arr;
    Stack->len_real = Stack->len_real * 2;
    Stack->base_arr = new int[Stack->len_real];
    for (int i = 0; i < Stack->len_elem; i++){
        Stack->base_arr[i] = arr_old[i];
    }
    delete [] arr_old;
}

void push(Stack_str* Stack, int val){
    //adds the val to the end of stack;
    if (Stack->len_elem + 1 >= Stack->len_real){
        more_space(Stack);
    }
    Stack->base_arr[Stack->len_elem] = val;
    Stack->len_elem++;
}

void pop(Stack_str* Stack){
    //delete the last element of stack == only reduce the len_elem
    Stack->len_elem--;
}

int main(){
    Stack_str* Stack = new Stack_str;
    Stack = create_empty();
    push(Stack, 5);
    push(Stack, 7);
    push(Stack, 8);
    pop(Stack);
    std::cout << Stack->base_arr[0] << " " << Stack->base_arr[1] <<  std::endl;

    return 0;
}
