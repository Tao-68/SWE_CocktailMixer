//@(#) Observer.h

#ifndef OBSERVER_H_H
#define OBSERVER_H_H

/**
 * @class Observer
 * @brief This is an observer-class
 * It do nothing at the moment.
 */
class Observer {
public:
    /**
     * @brief This virtual methode is not declared.
     */
    virtual void update() = 0;

};

#endif
