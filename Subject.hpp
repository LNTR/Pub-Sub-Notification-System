#include "Observer.hpp"
#include <unordered_set>
#include <mutex>
using std::unordered_set, std::mutex;
class Subject
{

public:
    virtual void attach(Observer *) = 0;
    virtual void detach(Observer *) = 0;
    virtual void notify() = 0;

protected:
    Subject(){};
    mutex shared_lock;

private:
    unordered_set<Observer *> _observers;
};
