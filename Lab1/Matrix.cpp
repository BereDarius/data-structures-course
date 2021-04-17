#include "Matrix.h"
#include <exception>

using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
	this->lines = nrLines;
	this->columns = nrCols;
	this->size = 0;
	this->capacity = nrCols * nrLines;
	this->elements = new TElem[this->capacity];
    this->rows = new TElem[this->capacity];
	this->cols = new TElem[this->capacity];
    // O(nrLines * nrCols)
}


int Matrix::nrLines() const {
	return this->lines;
	// O(1)
}


int Matrix::nrColumns() const {
	return this->columns;
    // O(1)
}


TElem Matrix::element(int i, int j) const {
    if (i < 0 || i > this->lines || j < 0 || j > this->columns) {
        throw exception();
    }
	for (int k = 0; k < this->size; k++) {
        if (this->rows[k] == i && this->cols[k] == j) {
            return this->elements[k];
        }
	}
	return NULL_TELEM;
}

TElem Matrix::modify(int i, int j, TElem e) {
    if (i < 0 || i > this->lines || j < 0 || j > this->columns) {
        throw exception();
    }
    TElem previous = this->element(i, j);
    if (this->element(i, j) == NULL_TELEM && e != NULL_TELEM) {
        this->rows[this->size] = i;
        this->cols[this->size] = j;
        this->elements[this->size] = e;
        this->size++;
    } else if (this->element(i, j) != NULL_TELEM && e == NULL_TELEM) {
        for (int k = 0; k < this->size; k++) {
            if (this->rows[k] == i && this->cols[k] == j) {
                this->elements[k] = NULL_TELEM;
            }
        }
        this->size--;
    } else if (this->element(i, j) != NULL_TELEM && e != NULL_TELEM) {
        for (int k = 0; k < this->size; k++) {
            if (this->rows[k] == i && this->cols[k] == j) {
                this->elements[k] = e;
            }
        }
    }
    return previous;
}


