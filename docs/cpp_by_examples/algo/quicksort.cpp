#include <iostream>  
#include <random> 
#include <ctime>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <stack>

template<class T>
std::vector<T> myqsort(std::vector<T>& A)
{
    if (A.size() <= 1) return A;
    T pivot = A[0]; // выбираем какой-то элемент, вопрос выбора - отдельная тема для разговора
    std::vector<T> lA, rA;
    for (int i = 1; i < A.size(); ++i)
    {
        T d = A[i];
        // раскидываем элементы слева и справа от выбранного
        if (d < pivot) lA.push_back(d);
        else rA.push_back(d);
    }
    // рекурсивно зовем себя же для половинок
    auto lR = myqsort(lA);
    auto rR = myqsort(rA);
    // собираем результат как (lR + pivot + rR)
    lR.push_back(pivot);
    lR.insert(lR.end(), rR.begin(), rR.end());
    return lR;
}

template<class T>
void myqsort2(std::vector<T>& A)
{
    std::stack<std::pair<int,int>> ps;
    ps.push(std::pair<int,int>(0, A.size()-1));

    while (!ps.empty())
    {
        auto p = ps.top();
        ps.pop();

        if (p.first >= p.second) continue;

        T pivot = A[(p.first + p.second) / 2];
        auto i = p.first - 1;
        auto j = p.second + 1;

        int r = 0;
        for (;;)
        {
            do { i += 1; } while (A[i] < pivot);
            do { j -= 1; } while (A[j] > pivot);

            if (i >= j) { r = j; break; }

            std::iter_swap(A.begin()+i, A.begin()+j);
        }

        ps.push(std::pair<int,int>(p.first, r-1));
        ps.push(std::pair<int,int>(r+1, p.second));
    }
}

int main() 
{ 
    std::mt19937 gen(time(0)); 
    std::uniform_int_distribution<> uid(10, 1000);

    std::vector<int> data(10000);
    std::generate(data.begin(), data.end(), std::bind(uid, gen));
    myqsort2<int>(data); auto& sd = data;

    std::cout << "My numbers: ";
    for (int i : sd) std::cout << i << ' ';
    std::cout << std::endl;

    return 0;
} 