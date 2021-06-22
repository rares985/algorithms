#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>

#include <vector>
#include <algorithm>
#include <iterator>
#include <chrono>
#include <cassert>

#include <utils.h>

typedef void (*sortingAlgorithm_t)(std::vector<int>&);

static void timeOfSorting(sortingAlgorithm_t sorter, std::vector<int> &vec)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    sorter(vec);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    // std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[us]" << std::endl;
}

constexpr auto lo = 0;
constexpr auto hi = 1000;

auto seed = std::chrono::system_clock::now().time_since_epoch().count();
std::default_random_engine dre(seed);
std::uniform_int_distribution<int> di(lo, hi);

auto generator = [&]{ return di(dre);};

constexpr auto N = 1000;


int main()
{
    std::vector<int> vec(N);

    std::generate(vec.begin(), vec.end(), generator);

    std::cout << "\n\n======= BubbleSort =========\n";
    std::generate(vec.begin(), vec.end(), generator);
    timeOfSorting(bubbleSort, vec);
    assert(true == std::is_sorted(vec.begin(), vec.end()));

    std::cout << "\n\n======= insertionSort =========\n";
    std::generate(vec.begin(), vec.end(), generator);
    timeOfSorting(insertionSort, vec);
    assert(true == std::is_sorted(vec.begin(), vec.end()));

    std::cout << "\n\n======= selectionSort =========\n";
    std::generate(vec.begin(), vec.end(), generator);
    timeOfSorting(selectionSort, vec);
    assert(true == std::is_sorted(vec.begin(), vec.end()));

    std::cout << "\n\n======= mergeSort =========\n";
    std::generate(vec.begin(), vec.end(), generator);
    timeOfSorting(mergeSort, vec);
    assert(true == std::is_sorted(vec.begin(), vec.end()));

    std::cout << "\n\n======= quickSort =========\n";
    std::generate(vec.begin(), vec.end(), generator);
    timeOfSorting(quickSort, vec);
    assert(true == std::is_sorted(vec.begin(), vec.end()));

    vec.clear();

    return 0;
}