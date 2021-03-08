#include <iostream>

struct StackNode{
    //This is the struct of one stack node;
    //It contains the value of this node and the pointer to the next node;
    int value;
    StackNode* ptr_prev; //The connection of nodes will from the last to the end.
};

struct Stack_str{
    //This is the struct of our Stack with some values (maybe not);
    //It contains the pointer to first and last nodes and the length of our stack;
    StackNode* first;
    StackNode* last;
    int len;
};

Stack_str* create_empty(){
    //this function create the empty stack and return the pointer to it;
    Stack_str* Stack = new Stack_str; //The pointer to this list will be returned;
    Stack->first = nullptr;
    Stack->last = nullptr;
    Stack->len = 0;
    return Stack;
}

void delete_stack(Stack_str* Stack){
    StackNode* node = Stack->last;
    int len_first = Stack->len;
    for (int i = 0; i < len_first - 1; i++){
        StackNode* node2del = new StackNode;
        node2del = node;
        node = node->ptr_prev;
        delete node2del;
    }
    delete node;
    delete Stack;
}

void pop(Stack_str* Stack){
    //this function delete the last node of stack;
    StackNode* node2del = Stack->last;
    Stack->last = node2del->ptr_prev;
    Stack->len--;
    delete node2del;
}

void push(Stack_str* Stack, int val){
    //this function adds the new node to the end of Stack;
    StackNode* node = new StackNode;
    node->ptr_prev = Stack->last;
    node->value = val;
    Stack->last = node;
    Stack->len++;
    if (Stack->len == 1){
        Stack->first = node;
    }
}

std::string* string_to_array(std::string str){
    //divide the string by spaces;
    std::string* arr_new = new std::string [200];
    int place = 0;
    std::string elem = "";
    for (int i = 0; i < str.size(); i++){
        if (str[i] != ' '){
            elem = elem + str[i];
        } else {
            arr_new[place] = elem;
            place++;
            elem = "";
        }
    }
    return arr_new;
}

int string_to_int(std::string str){
    int number = 0;
    int deg = 1;
    if (str[0] == '-'){
        for (int i = str.size() - 1; i >=1; i--){
        number += (int(str[i]) - 48) * deg;
        deg *= 10;
        }
        number *= -1;
    } else {
        for (int i = str.size() - 1; i >=0; i--){
        number += (int(str[i]) - 48) * deg;
        deg *= 10;
        }
    }
    return number;
}

int main(){
    //!The important note about input! Input must end with "=".
    std::string input;
    std::getline(std::cin, input);
    input = input + " ";
    std::string* tasks = string_to_array(input);
    Stack_str* Stack_num = new Stack_str;
    Stack_num = create_empty();
    int place = 0;
    int res_temp = 0;
    std::string element = tasks[place];
    while (element != "="){
        if (element == "+"){
            res_temp = Stack_num->last->ptr_prev->value + Stack_num->last->value;
            pop(Stack_num);
            pop(Stack_num);
            push(Stack_num, res_temp);
        } else if (element == "-"){
            res_temp = Stack_num->last->ptr_prev->value - Stack_num->last->value;
            pop(Stack_num);
            pop(Stack_num);
            push(Stack_num, res_temp);
        } else if (element == "*"){
            res_temp = Stack_num->last->ptr_prev->value * Stack_num->last->value;
            pop(Stack_num);
            pop(Stack_num);
            push(Stack_num, res_temp);
        } else if (element == "/"){
            res_temp = Stack_num->last->ptr_prev->value / Stack_num->last->value;
            pop(Stack_num);
            pop(Stack_num);
            push(Stack_num, res_temp);
        } else {
            push(Stack_num, string_to_int(element));
        }
        place++;
        element = tasks[place];
    }
    std::cout << Stack_num->last->value;
    delete_stack(Stack_num);
    return 0;
}
