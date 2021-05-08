#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <cmath>

SortedBag::SortedBag(Relation r) {
    this->relation = r;
    this->capacity = 20;
    this->elements = new TElem[this->capacity];
    for (int i = 0; i < this->capacity; i++) {
        this->elements[i] = NULL_TELEM;
    }
    this->keys = new int[this->capacity];
    for (int j = 0; j < this->capacity; j++) {
        this->keys[j] = -1;
    }
    this->numElements = 0;
    this->numBuckets = this->capacity;
    this->loadFactor = 0;
}

void SortedBag::add(TComp e) {
    if (this->loadFactor > 0.75) {
        this->rehash();
    }
    int key = this->hash(e);
    int index = -1;
    if (this->elements[key] == NULL_TELEM) {
        this->elements[key] = e;
        this->numElements++;
    } else {
        for (int i = this->capacity - 1; i > 0; i--) {
            if (this->elements[i] == NULL_TELEM) {
                this->elements[i] = e;
                index = i;
                break;
            }
        }
        while (keys[key] != -1) {
            key = this->keys[key];
        }
        keys[key] = index;
        this->numElements++;
        this->numBuckets--;
    }
    this->loadFactor = (float)this->numElements / (float)this->numBuckets;
}


bool SortedBag::remove(TComp e) {
    int key = this->hash(e);
    if (this->elements[key] == NULL_TELEM) {
        return false;
    }
    if (this->keys[key] == -1) {
        this->elements[key] = NULL_TELEM;
        this->numElements--;
        this->loadFactor = (float)this->numElements / (float)this->numBuckets;
        return true;
    } else {
        int previous = key;
        while (this->elements[key] != e) {
            previous = key;
            key = this->keys[key];
        }
        this->elements[key] = NULL_TELEM;
        this->keys[previous] = this->keys[key];
        this->keys[key] = -1;
        this->numElements--;
        this->numBuckets++;
        this->loadFactor = (float)this->numElements / (float)this->numBuckets;
        return true;
    }
}


bool SortedBag::search(TComp elem) const {
    int key = this->hash(elem);
    int e = this->elements[key];
    while (key != -1) {
        if (this->elements[key] == elem) {
            return true;
        }
        key = this->keys[key];
    }
	return false;
}


int SortedBag::nrOccurrences(TComp elem) const {
    int count = 0;
    int key = this->hash(elem);
    while (key != -1) {
        if (this->elements[key] == elem) {
            count++;
        }
        key = this->keys[key];
    }
	return count;
}



int SortedBag::size() const {
	return this->numElements;
}


bool SortedBag::isEmpty() const {
	return this->numElements == 0;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
    delete[] this->elements;
    delete[] this->keys;
}

int SortedBag::hash(TElem elem) const {
    //Multiplication method
    return floor(this->numBuckets * (elem * 0.61803398875 - floor(elem * 0.61803398875)));
}

void SortedBag::rehash() {
    int prevCapacity = this->capacity;
    auto prevElements = this->elements;
    this->capacity = this->capacity * 2;
    this->elements = new TElem[this->capacity];
    this->keys = new int[this->capacity];
    for (int i = 0; i < this->capacity; i++) {
        this->elements[i] = NULL_TELEM;
        this->keys[i] = -1;
    }
    this->numElements = 0;
    this->numBuckets = this->capacity;
    this->loadFactor = 0;
    for (int i = 0; i < prevCapacity; i++) {
        if (prevElements[i] != NULL_TELEM) {
            this->add(prevElements[i]);
        }
    }
}