#ifndef _OV_ALGORITHM_H
#define _OV_ALGORITHM_H
#include <cstddef>
namespace ov{

int binary_search( int *array, int n, int target);
int binary_search_first( int *array, int n, int target);

void insert_sort(int *array, int n);
void quick_sort(int *array, int first, int last);
void quick_sort(int *array, int n);

void quick_sort1(int *array, int first, int last);
void quick_sort1(int *array, int n);

}


#endif /* OV_ALGORITHM_H */
