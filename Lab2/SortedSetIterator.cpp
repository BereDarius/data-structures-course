#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
    this->current = m.elements;
}


void SortedSetIterator::first() {
    this->current = this->multime.elements;
}


void SortedSetIterator::next() {
    if (!this->valid()) {
        throw exception();
    }
    this->current = this->current->next;
}


TElem SortedSetIterator::getCurrent()
{
    if (!this->valid()) {
        throw exception();
    }
    return this->current->info;
}

bool SortedSetIterator::valid() const {
    if (this->current == nullptr || this->current->info == NULL_TELEM) {
        return false;
    }
    return true;
}

