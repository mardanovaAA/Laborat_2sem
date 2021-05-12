#include <iostream>
#include <cmath>

struct leaf{
    int value = 0;
    leaf* right = nullptr;
    leaf* left = nullptr;
    int bal_fact = 0;
};

struct binary_tree{
    leaf* root = nullptr;
    int amount = 0;
};

int height_by_leaf(leaf* curr_leaf){
    int height;
    if (curr_leaf->bal_fact == 0){
        if (curr_leaf->right != nullptr){
            height = height_by_leaf(curr_leaf->right) + 1;
        } else if (curr_leaf->left != nullptr){
            height = height_by_leaf(curr_leaf->left) + 1;
        } else {
            height = 1;
        }
    }
    if (curr_leaf->bal_fact == 1){
        height = height_by_leaf(curr_leaf->right) + 1;
    }
    if (curr_leaf->bal_fact == -1){
        height = height_by_leaf(curr_leaf->left) + 1;
    }
    return height;
}

void What_balance(leaf* curr_leaf){
    int hei_right = 0;
    int hei_left = 0;
    if (curr_leaf->right != nullptr){
        hei_right = height_by_leaf(curr_leaf->right);
    }
    if (curr_leaf->left != nullptr){
        hei_left = height_by_leaf(curr_leaf->left);
    }
    curr_leaf->bal_fact = hei_right - hei_left;
}

leaf* right_rotate_by_leaf(leaf* leaf2rot){
    leaf* new_root = leaf2rot->left;
    leaf2rot->left = new_root->right;
    new_root->right = leaf2rot;
    What_balance(leaf2rot);
    What_balance(new_root);
    return new_root;
}

leaf* left_rotate_by_leaf(leaf* leaf2rot){
    leaf* new_root = leaf2rot->right;
    leaf2rot->right = new_root->left;
    new_root->left = leaf2rot;
    What_balance(leaf2rot);
    What_balance(new_root);
    return new_root;
}

leaf* BigRotateLeft(leaf* leaf2rot){
    leaf2rot->right = right_rotate_by_leaf(leaf2rot->right);
    return left_rotate_by_leaf(leaf2rot);
}

leaf* BigRotateRight(leaf* leaf2rot){
    leaf2rot->left = left_rotate_by_leaf(leaf2rot->left);
    return right_rotate_by_leaf(leaf2rot);
}

leaf* Balance(leaf* leaf2bal){
    What_balance(leaf2bal);
    if (leaf2bal != nullptr){
        if (leaf2bal->bal_fact == 2){
            if (leaf2bal->right->bal_fact == -1){
                return BigRotateRight(leaf2bal);
            } else {
                return left_rotate_by_leaf(leaf2bal);
            }
        } else if (leaf2bal->bal_fact == -2){
            if (leaf2bal->left->bal_fact == 1){
                return BigRotateLeft(leaf2bal);
            } else {
                return right_rotate_by_leaf(leaf2bal);
            }
        } else {
            return leaf2bal;
        }
    } else {
        return nullptr;
    }
}

leaf* add_with_leaf(leaf* node_start, int val){
    //!You are not to use it
    //It is only for recursion;
    if (node_start == nullptr){
        leaf* new_node = new leaf;
        new_node->value = val;
        return new_node;
    } else if (node_start->value > val){
        //val is going to be left;
        node_start->left = add_with_leaf(node_start->left, val);
    } else {
        //val is going to be right;
        node_start->right = add_with_leaf(node_start->right, val);
    }
    What_balance(node_start);
    return Balance(node_start);
}

