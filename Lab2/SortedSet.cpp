#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
    this->elements = new SLLNode;
    this->elements->next = nullptr;
    this->elements->info = NULL_TELEM;
    this->relation = r;
}


bool SortedSet::add(TComp elem) {
    if (this->size() == 0) {
        this->elements->info = elem;
        return true;
    }
    SLLNode *current = this->elements;
    SLLNode *aux = current;
    if (this->relation(elem, current->info)) {
        aux->info = elem;
        aux->next = current;
        this->elements = aux;
        return true;
    }
    while (current->next != nullptr) {
        if (current->info == elem) {
            return false;
        } else if (this->relation(elem, current->info)) {
            aux->info = elem;
            aux->next = current->next;
            current->next = aux;
        }
        current = current->next;
    }
    if (current->info == elem) {
        return false;
    }
    if (current->next == nullptr) {
        if (this->relation(elem, current->info)) {
            TElem previous = current->info;
            current->info = elem;
            current->next = new SLLNode;
            current->next->info = previous;
            current->next->next = nullptr;
        } else {
            current->next = new SLLNode;
            current->next->info = elem;
            current->next->next = nullptr;
        }
    }
    return true;
}

bool SortedSet::remove(TComp elem) {
    SLLNode* current = this->elements;
    while (current->next != nullptr && current->next->info != elem) {
        current = current->next;
    }
    if (current->next == nullptr) {
        return false;
    } else {
        current->next = current->next->next;
        return true;
    }
}


bool SortedSet::search(TComp elem) const {
    SLLNode* current = this->elements;
    while (current->next != nullptr && current->next->info != elem) {
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
    if (this->elements->info == NULL_TELEM) {
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
    if (this->elements->info == NULL_TELEM && this->elements->next == nullptr) {
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


