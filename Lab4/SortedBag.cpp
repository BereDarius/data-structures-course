#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <cmath>

SortedBag::SortedBag(Relation r) {
    this->relation = r;
    this->capacity = 20;
    this->elements = new TElem[this->capacity];
    this->keys = new int[this->capacity];
    this->numElements = 0;
    this->loadFactor = 0;
}

void SortedBag::add(TComp e) {
    if (this->loadFactor > 0.75) {
        this->rehash();
    }
    int key = this->hash(e);
    int index = -1;
    if (this->elements[key] != -842150451) {
        for (int i = this->numBuckets - 1; i > 0; i--) {
            if (this->elements[i] == -842150451) {
                this->elements[i] = e;
                index = i;
                break;
            }
        }
        this->numElements++;
    } else {
        this->elements[key] = e;
        this->numElements++;
        this->numBuckets++;
    }
    while (this->keys[key] != -842150451) {
        key = this->keys[key];
    }
    this->keys[key] = index;
    this->loadFactor = (float)this->numElements / (float)this->numBuckets;
}


bool SortedBag::remove(TComp e) {

}


bool SortedBag::search(TComp elem) const {
	//TODO - Implementation
	return false;
}


int SortedBag::nrOccurrences(TComp elem) const {
	//TODO - Implementation
	return 0;
}



int SortedBag::size() const {
	return this->numElements;
}


bool SortedBag::isEmpty() const {
	//TODO - Implementation
	return false;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	//TODO - Implementation
}

int SortedBag::hash(TElem elem) {
    //Multiplication method
    return floor(this->numBuckets * (elem * 0.61803398875 - floor(elem * 0.61803398875)));
}

void SortedBag::rehash() {
    this->capacity = this->capacity * 2;

}