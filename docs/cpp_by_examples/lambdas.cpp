#include <iostream>
#include <memory>

class foo {
    int data;
public:
    foo(int d): data(d) { std::cout << "foo init" << std::endl; }
    ~foo() { std::cout << "foo destroy" << std::endl; }
    void print() { std::cout << "foo print " << data << std::endl; }
};

int main(int argc, char** argv) {
    auto p = std::make_shared<foo>(13);
    auto test = [p]() {
        p->print();
    };
    test();
    p->print();
    return 0;
}