#ifndef __OBSERVER_HPP__
#define __OBSERVER_HPP__

#include <iostream>
#include <list>
#include <string>

class IObserver {
    public:
        virtual ~IObserver(){};
        virtual void updateObserver(const std::string &message) = 0;
};

class ISubject {
    public:
        virtual ~ISubject(){};
        virtual void attach(IObserver *observer) = 0;
        virtual void detach(IObserver *observer) = 0;
        virtual void notify() = 0;
};

/**
 * The Subject owns some important state and notifies observers when the state
 * changes.
 */

class Subject : public ISubject {
    public:
        virtual ~Subject();

        void attach(IObserver *observer) override;
        void detach(IObserver *observer) override;
        void notify() override;

        void updateToObservers(std::string message = "Empty");
  
        int numObservers() { return list_observer_.size(); }

    private:
        std::list<IObserver *> list_observer_;
        std::string message_;
};

#endif