void Add_elem(binary_tree* Tree, int val){
    Tree->root = add_with_leaf(Tree->root, val);
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

void Pre_order_travers(binary_tree* Tree){
    if (Tree->root != nullptr){
        pre_order_by_leaf(Tree->root);
    } else {
        std::cout << "Null" << std::endl;
    }
    std::cout << std::endl;
}

void inf_order_by_leaf(leaf* curr_leaf){
    //!You are not to use it;
    if (curr_leaf->left != nullptr){
        inf_order_by_leaf(curr_leaf->left);
    }
    std::cout << curr_leaf->value << " ";
    if (curr_leaf->right != nullptr){
        inf_order_by_leaf(curr_leaf->right);
    }
}

void Inf_order_travers(binary_tree* Tree){
    if (Tree->root != nullptr){
        inf_order_by_leaf(Tree->root);
    } else {
        std::cout << "Null" << std::endl;
    }
    std::cout << std::endl;
}

void post_order_by_leaf(leaf* curr_leaf){
    //!You are not to use it;
    if (curr_leaf->left != nullptr){
        post_order_by_leaf(curr_leaf->left);
    }
    if (curr_leaf->right != nullptr){
        post_order_by_leaf(curr_leaf->right);
    }
    std::cout << curr_leaf->value << " ";
}

void Post_order_travers(binary_tree* Tree){
    if (Tree->root != nullptr){
        post_order_by_leaf(Tree->root);
    } else {
        std::cout << "Null" << std::endl;
    }
    std::cout << std::endl;
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
        std::cout << curr_leaf->value << " ";
    }
}

void Find_all_leaves(binary_tree* Tree){
    if (Tree->root != nullptr){
        find_all_leaves_by_leaf(Tree->root);
    } else {
        std::cout << "Null" << std::endl;
    }
    std::cout << std::endl;
}

void delete_by_leaf(leaf* Leaf2del){
    //!You are not to use it
    if (Leaf2del->right != nullptr){
        delete_by_leaf(Leaf2del->right);
    }
    if (Leaf2del->left != nullptr){
        delete_by_leaf(Leaf2del->left);
    }
    delete Leaf2del;
}

void Delete_tree(binary_tree* Tree){
    if (Tree->root != nullptr){
        delete_by_leaf(Tree->root);
    }
    delete Tree;
}

leaf* Find_val(binary_tree* Tree, int val){
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

int find_min_by_leaf(leaf* curr_leaf){
    //find the value of the minimum element of the tree with the root curr_leaf;
    while (curr_leaf->left != nullptr){
        curr_leaf = curr_leaf->left;
    }
    return curr_leaf->value;
}

leaf* delete_elem_recurs(leaf* curr_leaf, int val){
    if (curr_leaf != nullptr){
        if (curr_leaf->value > val){
            //we need to delete from the left side;
            curr_leaf->left = delete_elem_recurs(curr_leaf->left, val);
        } else if (curr_leaf->value < val){
            //we need to delete from the right side;
            curr_leaf->right = delete_elem_recurs(curr_leaf->right, val);
        } else {
            //this element we need to delete;
            leaf* left_part = curr_leaf->left;
            leaf* right_part = curr_leaf->right;
            if (left_part == nullptr){
                //there is only one right children (or none);
                delete curr_leaf;
                return right_part;
            } else if (right_part == nullptr){
                //there is only the left children;
                delete curr_leaf;
                return left_part;
            } else {
                //there are both children;
                leaf* new_node = new leaf;
                new_node->value = find_min_by_leaf(curr_leaf->right);
                new_node->left = left_part;
                new_node->right = delete_elem_recurs(right_part, new_node->value);
                return Balance(new_node);
            }
        }
    } else {
        return nullptr;
    }
    return Balance(curr_leaf);
}

void Remove_by_value(binary_tree* Tree, int val){
    Tree->root = delete_elem_recurs(Tree->root, val);
}

int main(){
    binary_tree* Tree = new binary_tree;
    Add_elem(Tree, 8);
    Add_elem(Tree, 3);
    Add_elem(Tree, 1);
    Add_elem(Tree, 2);
    std::cout << Tree->root->bal_fact << std::endl;
    std::cout << Tree->root->value << std::endl;
    Pre_order_travers(Tree);
    Inf_order_travers(Tree);
    Post_order_travers(Tree);
    Remove_by_value(Tree, 2);
    Inf_order_travers(Tree);
    Find_all_leaves(Tree);
    Delete_tree(Tree);
    return 0;
}
