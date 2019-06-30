// C++ program for implementation of Heap Sort 
#include <iostream> 
#include <random> 
#include <ctime>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>

#define IPARENT(I) ((I-1)/2)
#define ILEFT(I) (2*I+1)

template <class T>
void myHeapSort(std::vector<T>& arr) {
    auto shiftDown = [&arr](int start, int end) {
        auto root = start;
        while (ILEFT(root) <= end) {
            auto child = ILEFT(root);
            auto swap = root;
            if (arr[swap] < arr[child])
                swap = child;
            if (child+1 <= end && arr[swap] < arr[child+1])
                swap = child + 1;
            if (swap == root)
                return;
            std::swap(arr[root], arr[swap]);
            root = swap;
        }
    };

    // heapify
    {
        auto count = arr.size();
        int start = IPARENT(count-1);
        while (start >= 0)
        {
            shiftDown(start, count-1);
            start -= 1;
        }
    }

    // sorting
    auto end = arr.size() - 1;
    while (end > 0)
    {
        std::swap(arr[end], arr[0]);
        end -= 1;
        shiftDown(0, end);
    }
}



int main() 
{ 
    std::mt19937 gen(time(0)); 
    std::uniform_int_distribution<> uid(10, 1000);

    std::vector<int> data(10000);
    std::generate(data.begin(), data.end(), std::bind(uid, gen));

	myHeapSort(data);

	std::cout << "Sorted array is \n"; 
    for (int i : data) std::cout << i << ' ';
    std::cout << std::endl;
} 
