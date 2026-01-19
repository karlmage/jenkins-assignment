#ifndef SORT
#define SORT

#include <cstring>          // strcmp
#include "stringProcessor.h"

void swap(char** a, char** b)
{
    char* tmp = *a;
    *a = *b;
    *b = tmp;
}

static int partition(char** arr, int low, int high)
{
    char* pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j)
    {
        if (std::strcmp(arr[j], pivot) < 0)
        {
            ++i;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

static void quick_sort_impl(char** arr, int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);
        quick_sort_impl(arr, low, p - 1);
        quick_sort_impl(arr, p + 1, high);
    }
}

void quick_sort(char** arr, size_t length)
{
    if (!arr || length < 2)
        return;

    quick_sort_impl(arr, 0, static_cast<int>(length) - 1);
}

#endif // !SORT
