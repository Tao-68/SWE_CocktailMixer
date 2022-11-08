//@(#) Subject.h

#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include "Observer.h"

#include <vector>
#include <iostream>
/**
 * @class Subject
 *
 * @brief Subject notifies the observers
 *
 * Subject (Waage) notifies the observers (Dispenser and Drainer).
 * The observers will be updated.
 */
class Subject {
public:

    /** @brief Adds observer to the observers list
    * @param [in] observer the observer to be added
    */
    void attach(Observer * observer);

    /** @brief Removes observer from the observers list
    * @param [in] observer the observer to be removed
    */
    void detach(Observer * observer);

    /**
    * @brief Notifies the observers
    */
    void notify();

private:

    std::vector<Observer *> observers;

};

#endif
