#include "Matrix.h"
#include <exception>
#include <cstdlib>

using namespace std;


Matrix::Matrix(int nrLines, int nrCols) {
	this->lines = nrLines;
	this->columns = nrCols;
	if (nrLines < 0 || nrCols < 0) {
        throw exception();
    }
	SLLNode head { NULL_TELEM, nullptr };
	SLLNode* current = &head;
	for (int i = 0; i < nrLines; i++) {
        for (int j = 0; j < nrCols; j++) {
            if (i == 0 && j == 0) {
                this->elements.head = &head;
            } else {
                current->next = new SLLNode;
                current = current->next;
                current->value = NULL_TELEM;
                current->next = nullptr;
            }
        }
    }
	this->elements.head = head.next;
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
	if (i < 0 || j < 0 || i >= this->lines || j >= this->columns) {
	    throw exception();
	}
	SLLNode* node = this->elements.head;
	for (int row = 0; row < i; row++) {
	    for (int col = 0; col < j; col++) {
            node = node->next;
	    }
	}
	return node->value;
    // O(i * j)
}

TElem Matrix::modify(int i, int j, TElem e) {
    if (i < 0 || j < 0 || i >= this->lines || j >= this->columns) {
        throw exception();
    }
    SLLNode* head = this->elements.head;
    for (int row = 0; row < i; row++) {
        for (int col = 0; col < j; col++) {
            this->elements.head = this->elements.head->next;
        }
    }
    TElem previousValue = head->value;
    this->elements.head = head;
    return previousValue;
    // O(i * j)
}


