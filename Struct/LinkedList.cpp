//Допиши изменение первого и последнего элемента в функциях добавить/удалить в конце/начале. На случай пустого листа!!!

#include <iostream>

struct ListNode{
    //This is the struct of one list node;
    //It contains the value of this node and the pointer to the next node;
    int value;
    ListNode* ptr_next;
};

struct List{
    //This is the struct of our list with some values (maybe not);
    //It contains the pointer to first and last nodes and the length of our list;
    ListNode* first;
    ListNode* last;
    int len;
};

List* create_empty(){
    //this function create the empty list and return the pointer;
    List* LinkedList = new List; //The pointer to this list will be returned;
    LinkedList->first = nullptr;
    LinkedList->last = nullptr;
    LinkedList->len = 0;
    return LinkedList;
}

void add_to_end(List* LinkedList, int val){
    ListNode* node = new ListNode;
    node->ptr_next = nullptr;
    node->value = val;
    if (LinkedList->len == 0){
        LinkedList->last = node;
        LinkedList->first = node;
        LinkedList->len++;
    } else {
        LinkedList->last->ptr_next = node;
        LinkedList->last = node;
        LinkedList->len++;
    }
}

void add_to_begin(List* LinkedList, int val){
    ListNode* node = new ListNode;
    node->ptr_next = LinkedList->first;
    node->value = val;
    LinkedList->first = node;
    LinkedList->len++;
    if (LinkedList->len == 1){
        LinkedList->last = node;
    }
}

void delete_list(List* LinkedList){
    //this function delete the list;
    ListNode* cur_node = LinkedList->first;
    for (int i = 0; i < LinkedList->len - 1; i++){
        ListNode* node2del = cur_node;
        cur_node = cur_node->ptr_next;
        delete node2del;
    }
    delete cur_node;
    delete LinkedList;
}

void remove_value(List* LinkedList, int val){
    //The function remove node with the same val or nothing (if there is no node with val);
    List* List_res = new List; //this pointer to the new list will returned;
    int i = 0; //how much nodes we visit;
    ListNode* cur_node = LinkedList->first; //it is a pointer to current node;
    if (cur_node->value == val){
        //What if our value is equal to the first node
        LinkedList->first = LinkedList->first->ptr_next;
        delete cur_node;
        LinkedList->len--;
    } else {
        while ((cur_node->ptr_next->value != val) || (cur_node->ptr_next->ptr_next != nullptr)){
            //try to find the node with the val;
            cur_node = cur_node->ptr_next;
        }
        if (cur_node->ptr_next->value == val){
            //We find the node with the same value;
            ListNode* node2del = cur_node->ptr_next; // We will delete this node;
            cur_node->ptr_next = cur_node->ptr_next->ptr_next;
            delete node2del;
            LinkedList->len--;
        } else if (cur_node->ptr_next->value == val){
            //if the latest node is value;
            ListNode* node2del = cur_node->ptr_next;
            cur_node->ptr_next = nullptr;
            delete node2del;
            LinkedList->last = cur_node;
            LinkedList->len--;
        }
    }
}

List* copy_list(List* List_old){
    List* List_new = new List;
    List_new = create_empty();
    if (List_old->len != 0){
        ListNode* node = new ListNode;
        node = List_old->first;
        add_to_end(List_new, node->value);
        for (int i = 0; i < List_old->len - 1; i++){
            node = node->ptr_next;
            add_to_end(List_new, node->value);
        }
    }
    return List_new;
}

void print_list(List* LinkedList){
    //This function print the node's values;
    ListNode* cur_node = LinkedList->first;
    for (int i = 0; i < LinkedList->len; i++){
        std::cout << cur_node->value << std::endl;
        cur_node = cur_node->ptr_next;
    }
}

List* reverse_list(List* LinkedList){
    //This function returned the reversed list and delete the initial list;
    List* new_list = create_empty();
    ListNode* cur_node = LinkedList->first;
    for (int i = 0; i < LinkedList->len; i++){
        add_to_begin(new_list, cur_node->value);
        cur_node = cur_node->ptr_next;
    }
    delete_list(LinkedList);
    return new_list;
}

void merge_lists(List* List_first, List* List_second){
    //This function changes the first list (joins the second List to the end of the first List) and delete the second;
    ListNode* cur_node = List_second->first;
    if (List_second->len != 0){
        add_to_end(List_first, cur_node->value);
        for (int i = 0; i < List_second->len - 1; i++){
            cur_node = cur_node->ptr_next;
            add_to_end(List_first, cur_node->value);
        }
    }
    delete_list(List_second);
}

void add_i(List* LinkedList, int val, int number){
    //This function adds the new node to the list on the number place (0, len_list);
    if (number == 0) {
        add_to_begin(LinkedList, val);
    } else if (number == LinkedList->len){
        add_to_end(LinkedList, val);
    } else {
        ListNode* new_node = new ListNode;
        ListNode* cur_node = LinkedList->first;
        for (int i = 0; i < number - 1; i++){
            cur_node = cur_node->ptr_next;
        }
        new_node->ptr_next = cur_node->ptr_next;
        new_node->value = val;
        cur_node->ptr_next = new_node;
        LinkedList->len++;
    }
}

void del_i(List* LinkedList, int number){
    //This function delete the node on the number place (0. len-1);
    if ((LinkedList->len == 1) || (LinkedList->len == 0)){
        LinkedList->len = 0;
        LinkedList->first = nullptr;
        LinkedList->last = nullptr;
    } else if (number == 0) {
        //delete the first number;
        ListNode* cur_node = LinkedList->first;
        LinkedList->first = cur_node->ptr_next;
        LinkedList->len--;
        delete cur_node;
    } else if (number == LinkedList->len - 1){
        ListNode* cur_node = LinkedList->first;
        for (int i = 0; i < LinkedList->len - 1; i++){
            cur_node = cur_node->ptr_next;
        }
        LinkedList->last = cur_node;
        LinkedList->len--;
        cur_node = cur_node->ptr_next;
        delete cur_node;
    } else {
        ListNode* cur_node = LinkedList->first;
        for (int i = 0; i < number - 1; i++){
            cur_node = cur_node->ptr_next;
        }
        ListNode* node2del = new ListNode;
        node2del = cur_node->ptr_next;
        cur_node->ptr_next = cur_node->ptr_next->ptr_next;
        LinkedList->len--;
        delete node2del;
    }
}



