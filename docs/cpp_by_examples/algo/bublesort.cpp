#include <iostream> 
#include <random> 
#include <ctime>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>


template<class T>
void bublesort(std::vector<T>& arr)
{
    for (int i = 1; i < arr.size(); ++i)
    {
        bool s = false;
        for (int j = 0; j < arr.size()-i; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                std::swap(arr[j], arr[j+1]);
                s = true;
            }
        }
        if (!s) break;
    }
}

int main(int argc, char** argv)
{
    for (int s = 10; s < 10000000; s = s*10)
    {
        std::mt19937 gen(time(0)); 
        std::uniform_int_distribution<> uid(10, 1000);

        std::vector<int> v(s);
        std::generate(v.begin(), v.end(), std::bind(uid, gen));
        
        bublesort<int>(v);

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
    }
    
    
    return 0;
}