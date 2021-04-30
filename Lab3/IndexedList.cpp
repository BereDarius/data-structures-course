#include <exception>

#include "IndexedList.h"
#include "ListIterator.h"

using namespace std;

IndexedList::IndexedList() {
    this->capacity = 20;
    this->elements = new TElem[this->capacity];
    this->next = new int[this->capacity];
    this->head = -1;
    for (int i = 0; i < this->capacity - 1; i++) {
        this->next[i] = i+1;
    }
    this->next[capacity - 1] = -1;
    this->firstEmpty = 1;

    // COMPLEXITY: theta(capacity)

}

int IndexedList::size() const {
    if (this->isEmpty())
        return 0;
    int count = 0;
    int index = this->head;
    while (this->next[index - 1] != -1) {
        count++;
        index = this->next[index - 1];
    }
    return count + 1;

    // COMPLEXITY: O(n)

}


bool IndexedList::isEmpty() const {
	return this->head == -1;

	// COMPLEXITY: O(1)

}

TElem IndexedList::getElement(int pos) const {
    if (pos < 0 || pos >= this->size()) {
        throw exception();
    }
    if (pos == 0) {
        return this->elements[this->head - 1];
    }
    int index = this->head;
    for (int i = 0; i < pos; i++) {
        index = this->next[index - 1];
    }
    return this->elements[index - 1];

    // COMPLEXITY: O(n)

}

TElem IndexedList::setElement(int pos, TElem e) {
    if (pos < 0 || pos >= this->size()) {
        throw exception();
    }
    TElem previous;
    if (pos == 0) {
        previous = this->elements[this->head - 1];
        this->elements[this->head - 1] = e;
        return previous;
    }
    int index = this->head;
    for (int i = 0; i < pos; i++) {
        index = this->next[index - 1];
    }
    previous = this->elements[index - 1];
    this->elements[index - 1] = e;
    return previous;

    // COMPLEXITY: O(n)

}

void IndexedList::addToEnd(TElem e) {
    if (this->isEmpty()) {
        this->addToPosition(0, e);
    } else {
        if (this->firstEmpty == -1) {
            this->resize();
        }
        int current = this->head;
        int previous;
        while (current != -1) {
            previous = current;
            current = this->next[current - 1];
        }
        this->next[previous - 1] = this->firstEmpty;
        this->elements[this->firstEmpty - 1] = e;
        this->next[this->firstEmpty - 1] = current;
        this->firstEmpty = this->next[this->firstEmpty];
    }

    // COMPLEXITY: O(n)

}

void IndexedList::addToPosition(int pos, TElem e) {
    if (pos < 0 || (pos >= this->size() && this->size() > 0)) {
        throw exception();
    }
    if (this->firstEmpty == -1) {
        this->resize();
    }
    if (pos == 0) {
        //INSERT FIRST
        int newPosition = this->firstEmpty;
        this->elements[newPosition - 1] = e;
        this->firstEmpty = this->next[firstEmpty];
        this->next[newPosition - 1] = this->head;
        this->head = newPosition;
    } else {
        int currentPosition = 0;
        int currentNode = this->head;
        while (currentNode != -1 && currentPosition < pos - 1) {
            currentPosition++;
            currentNode = this->next[currentNode - 1];
        }
        if (currentNode != -1) {
            int newElement = this->firstEmpty;
            this->firstEmpty = this->next[this->firstEmpty];
            this->elements[newElement - 1] = e;
            this->next[newElement - 1] = this->next[currentNode - 1];
            this->next[currentNode - 1] = newElement;
        }
    }

    // COMPLEXITY: O(n)

}

TElem IndexedList::remove(int pos) {
    if (pos < 0 || pos >= this->size()) {
        throw exception();
    }
    TElem previous;
    if (pos == 0) {
        previous = this->elements[this->head - 1];
        this->head = this->next[this->head - 1];
        return previous;
    }
    int currentNode = this->head;
    int previousNode;
    for (int i = 0; i < pos; i++) {
        previousNode = currentNode;
        currentNode = this->next[currentNode - 1];
    }
    previous = this->elements[currentNode - 1];
    this->next[previousNode - 1] = this->next[currentNode - 1];
    return previous;

    // COMPLEXITY: O(n)

}

int IndexedList::search(TElem e) const{
    int current = this->head;
    int count = 0;
    while(current != -1 && this->elements[current - 1] != e) {
        count++;
        current = next[current - 1];
    }
    if (current != -1) {
        return count;
    } else {
        return -1;
    }

    // COMPLEXITY: O(n)

}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);
}

IndexedList::~IndexedList() {
    delete[] this->elements;
    delete[] this->next;
}


void IndexedList::resize() {
    auto newElems = new TElem[this->capacity * 2];
    auto newNext = new int[this->capacity * 2];
    for (int i = 0; i < this->capacity; i++) {
        newElems[i] = this->elements[i];
        newNext[i] = this->next[i];
    }
    for (int i = this->capacity - 1; i < this->capacity * 2 - 1; i++) {
        newNext[i] = i + 1;
    }
    newNext[capacity * 2 - 1] = -1;
    this->elements = newElems;
    this->next = newNext;
    this->firstEmpty = this->capacity + 1;
    this->capacity = this->capacity * 2;
}