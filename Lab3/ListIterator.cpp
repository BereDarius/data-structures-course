#include "ListIterator.h"
#include "IndexedList.h"
#include <exception>

using namespace std;

ListIterator::ListIterator(const IndexedList& list) : list(list){
    this->current = this->list.head;
}

void ListIterator::first(){
    this->current = this->list.head;
}

void ListIterator::next(){
    if (this->current == -1) {
        throw exception();
    }
    this->current = this->list.next[this->current - 1];
}

bool ListIterator::valid() const{
    return this->current != -1;
}

TElem ListIterator::getCurrent() const{
    if (!this->valid()) {
        throw exception();
    }
    return this->list.elements[this->current - 1];
}