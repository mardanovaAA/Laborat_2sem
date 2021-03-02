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

void pop(Stack_str* Stack){
    //this function delete the last node of stack;
    StackNode* node2del = Stack->last;
    Stack->last = node2del->ptr_prev;
    Stack->len--;
    delete node2del;
}

int main(){
    Stack_str* Stack = new Stack_str;
    Stack = create_empty();
    int a, b;
    std::cin >> a;
    push(Stack, a);
    std::cout << Stack->len << " " << Stack->first->value << " " << Stack->last->value << std::endl;
    std::cin >> b;
    push(Stack, b);
    std::cout << Stack->len << " " << Stack->first->value << " " << Stack->last->value << std::endl;
    pop(Stack);
    std::cout << Stack->len << " " << Stack->first->value << " " << Stack->last->value << std::endl;
}
