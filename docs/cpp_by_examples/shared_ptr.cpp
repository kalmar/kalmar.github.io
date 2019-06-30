#include <iostream>
#include <atomic>

template <class T>
class Foo {
    struct Bar {
        T* ptr;
        std::atomic<unsigned> counter;
        Bar(T* _ptr): ptr(_ptr), counter(1) {}
        ~Bar() { delete ptr; }
    } *bar;

    void reset() {
        if (bar && bar->counter.fetch_sub(1) <= 1) {
            delete bar;
        }
        bar = nullptr;
    }

public:
    Foo(T* ptr): bar(new Bar(ptr)) {}
    Foo(const Foo<T>& src): bar(src.bar) {
        bar->counter.fetch_add(1);
    }
    ~Foo() {
        reset();
    }

    Foo<T>& operator=(const Foo<T>& src) {
        reset();
        src.bar->counter.fetch_add(1);
        bar = src.bar;
        return *this;
    }

    T* operator->() {
        return bar->ptr;
    }

    T& operator*() {
        return *(bar->ptr);
    }
};

class Test {
    int id;
public:
    Test(int nid): id(nid) {
        std::cout << "Create Test " << id << std::endl;
    }
    ~Test() {
        std::cout << "Destroy Test " << id << std::endl;
    }
    void print() {
        std::cout << " >> Print Test " << id << std::endl;
    }
};

int main(int argc, char **argv) {
    Foo<Test> a(new Test(1));
    {
        Foo<Test> b = a;
        a->print();
        b->print();

        a = Foo<Test>(new Test(2));
        a->print();
        b->print();
    }
    a->print();
    return 0;
}
