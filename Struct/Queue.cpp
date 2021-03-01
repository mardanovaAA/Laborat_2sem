#include <iostream>

struct QueueNode{
    //This is the struct of one queue node;
    //It contains the value of this node and the pointer to the next node;
    int value;
    QueueNode* ptr_next;
};

struct Queue_str{
    //This is the struct of our list with some values (maybe not);
    //It contains the pointer to first and last nodes and the length of our queue;
    QueueNode* first;
    QueueNode* last;
    int len;
};

Queue_str* create_empty(){
    //this function create the empty queue and return the pointer;
    Queue_str* Queue = new Queue_str; //The pointer to this queue will be returned;
    Queue->first = nullptr;
    Queue->last = nullptr;
    Queue->len = 0;
    return Queue;
}

void enqueue(Queue_str* Queue, int val){
    //Adds the node to the end of the queue;
    if (Queue->len == 0){
        QueueNode* node = new QueueNode;
        node->ptr_next = nullptr;
        node->value = val;
        Queue->first = node;
        Queue->last = node;
        Queue->len++;
    } else{
        QueueNode* node = new QueueNode;
        node->ptr_next = nullptr;
        node->value = val;
        Queue->last->ptr_next = node;
        Queue->last = node;
        Queue->len++;
    }
}

void dequeue(Queue_str* Queue){
    QueueNode* node2del = Queue->first;
    Queue->first = node2del->ptr_next;
    Queue->len--;
    delete node2del;
}

int main(){
    Queue_str* Queue = new Queue_str;
    Queue = create_empty();
    int a, b;
    std::cin >> a;
    enqueue(Queue, a);
    std::cout << Queue->len << " " << Queue->first->value << " " << Queue->last->value << std::endl;
    std::cin >> b;
    enqueue(Queue, b);
    std::cout << Queue->len << " " << Queue->first->value << " " << Queue->last->value << std::endl;
    dequeue(Queue);
    std::cout << Queue->len << " " << Queue->first->value << " " << Queue->last->value << std::endl;
}
