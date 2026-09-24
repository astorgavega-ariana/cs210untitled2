#include <iostream>
#include "List.h"
#include "Data.h"


int main() {
    std::unique_ptr<List<int>> list = makeList<int>();
    list->addFront(new int(10));
    list->addFront(new int(20));
    list->addFront(new int(30));
    list->print();
    int key = 20;
    std::cout << "search(20): "
    << (list->search(&key) ? "found" : "not found") << std::endl;
    list->deleteFront();
    list->print();
    std::unique_ptr<List<Data>> roster = makeList<Data>();
    roster->addFront(new Data(1, "Alice"));
    roster->addFront(new Data(2, "Bilal"));
    roster->addFront(new Data(3, "Chen"));
    roster->print();
    Data query(2, "");
    std::cout << "search(id 2): "
    << (roster->search(&query) ? "found" : "not found")
    << std::endl;
    return 0;
}














// class Box {
//     public:
//     Box(int value): data(new int(value)) {
//
//     }
//     ~Box() {
//         delete data;
//         data = nullptr;
//     }
//     int value() {
//         return *data;
//     }
// private:
//     int *data;
// };
//
// int main() {
//     // int* p = new int(5); // new does not have a name in the memory but does point to an address (heap memory)
//     // std::cout << *p << std::endl; // deref
//     // std::cout << p << std::endl; // address
//     // delete p; // this deletes long-term memory like the new int memory
//     // p = nullptr; // placeholder for an address after its deleted since the memory space has been freed after we deleted p value
//     // // nullptr function exist because dangling pointers look bad/weird and hold no memory!
//     // // heap memory = forever v. stack memory will be garbage collected afterwards
//     // // heap memory can be bad for memory link/running out of memory for a program ( stack overflow, segmentation)
//     // // pointers good for management for list of var's rather than multitude of var
//     Box *box1 = new Box(6);
//     std::cout << box1->value() << std::endl; // if it is a stack var you use dot but a pointer or heap is an arrow to reference
//     delete box1; // dot means belongs to arrow means doesnt but go this way basically!
//
//
//
//     // int x = 5;
//     // int* p = &x; // this is a pointer named p (stays in stack memory)
//     // std::cout << x << std::endl;
//     // std::cout<<*p<<std::endl; // this is the dereferencing aka the value inside the address (actual value)
//     // std::cout<<p<<std::endl; // this prints the actual address itself of the value (not the actual value but where it is)
//     //
//     // *p = 10;
//     // std::cout<<*p<<std::endl; // pointers are also var but they store addresses not values (the address itself holds thre value but you must derefrence it.)_
//     // std::cout<<&x<<std::endl; // POINTING 2 the memory location
//
//
//
//     return 0;
// }