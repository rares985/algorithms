#include <ctime>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iterator>

#include "utils.h"

using namespace std;


void bubbleSort(std::vector<int> &vec)
{
    int size = (int)vec.size();

    for(int i = 0; i < size - 1; i++)
    {
        for(int j = i+1; j < size; j++)
        {
            if (vec[i] > vec[j])
            {
                swap(vec[i], vec[j]);
            }

        }
    }
}

void insertionSort(std::vector<int> &vec)
{
    for(int i = 0; i < (int)vec.size(); i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (vec[j-1] > vec[j])
            {
                swap(vec[j-1], vec[j]);
            }
        }
    }
}

void selectionSort(std::vector<int> &vec)
{
    int min = 0;
    int posMin = 0;

    for (int i = 0; i < (int)vec.size(); i++)
    {
        min = vec[i];
        posMin = i;

        for(int j = i; j < (int)vec.size(); j++)
        {
            if (vec[j] < min)
            {
                posMin = j;
                min = vec[j];
            }
        }

        swap(vec[i], vec[posMin]);
    }
}


static void merge(std::vector<int> &vec, int left, int middle, int right)
{
    std::vector<int> leftvec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<int> rightvec(vec.begin() + middle + 1, vec.begin() + right + 1);

    int leftIdx = 0;
    int rightIdx = 0;
    int originalIdx = left;

    while (true)
    {
        if (leftIdx >= leftvec.size() || rigthIdx >= rightvec.size())
        {
            break;
        }

        if (leftvec[leftIdx] <= rightvec[rightIdx])
        {
            vec[originalIdx] = leftvec[leftIdx];
            leftIdx += 1;
        }
        else
        {
            vec[originalIdx] = rightvec[rightIdx];
            rightIdx += 1;
        }

        originalIdx += 1;
    }

    /* What's remained of left subset, if any */
    if (leftIdx < leftvec.size())
    {
        std::copy(leftvec.begin() + leftIdx, leftvec.end(), vec.begin() + originalIdx);
    }

    /* What's remained of right subset, if any */
    if (rightIdx < rightvec.size())
    {
        std::copy(rightvec.begin() + rightIdx, rightvec.end(), vec.begin() + originalIdx);
    }
}

void mergeSort(std::vector<int> &vec, int left, int right)
{
    int middle = left + (right - left) / 2;

    if (right > left)
    {
        mergeSort(vec, left, middle);
        mergeSort(vec, middle + 1, right);
        merge(vec, left, middle, right);
    }
}
