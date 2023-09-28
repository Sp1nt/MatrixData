#pragma once
#include <iostream>
using namespace std;
template <class T>
class Matrix {
    int** data;
    int rows;
    int cols;

public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix<T>&);
    ~Matrix();

    Matrix(Matrix<T>&&);
    Matrix<T>& operator=(Matrix<T>&& obj);

    void RandInp();
    void Print();

    void SearchMax(int&, int&);
    void SearchMin(int&, int&);


    T** GetData() const;
    int GetRows() const;
    int GetCols() const;

    Matrix<T> operator+(const Matrix<T>& obj);
    Matrix<T> operator+(const T& num) ;

    Matrix<T> operator-(const Matrix<T>& obj);
    Matrix<T> operator-(const T& num) ;

    Matrix<T> operator*(const Matrix<T>& obj);
    Matrix<T> operator*(const T& num) ;

    Matrix<T> operator/(const Matrix<T>& obj);
    Matrix<T> operator/(const T& num) ;
};


template<class T>
Matrix<T>::Matrix() {
    data = nullptr;
    rows = 0;
    cols = 0;
}

template<class T>
Matrix<T>::Matrix(int nRow, int nCol) {
        rows = nRow;
        cols = nCol;

        data = new int* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++)
                data[i][j] = 0;
        }
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& obj) {
    rows = obj.rows;
    cols = obj.cols;
    data = new int* [obj.rows];

    for (int i = 0; i < obj.rows; i++) {
        data[i] = new int[obj.cols];
    }

    for (int i = 0; i < obj.rows; i++) {
        for (int j = 0; j < obj.cols; j++) {
            data[i][j] = obj.data[i][j];
        }
    }
}

template<class T>
Matrix<T>::~Matrix() {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }
}

template<class T>
void Matrix<T>::RandInp() {
    data = new int* [rows];

    for (int i = 0; i < rows; i++)
        data[i] = new int[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            data[i][j] = rand() % 50;
}

template<class T>
Matrix<T>::Matrix(Matrix<T>&& obj) {
    rows = obj.rows;
    obj.rows = 0;

    cols = obj.cols;
    obj.cols = 0;

    data = new int* [rows];

    for (int i = 0; i < rows; i++)
        data[i] = new int[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            data[i][j] = obj.data[i][j];
            obj.data[i][j] = 0;
        }
}

template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& obj) {
    rows = obj.rows;
    obj.rows = 0;

    cols = obj.cols;
    obj.cols = 0;

    data = new int* [rows];

    for (int i = 0; i < rows; i++)
        data[i] = new int[cols];

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++) {
            data[i][j] = obj.data[i][j];
            obj.data[i][j] = 0;
        }
    return *this;
}

template<class T>
void Matrix<T>::Print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template<class T>
void Matrix<T>::SearchMax(int& indMaxRow, int& indMaxCol) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0)
                continue;
            if (data[i][j] > data[indMaxRow][indMaxCol]) {
                indMaxRow = i;
                indMaxCol = j;
            }
        }
    }
}

template<class T>
void Matrix<T>::SearchMin(int& indMinRow, int& indMinCol) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 && j == 0)
                continue;
            if (data[i][j] < data[indMinRow][indMinCol]) {
                indMinRow = i;
                indMinCol = j;
            }
        }
    }
}



template<class T>
T** Matrix<T>::GetData() const {
    return data;
}

template<class T>
int Matrix<T>::GetRows() const {
    return rows;
}

template<class T>
int Matrix<T>::GetCols() const {
    return cols;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& obj) {

    Matrix tmp(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tmp.data[i][j] = data[i][j] + obj.data[i][j];
        }
    }

    return tmp;
}

template<class T>
Matrix<T> Matrix<T>::operator+(const T& num)  {
    Matrix tmp(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tmp.data[i][j] = data[i][j] + num;
        }
    }

    return tmp;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& obj) {
    Matrix tmp(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tmp.data[i][j] = data[i][j] - obj.data[i][j];
        }
    }

    return tmp;
}

template <class T>
Matrix<T> Matrix<T>::operator-(const T& num)  {
    Matrix tmp(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tmp.data[i][j] = data[i][j] - num;
        }
    }

    return tmp;
}

template<class T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& obj) {
    Matrix tmp(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tmp.data[i][j] = data[i][j] * obj.data[i][j];
        }
    }

    return tmp;
}

template <class T>
Matrix<T> Matrix<T>::operator*(const T& num)  {
    Matrix tmp(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tmp.data[i][j] = data[i][j] * num;
        }
    }

    return tmp;
}

template<class T>
Matrix<T> Matrix<T>::operator/(const Matrix<T>& obj) {
    Matrix tmp(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tmp.data[i][j] = data[i][j] / obj.data[i][j];
        }
    }

    return tmp;
}

template <class T>
Matrix<T> Matrix<T>::operator/(const T& num) {
    Matrix tmp(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            tmp.data[i][j] = data[i][j] / num;
        }
    }

    return tmp;
}
