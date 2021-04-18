#include <iostream>

struct leaf{
    int value = 0;
    leaf* right = nullptr;
    leaf* left = nullptr;
};

struct binary_tree{
    leaf* root = nullptr;
    int amount = 0;
};

void Add_with_leaf(leaf* node_start, int val){
    //!You are not to use it
    //It is only for recursion;
    if (node_start->value > val){
        //val is going to be left;
        if (node_start->left == nullptr){
            leaf* new_node = new leaf;
            new_node->value = val;
            node_start->left = new_node;
        } else {
            Add_with_leaf(node_start->left, val);
        }
    } else {
        //val is going to be right;
        if (node_start->right == nullptr){
            leaf* new_node = new leaf;
            new_node->value = val;
            node_start->right = new_node;
        } else {
            Add_with_leaf(node_start->right, val);
        }
    }
}

void Add_elem(binary_tree* Tree, int val){
    if (Tree->root == nullptr){
        Tree->root = new leaf;
        Tree->root->value = val;
        Tree->amount++;
    } else {
        Add_with_leaf(Tree->root, val);
    }
}

leaf* find_val(binary_tree* Tree, int val){
    //Returns pointer to the parent, if there is an element with val;
    //In case when val == root, returns the pointer to the root;
    //When there is not such element, returns nullptr;
    leaf* curr_leaf = Tree->root;
    leaf* parent_leaf = Tree->root;
    bool flag = false; //it is true, if the element with val exists.
    while (curr_leaf != nullptr){
        if (curr_leaf->value == val){
            curr_leaf = nullptr;
            flag = true;
        } else if (curr_leaf->value < val){
            parent_leaf = curr_leaf;
            curr_leaf = curr_leaf->right;
        } else {
            parent_leaf = curr_leaf;
            curr_leaf = curr_leaf->left;
        }
    }
    if (flag){
        return parent_leaf;
    } else {
        return nullptr;
    }
}

void delete_elem_with_parent(leaf* parent, leaf* what2del){
    //!You are not to use it!
    if ((what2del->left == nullptr) && (what2del->right == nullptr)){
        //what2del has no children
        if ((parent->right != nullptr) && (parent->right->value == what2del->value)){
            parent->right = nullptr;
        } else {
            parent->left = nullptr;
        }
        delete what2del;
    } else if (what2del->left == nullptr){
        //what2del has only right children
        if ((parent->right != nullptr) && (parent->right->value == what2del->value)){
            parent->right = what2del->right;
        } else {
            parent->left = what2del->right;
        }
        delete what2del;
    } else if (what2del->right == nullptr){
        //what2del has only left children;
        if ((parent->right != nullptr) && (parent->right->value == what2del->value)){
            parent->right = what2del->left;
        } else {
            parent->left = what2del->left;
        }
        delete what2del;
    } else {
        //what2del has both children;
        //Let's find the lefmost element of the right undertree of what2del;
        leaf* curr_leaf = what2del->right;
        leaf* par_curr_leaf = what2del;
        bool flag = false;
        while (curr_leaf->left != nullptr){
            flag = true;
            par_curr_leaf = curr_leaf;
            curr_leaf = curr_leaf->left;
        }
        if (flag){
            //It means that par_curr_leaf != what2del;
            par_curr_leaf->left = curr_leaf->right;
            curr_leaf->right = what2del->right;
            curr_leaf->left = what2del->left;
        } else {
            curr_leaf->left = what2del->left;
        }
        if ((parent->right != nullptr) && (parent->right->value == what2del->value)){
            parent->right = curr_leaf;
        } else {
            parent->left = curr_leaf;
        }
        delete what2del;
    }
}

void remove_by_value(binary_tree* Tree, int val){
    leaf* parent_leaf = find_value(Tree, val);
    if (parent_leaf != nullptr){
        if (parent_leaf->value == val){
            //the case of root;
            leaf* false_parent = new leaf;
            false_parent->right = Tree->root;
            delete_elem_with_parent(false_parent, Tree->root);
            Tree->root = false_parent->right;
            delete false_parent;
        } else {
            if ((parent_leaf->right != nullptr) && (parent_leaf->right->value == val)){
                leaf* what2del = parent_leaf->right;
            } else {
                leaf* what2del = parent_leaf->left;
            }
            delete_elem_with_parent(parent_leaf, what2del);
        }
    Tree->amount--;
}
}

void pre_order_by_leaf(leaf* curr_leaf){
    //!You are not to use it;
    std::cout << curr_leaf->value << " ";
    if (curr_leaf->left != nullptr){
        pre_order_by_leaf(curr_leaf->left);
    }
    if (curr_leaf->right != nullptr){
        pre_order_by_leaf(curr_leaf->right);
    }
}

void pre_order_travers(binary_tree* Tree){
    if (Tree->root != nullptr){
        pre_order_by_leaf(Tree->root);
    } else {
        std::cout << "Null" << std::endl;
    }
}

void inf_order_by_leaf(leaf* curr_leaf){
    //!You are not to use it;
    if (curr_leaf->left != nullptr){
        pre_order_by_leaf(curr_leaf->left);
    }
    std::cout << curr_leaf->value << " ";
    if (curr_leaf->right != nullptr){
        pre_order_by_leaf(curr_leaf->right);
    }
}

void inf_order_travers(binary_tree* Tree){
    if (Tree->root != nullptr){
        inf_order_by_leaf(Tree->root);
    } else {
        std::cout << "Null" << std::endl;
    }
}

void post_order_by_leaf(leaf* curr_leaf){
    //!You are not to use it;
    if (curr_leaf->left != nullptr){
        pre_order_by_leaf(curr_leaf->left);
    }
    if (curr_leaf->right != nullptr){
        pre_order_by_leaf(curr_leaf->right);
    }
    std::cout << curr_leaf->value << " ";
}

void post_order_travers(binary_tree* Tree){
    if (Tree->root != nullptr){
        post_order_by_leaf(Tree->root);
    } else {
        std::cout << "Null" << std::endl;
    }
}

void find_all_leaves_by_leaf(leaf* curr_leaf){
    //!You are not to use it
    if (curr_leaf->left != nullptr){
        find_all_leaves_by_leaf(curr_leaf->left);
    }
    if (curr_leaf->right != nullptr){
        find_all_leaves_by_leaf(curr_leaf->right);
    }
    if ((curr_leaf->left == nullptr) && (curr_leaf->right == nullptr)){
        std::cout << curr_leaf->value;
    }
}

void find_all_leaves(binary_tree* Tree){
    if (Tree->root != nullptr){
        find_all_leaves_by_leaf(Tree->root);
    } else {
        std::cout << "Null" << std::endl;
    }
}

int main(){

}

