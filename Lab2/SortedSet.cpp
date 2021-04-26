#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
    this->elements = new SLLNode;
    this->elements->next = nullptr;
    this->elements->info = NULL_TELEM;
    this->relation = r;
}


bool SortedSet::add(TComp elem) {
    SLLNode* current = this->elements;
    auto newElem = new SLLNode;
    newElem->info = elem;
    if (this->isEmpty()) {
        this->elements->info = elem;
        this->elements->next = nullptr;
        return true;
    }
    if (this->relation(elem, this->elements->info)) {
        if (this->elements->info == elem) {
            return false;
        }
        newElem->next = this->elements;
        this->elements = newElem;
        return true;
    }
    while (current->next != nullptr) {
        SLLNode* previous = current;
        current = current->next;
        if (current->info == elem) {
            return false;
        }
        if (this->relation(elem, current->info)) {
            previous->next = newElem;
            newElem->next = current;
            return true;
        }
    }
    if (current->next == nullptr) {
        if (this->relation(current->info, elem)) {
            if (current->info == elem) {
                return false;
            }
            current->next = newElem;
            newElem->next = nullptr;
            return true;
        }
    }
    return false;
}

bool SortedSet::remove(TComp elem) {
    if (this->isEmpty()) {
        return false;
    }
    if (this->size() == 1) {
        if (this->elements->info == elem) {
            this->elements->info = NULL_TELEM;
            return true;
        }
    }
    if (this->elements->info == elem) {
        this->elements = this->elements->next;
        return true;
    }
    SLLNode* current = this->elements;
    while (current->next != nullptr) {
        SLLNode* previous = current;
        current = current->next;
        if (current->info == elem) {
            previous->next = current->next;
            return true;
        }
    }
    return false;
}


bool SortedSet::search(TComp elem) const {
    SLLNode* current = this->elements;
    while (current->next != nullptr && current->info != elem) {
        current = current->next;
    }
    if (current->next == nullptr) {
        if (current->info == elem) {
            return true;
        } else {
            return false;
        }
    }
    return true;
}


int SortedSet::size() const {
    if (this->elements == nullptr || this->elements->info == NULL_TELEM) {
        return 0;
    }
    int size = 0;
    SLLNode* current = this->elements;
    while(current != nullptr) {
        current = current->next;
        size++;
    }
	return size;
}



bool SortedSet::isEmpty() const {
    if (this->size() == 0) {
        return true;
    }
    return false;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}


SortedSet::~SortedSet() {
    SLLNode* current = this->elements;
    while(current != nullptr) {
        SLLNode* next = current->next;
        delete current;
        current = next;
    }
}


