#include <iostream>  
#include <random> 
#include <ctime>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <stack>

template<class T>
void myqsort(std::vector<T>& A, int left, int right)
{
    // std::cout << "myqsort " << left << ".." << right << std::endl;
    
    auto mypartition = [&A](int l, int r)
    {
        T pivot = A[(l + r) / 2];
        int i = l - 1;
        int j = r + 1;
        for (;;)
        {
            do { i += 1; } while (A[i] < pivot);
            do { j -= 1; } while (A[j] > pivot);
            if (i >= j) return j;
            // std::cout << "swap " << i << " <> " << j << std::endl;
            std::swap(A[i], A[j]);
        }
    };

    if (left < right)
    {
        int p = mypartition(left, right);
        // std::cout << "p = " << p << std::endl;
        myqsort(A, left, p);
        myqsort(A, p+1, right);
    }
}


int main(int argc, char** argv)
{
    for (int s = 10; s < 10000001; s = s*10)
    {
        std::mt19937 gen(time(0)); 
        std::uniform_int_distribution<> uid(10, 1000);

        std::vector<int> v(s);
        std::generate(v.begin(), v.end(), std::bind(uid, gen));
        
        myqsort<int>(v, 0, v.size()-1);

        int ok = true;
        for (int i = 1; i < v.size(); ++i)
        {
            if (v[i-1] > v[i])
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            std::cout << s << " - OK" << std::endl;
        }
        else
        {
            std::cout << s << " - FAIL" << std::endl;
        }

        // for (int i : v) std::cout << i << ", "; std::cout << std::endl;
        // break;
    }
    
    
    return 0;
}