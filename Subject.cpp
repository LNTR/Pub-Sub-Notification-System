#include "Observer.hpp"
#include "Subject.hpp"

void Subject::attach(Observer *observer)
{
    _observers.insert(observer);
}
void Subject::detach(Observer *observer)
{
    _observers.erase(observer);
}
void Subject::notify()
{
    for (Observer *observer : _observers)
    {
        observer->update(this);
    }
}