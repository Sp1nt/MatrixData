
#pragma once
#include <iostream>
#include "Matrix.h"


using namespace std;

class A {
	int** data;
	int rows;
	int cols;

public:
	A();
	A(int, int);
	A(const A&);
	~A();

	A& operator=(const A& a);

	int** GetData() const;
	int GetRows() const;
	int GetCols() const;

	A operator+(const A& obj);
	A operator+(const int num);

	A operator-(const A& obj);
	A operator-(const int num);

	A operator*(const A& obj);
	A operator*(const int num);

	A operator/(const A& obj);
	A operator/(const int num);


};



A::A() {
	rows = 0;
	cols = 0;
	data = nullptr;
}
A::A(int r, int c) {
	rows = r;
	cols = c;

	data = new int* [rows];

	for (int i = 0; i < rows; i++)
	{
		data[i] = new int[cols];
	}
}

A::A(const A& obj) {
	rows = obj.rows;
	cols = obj.cols;
	data = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		data[i] = new int[cols]();
		for (int j = 0; j < cols; ++j) {
			data[i][j] = obj.data[i][j];
		}
	}
}

A::~A() {
	if (data != nullptr) {
		for (int i = 0; i < rows; i++)
			delete[] data[i];
		delete[] data;
	}
}


int** A::GetData() const {
	return data;
}
int A::GetRows() const {
	return rows;
}
int A::GetCols() const {
	return cols;
}

inline A A::operator+(const A& obj)
{
	A result(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			result.data[i][j] = data[i][j] + obj.data[i][j];
		}
	}
	return result;
}

inline A A::operator+(const int num)
{
	A result(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			result.data[i][j] = data[i][j] + num;
		}
	}
	return result;
}

inline A A::operator-(const A& obj)
{
	A result(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			result.data[i][j] = data[i][j] - obj.data[i][j];
		}
	}
	return result;
}

inline A A::operator-(const int num)
{
	A result(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			result.data[i][j] = data[i][j] - num;
		}
	}
	return result;
}

inline A A::operator*(const A& obj)
{
	A result(rows, obj.cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < obj.cols; ++j) {
			result.data[i][j] = 0;
			for (int k = 0; k < cols; ++k) {
				result.data[i][j] += data[i][k] * obj.data[k][j];
			}
		}
	}
	return result;
}

inline A A::operator*(const int num)
{
	A result(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			result.data[i][j] = data[i][j] * num;
		}
	}
	return result;
}

inline A A::operator/(const A& obj)
{
	A result(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			result.data[i][j] = data[i][j] / obj.data[i][j];
		}
	}
	return result;
}

inline A A::operator/(const int num)
{
	A result(rows, cols);
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			result.data[i][j] = data[i][j] / num;
		}
	}
	return result;
}

inline A& A::operator=(const A& obj)
{
	rows = obj.rows;
	cols = obj.cols;
	data = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		data[i] = new int[cols]();
		for (int j = 0; j < cols; ++j) {
			data[i][j] = obj.data[i][j];
		}
	}

	return *this;
}

int main()
{
	Matrix<int> matrix1(5, 5);
	matrix1.RandInp();
	cout << "Matrix 1:" << endl;
	matrix1.Print();

	cout << endl << endl;

	Matrix<int> matrix2(5, 5);
	matrix2.RandInp();
	cout << "Matrix 2:" << endl;
	matrix2.Print();

	cout << endl << endl;

	Matrix<int> rezOfMatrix = matrix1 + matrix2;
	cout << "Sum of matrices:" << endl;
	rezOfMatrix.Print();

	cout << endl << endl;

	Matrix<int> rezOfMatrix1 = matrix1 - matrix2;
	cout << "Minus of matrices:" << endl;
	rezOfMatrix1.Print();

	cout << endl << endl;

	Matrix<int> rezOfMatrix2 = matrix1 * matrix2;
	cout << "Multy of matrices:" << endl;
	rezOfMatrix2.Print();

	cout << endl << endl;

	Matrix<int> rezSum = matrix1 + 10;
	cout << "Matrix1 + 10:" << endl;
	rezSum.Print();

	cout << endl << endl;

	Matrix<int> rezMinus = matrix1 - 10;
	cout << "Matrix1 - 10:" << endl;
	rezMinus.Print();

	cout << endl << endl;

	Matrix<int> rezMulty = matrix1 * 10;
	cout << "Matrix1 * 10:" << endl;
	rezMulty.Print();

	cout << endl << endl;

	Matrix<int> rezDevine = matrix1 / 10;
	cout << "Matrix1 / 10:" << endl;
	rezDevine.Print();

	cout << endl << endl;

	int index = 0, index1 = 0;
	matrix1.SearchMax(index, index1);
	cout << "Maximum element: " << matrix1.GetData()[index][index1] << " at row " << index << " and column " << index1 << endl;

	cout << endl << endl;

	matrix1.SearchMin(index, index1);
	cout << "Minimum element: " << matrix1.GetData()[index][index1] << " at row " << index << " and column " << index1 << endl;


	return 0;
}