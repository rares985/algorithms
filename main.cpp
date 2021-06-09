#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>

#include <utils.h>


constexpr auto lo = 0;
constexpr auto hi = 100;

auto seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine dre(seed);
std::uniform_int_distribution<int> di(lo, hi);

auto generator = [&]{ return di(dre);};



int main()
{
    std::srand(unsigned(std::time(nullptr)));
    std::vector<int> vec(10);
    std::generate(vec.begin(), vec.end(), generator);

    std::cout << "\n\n======= BubbleSort =========\n";
    std::generate(vec.begin(), vec.end(), generator);
    std::cout << "Before: ";
    printVector(vec);

    bubbleSort(vec);

    std::cout << "After: ";
    printVector(vec);
    std::cout << "Sorted: " << std::is_sorted(vec.begin(), vec.end());

    std::cout << "\n\n======= InsertionSort =========\n";
    std::generate(vec.begin(), vec.end(), generator);
    std::cout << "Before: ";
    printVector(vec);

    insertionSort(vec);

    std::cout << "After: ";
    printVector(vec);
    std::cout << "Sorted: " << std::is_sorted(vec.begin(), vec.end());


    std::cout << "\n\n======= SelectionSort =========\n";
    std::generate(vec.begin(), vec.end(), generator);
    std::cout << "Before: ";
    printVector(vec);

    selectionSort(vec);

    std::cout << "After: ";
    printVector(vec);
    std::cout << "Sorted: " << std::is_sorted(vec.begin(), vec.end());


    std::cout << "\n\n======= MergeSort =========\n";
    std::generate(vec.begin(), vec.end(), generator);
    std::cout << "Before: ";
    printVector(vec);

    mergeSort(vec, 0, vec.size() - 1);

    std::cout << "After: ";
    printVector(vec);
    std::cout << "Sorted: " << std::is_sorted(vec.begin(), vec.end());

    vec.clear();

    return 0;
}