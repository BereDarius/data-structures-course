#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    this->elements = new int[b.numElements];
    int index = 0;
    for (int i = 0; i < b.capacity; i++) {
        if (b.elements[i] != NULL_TELEM) {
            this->elements[index] = b.elements[i];
            index++;
        }
    }
    // Bubble sort algorithm for sorting the elements array
    TElem temp;
    for (int i = 0; i < b.numElements - 1; i++) {
        for (int j = 0; j < b.numElements - i - 1; j++) {
            if (b.relation(this->elements[j], this->elements[j + 1])) {
                temp = this->elements[j];
                this->elements[j] = this->elements[j+1];
                this->elements[j+1] = temp;
            }
        }
    }
    this->current = 0;
    // COMPLEXITY: O(n^2)
}

TComp SortedBagIterator::getCurrent() {
    if (!this->valid()) {
        throw exception();
    }
	return this->elements[this->current];
}

bool SortedBagIterator::valid() {
    return this->current < this->bag.numElements;
}

void SortedBagIterator::next() {
    if (!this->valid()) {
        throw exception();
    }
    this->current++;
}

void SortedBagIterator::first() {
    this->current = 0;
}

