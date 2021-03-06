//! @file 
//! @brief Header file for the Subject prototype class 
//!

#pragma once
#include "Observer.h"
#include <list>
using namespace std;

//Needs to have a forward reference due to 
//circular reference between Observer and Subject
class Observer;

//!  Subject prototype class
/*!
Prototype for Character class subject functionality. Ensures compatibility with CharacterObserver class.
*/
class Subject {
  public:
	virtual void Attach(Observer* o);
	virtual void Detach(Observer* o);
	virtual void Notify();
	Subject();
	~Subject();
  private:
	list<Observer*> *_observers;
};
