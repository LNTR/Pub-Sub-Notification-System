#include "Observer.hpp"
#include <unordered_set>
using std::unordered_set;
class Subject
{

public:
    virtual ~Subject();
    virtual void attach(Observer *);
    virtual void detach(Observer *);
    virtual void notify();

protected:
    Subject();

private:
    unordered_set<Observer *> _observers;
};
