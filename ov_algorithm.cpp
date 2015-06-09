#include "ov_algorithm.h"
namespace ov{
const int CUTOFF = 3;

void swap(int *array, int i, int j){
    if( i == j )
        return;
    int t = array[i];
    array[i] = array[j];
    array[j] = t;
}

/**
 * @brief   二分查找
 *
 * @param   array
 * @param   n
 * @param   target
 *
 * @return  
 */
int binary_search( int *array, int n, int target){
    int first = 0, last = n-1;
    while(first <= last){
        int mid = first + (last - first) / 2;
        if(array[mid] == target)
            return mid;
        else if(array[mid] < target){
            first = mid + 1;
        }
        else{
            last = mid - 1;
        }
    }    
    return -1;
}


/**
 * @brief   二分查找，并返回首次出现的位置
 *
 * @param   array
 * @param   n
 * @param   target
 *
 * @return  
 */
int binary_search_first( int *array, int n, int target){
    int first = 0, last = n-1;
    int mid;
    while(first <= last){
        if(array[first] == target)
            return first;
        mid = first + (last - first) / 2;
        if(array[mid] == target)
            last = mid;
        else if(array[mid] < target)
            first = mid + 1;
        else
            last = mid - 1;
    }
    if(array[mid] == target)
        return mid;
    else
        return -1;
}


/**
 * @brief   插入排序
 *
 * @param   array
 * @param   n
 *
 * @return  
 */
void insert_sort(int *array, int n){
    for(int i = 1; i < n; ++i){
        int t = array[i];
        int j;
        for(j = i - 1; j >= 0 && array[j] > t; --j){
            array[j + 1] = array[j];
        }
        array[j + 1] = t;
    }
}


void shell_sort(int *array, int n){
    
}

/**
 * @brief   快速排序
 *
 * @param   array
 * @param   first
 * @param   last
 */
int midian3(int *array, int first, int last){
    int center = (first + last) / 2;
    if(array[first] > array[center])
        swap(array, first, center);
    if(array[first] > array[last])
        swap(array, first, last);
    if(array[center] > array[last])
        swap(array, center, last);
    swap(array, center, last - 1);
    return array[last - 1];
}

int partition(int *array, int first, int last){
    int midian = midian3(array, first, last);
    int left = first, right = last - 1;
    while(1){
        while(array[++left] < midian){}
        while(array[--right] > midian){}
        if(left < right)
            swap(array, left, right);
        else
            break;
    }
    swap(array, left, last - 1);
    return left;
}

void quick_sort(int *array, int first, int last){
    if( NULL == array)
        return;

    if(first + CUTOFF <= last){
        int pivot = partition(array, first, last);
        quick_sort(array, first, pivot - 1);
        quick_sort(array, pivot + 1, last);
    }
    else{
        insert_sort(array + first, last - first + 1);
    }
}

void quick_sort(int *array, int n){
    quick_sort(array, 0, n - 1);
}


void quick_sort1(int *array, int first, int last){
    if(NULL == array)
        return;
    if(first >= last)
        return;
    if(first + CUTOFF <= last){
        int mid = first + (last - first) / 2;
        int midian = array[mid];
        swap(array, first, mid);
        int left = first + 1, right = last;
        while(1){
            while(left < last && array[left] < midian)
                ++left;
            while(right > first + 1 && array[right] > midian)
                --right;
            swap(array, left, right);
        }
        swap(array, first, right);
        quick_sort1(array, first, right - 1);
        quick_sort1(array, right + 1, last);
    }
    else{
        insert_sort(array + first, last - first + 1);
    }
}

void quick_sort1(int *array, int n){
    quick_sort1(array, 0, n - 1);
}
}
