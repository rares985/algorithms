#ifndef UTILS_H_
#define UTILS_H_

#pragma once

#include <ctime>
#include <climits>
#include <cstdlib>
#include <iostream>

#include <vector>
#include <algorithm>
#include <iterator>


void bubbleSort(std::vector<int> &vec);
void insertionSort(std::vector<int> &vec);
void selectionSort(std::vector<int> &vec);
void mergeSort(std::vector<int> &vec);
void quickSort(std::vector<int> &vec);



template<typename T>
void printVector(std::vector<T> &vec)
{
    std::cout << "(";
    for(typename std::vector<T>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::string separator(it == vec.end() - 1 ? ")\n" : " ");
        std::cout << *it << separator;
    }
}

#endif /* UTILS_H_ */
