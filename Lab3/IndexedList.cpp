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
}


bool IndexedList::isEmpty() const {
	return this->head == -1;
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
}

void IndexedList::addToEnd(TElem e) {
    if (this->isEmpty()) {
        this->addToPosition(0, e);
    } else {
        this->addToPosition(this->size() - 1, e);
    }
}

void IndexedList::addToPosition(int pos, TElem e) {
    if (pos < 0 || pos > this->size()) {
        throw exception();
    }
    if (this->firstEmpty == -1) {
        //RESIZE
        auto newElems = new TElem[this->capacity * 2];
        auto newNext = new int[this->capacity * 2];
        for (int i = 0; i < this->capacity; i++) {
            newElems[i] = this->elements[i];
            newNext[i] = this->next[i];
        }
        for (int i = this->capacity; i < this->capacity * 2 - 1; i++) {
            newNext[i] = i + 1;
        }
        newNext[capacity * 2 - 1] = -1;
        this->elements = newElems;
        this->next = newNext;
        this->firstEmpty = this->capacity + 1;
        this->capacity = this->capacity * 2;
    }
    if (pos == 0) {
        //INSERT FIRST
        this->next[this->firstEmpty - 1] = this->head;
        this->elements[this->firstEmpty - 1] = e;
        this->head = this->firstEmpty;
        this->firstEmpty = this->next[this->firstEmpty];
    } else {
        int current = this->head;
        int previous;
        for (int i = 0; i < pos; i++) {
            previous = current;
            current = this->next[current - 1];
        }
        this->next[this->firstEmpty - 1] = current;
        this->elements[this->firstEmpty - 1] = e;
        this->next[previous - 1] = firstEmpty;
        this->firstEmpty = this->next[this->firstEmpty];
    }
    if (this->size() == this->capacity) {
        this->firstEmpty = -1;
    }
}

TElem IndexedList::remove(int pos) {
    if (pos < 0 || pos >= this->size()) {
        throw exception();
    }
    int current = this->head;
    TElem removed;
    if (pos == 0) {
        removed = this->elements[this->head - 1];
        this->head = this->next[this->head - 1];
    } else {
        for (int i = 0; i < pos - 1; i++) {
            current = this->next[current - 1];
        }
        removed = this->elements[current - 1];
        this->next[current - 1] = this->next[this->next[current - 1]];
        this->next[this->next[current - 1]] = firstEmpty;
        this->firstEmpty = this->next[current];
    }
    return removed;
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
}

ListIterator IndexedList::iterator() const {
    return ListIterator(*this);
}

IndexedList::~IndexedList() {
    delete[] this->elements;
    delete[] this->next;
}