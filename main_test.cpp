#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ov_algorithm.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace ov;
const int N = 100;

#define CREATE_ARRAY(array_name) \
int array_name[N] = {0}; \
srand(time(0)); \
for(int i = 0; i < N; ++i){ \
    array_name[i] = rand() % 100; \
}

void print_array(int *array, int n){
    for(int i = 0; i < n; ++i){
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

TEST_CASE( "Test my algorithm", "[algorithm]" ) {

    SECTION("Binary Search"){
        int A[] = {0, 0, 1, 3, 3, 3, 4, 5, 5, 6, 7, 8, 10, 100, 233, 435};
        int n = sizeof(A) / sizeof(int);

        REQUIRE( true == (binary_search(A, n, 0) == 0 || binary_search(A, n, 0) == 1 ));
        REQUIRE( binary_search(A, n, 1) == 2 );
        REQUIRE( binary_search(A, n, 2) == -1 );
        REQUIRE( true == (binary_search(A, n, 5) == 7 || binary_search(A, n, 5) == 8));

    }

    SECTION("Binary Search first"){
        int A[] = {0, 0, 1, 3, 3, 3, 4, 5, 5, 6, 7, 8, 10, 100, 233, 435};
        int n = sizeof(A) / sizeof(int);

        REQUIRE( binary_search_first(A, n, 0) == 0 );
        REQUIRE( binary_search_first(A, n, 1) == 2 );
        REQUIRE( binary_search_first(A, n, 2) == -1 );
        REQUIRE( binary_search_first(A, n, 5) == 7 );

    }


    SECTION("Quick Sort"){
        int A1[2] = { 4, 2};
        quick_sort(A1, 2);
        print_array(A1, 2);

        int A2[3] = { 4, 2, 2};
        quick_sort(A2, 3);
        print_array(A2, 3);

        int A3[4] = { 4, 2, 2, 5};
        quick_sort(A3, 4);
        print_array(A3, 4);

        CREATE_ARRAY(B);        
        quick_sort(B, N);
        print_array(B, N);
    }

    SECTION("Quick Sort"){
        int A1[2] = { 4, 2};
        quick_sort1(A1, 2);
        print_array(A1, 2);

        int A2[3] = { 4, 2, 2};
        quick_sort1(A2, 3);
        print_array(A2, 3);

        int A3[4] = { 4, 2, 2, 5};
        quick_sort1(A3, 4);
        print_array(A3, 4);

        CREATE_ARRAY(B);        
        quick_sort1(B, N);
        print_array(B, N);
    }
}
