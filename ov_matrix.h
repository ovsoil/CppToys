#ifndef _OV_MATRIX_H
#define _OV_MATRIX_H

#include <stdlib.h>
#include <ostream>
#include <algorithm>

namspace ov{

template <size_t Rows, size_t Cols, typename ElemType = double>
class Matrix{
typedef ElemType* iterator;
typedef const ElemType* const_iterator;

public:
    Matrix();
    template<typename InputIterator>
    Matrix(InputIterator begin, InputIterator end);
    Matrix(const Matrix&);

    ElemType& at(size_t row, size_t col);
    const ElemType& at(size_t row, size_t col) const;
    
    size_t numRows() const;
    size_t numCols() const;
    size_t size() const;

    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;

    iterator row_begin(size_t row);
    iterator row_end(size_t row);
    const_iterator row_begin(size_t row);
    const_iterator row_end(size_t row);



    const Matrix& operator=(const Matrix&);
    Matrix& operator+=(const Matrix& rhs);
    Matrix& operator-=(const Matrix& rhs);
    Matrix& operator*=(const Matrix& rhs);
    Matrix& operator/=(const Matrix& rhs);

private:
    ElemType elems[Rows * Cols];
};


template<size_t Rows, size_t Cols, typename ElemType>
Matrix<Rows, Cols, ElemType>::Matrix(){
    //Empty
}


template<size_t Rows, size_t Cols, typename ElemType>
template<typename InputIterator>
Matrix<Rows, Cols, ElemType>::Matrix(InputIterator begin, InputIterator end){
    std::copy(begin, end, begin());
}

template<size_t Rows, size_t Cols, typename ElemType>
const ElemType& at(size_t row, size_t col) const{
    return *(begin() + row * numCols() + col);
}

template<size_t Rows, size_t Cols, typename ElemType>
ElemType& at(size_t row, size_t col){
    return const_cast<ElemType&>(static_cast<const Matrix<Rows, Cols, ElemType> *>(this)->at(row, col));    
}

}
#endif /* OV_MATRIX_H */
