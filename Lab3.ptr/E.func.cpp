#include <iostream>



int main(){
    int a, b, c;
    std::cin >> a;
    std::cin >> b;
    int* ptr1 = &a;
    int* ptr2 = &b;
    c = do_some_awesome_work(ptr1, ptr2);
    std::cout << c;
    return 0;
}
