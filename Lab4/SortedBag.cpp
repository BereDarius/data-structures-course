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
    // Complexity: Theta(n)
}

void SortedBag::add(TComp e) {
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
    if (this->loadFactor > 0.75) {
        this->rehash();
    }
    // Complexity: Theta(n)
}


bool SortedBag::remove(TComp e) {
    int key = this->hash(e);
    int previous = key;
    while (key != -1 && this->elements[key] != e) {
        previous = key;
        key = this->keys[key];
    }
    if (key == -1) {
        return false;
    } else {
        bool over = false;
        int p;
        int pp;
        do {
            p = this->keys[key];
            pp = key;
            while (p != -1 && this->hash(this->elements[p]) != key) {
                pp = p;
                p = this->keys[p];
            }
            if (p == -1) {
                over = true;
            } else {
                this->elements[key] = this->elements[p];
                previous = pp;
                key = p;
            }
        } while (!over);
        if (previous == -1) {
            int index = 0;
            while (index < this->capacity && previous == -1) {
                if (this->keys[index] == key) {
                    previous = index;
                } else {
                    index++;
                }
            }
        }
        if (previous == -1) {
            this->keys[previous] = this->keys[key];
        }
        this->elements[key] = NULL_TELEM;
        this->keys[key] = -1;
        this->numElements--;
        this->numBuckets++;
        return true;
    }
    // Complexity: Theta(n)
}


bool SortedBag::search(TComp elem) const {
    int key = this->hash(elem);
    if (this->elements[key] == NULL_TELEM) {
        return false;
    }
    while (key != -1) {
        if (this->elements[key] == elem) {
            return true;
        }
        key = this->keys[key];
    }
    return false;
    // Complexity: Theta(n)
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
    // Complexity: Theta(n)
}



int SortedBag::size() const {
	return this->numElements;
	// Complexity: Theta(1)
}


bool SortedBag::isEmpty() const {
	return this->numElements == 0;
	// Complexity: Theta(1)
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
    //return floor(this->numBuckets * (elem * 0.61803398875 - floor(elem * 0.61803398875)));
    return abs(elem % this->capacity);
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
    // Complexity: Theta(n)
}