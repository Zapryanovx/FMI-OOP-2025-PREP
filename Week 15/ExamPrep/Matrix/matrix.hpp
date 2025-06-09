#include <iostream>
#include <exception>

template <typename T>
class Matrix {

public:
	Matrix();
	Matrix(size_t rows, size_t cols);

	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);

	Matrix(Matrix&& other) noexcept;
	Matrix& operator=(Matrix&& other) noexcept;

	~Matrix();

	void setAt(unsigned int x, unsigned int y, const T& element);
	const T& getAt(unsigned int x, unsigned int y) const;

	void transpose();

private:
	T** matrix;
	size_t rows;
	size_t cols;

	void initMatrix(size_t rows, size_t cols);
	void copyFrom(const Matrix& other);
	void moveFrom(Matrix&& other);
	void free();
};

template <typename T>
Matrix<T>::Matrix() : Matrix<T>(2, 2) {}

template <typename T>
Matrix<T>::Matrix(size_t rows, size_t cols) {
	initMatrix(rows, cols);
}

template <typename T>
Matrix<T>::Matrix(const Matrix<T>& other) {
	copyFrom(other);
}

template <typename T>
Matrix<T>::Matrix(Matrix<T>&& other) noexcept {
	moveFrom(std::move(other));
}	

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	
	return *this;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template <typename T>
Matrix<T>::~Matrix() {
	free();
}

template <typename T>
void Matrix<T>::setAt(unsigned int x, unsigned int y, const T& element) {
	x--;
	y--;

	if (x >= rows || y >= cols) {
		throw std::out_of_range("exceeded matrix");
	}

	matrix[x][y] = element;
}

template <typename T>
const T& Matrix<T>::getAt(unsigned int x, unsigned int y) const {
	x--;
	y--;

	if (x >= rows || y >= cols) {
		throw std::out_of_range("invalid idx to get");
	}

	return matrix[x][y];
}

template <typename T>
void Matrix<T>::transpose() {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = i + 1; j < cols; j++) {
			std::swap(matrix[i][j], matrix[j][i]);
		}
	}
}

template <typename T>
void Matrix<T>::initMatrix(size_t rows, size_t cols) {
	matrix = new T * [rows];
	for (size_t j = 0; j < cols; j++) {
		matrix[j] = new T[cols]{};
	}

	this->rows = rows;
	this->cols = cols;
}

template <typename T>
void Matrix<T>::copyFrom(const Matrix& other) {
	matrix = new T * [other.rows];
	for (size_t i = 0; i < other.rows; i++) {
		matrix[i] = new T[other.cols]{};
		for (size_t j = 0; j < other.cols; j++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}

	rows = other.rows;
	cols = other.cols;
}

template <typename T>
void Matrix<T>::moveFrom(Matrix&& other) {

	matrix = other.matrix;
	other.matrix = nullptr;

	rows = other.rows;
	cols = other.cols;
	other.rows = other.cols = 0;
}

template <typename T>
void Matrix<T>::free() {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
		matrix[i] = nullptr;
	}

	delete[] matrix;
	matrix = nullptr;

	rows = cols = 0;
}

int main() {
	
	return 0;
}