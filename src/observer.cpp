#include "observer.hpp"

#include "verembalsesdebug.h"

/**
  * The subscription management methods.
  */
void Subject::attach(IObserver *observer) {
    list_observer_.push_back(observer);
}
  
void Subject::detach(IObserver *observer) {
    list_observer_.remove(observer);
}

void Subject::notify() {
    std::list<IObserver *>::iterator iterator = list_observer_.begin();
    
    while (iterator != list_observer_.end()) {
        (*iterator)->updateObserver(message_);
        ++iterator;
    }
}

void Subject::updateToObservers(std::string message) {
    this->message_ = message;
    notify();
}

Subject::~Subject() {
    qCDebug(VEREMBALSES) << "Goodbye, I was the Subject.";
}
