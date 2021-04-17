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
    this->current = this->current->next;
}


TElem SortedSetIterator::getCurrent()
{
    return this->current->info;
}

bool SortedSetIterator::valid() const {
    return (this->current != nullptr);
}

