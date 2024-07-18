#ifndef OBSERVER_PATTERN
#define OBSERVER_PATTERN
#include "ObserverPattern.hpp"
#endif

#include <string>
#include <vector>
#include <unordered_set>

using std::string, std::vector, std::unordered_set;

class GlobalMessageQueue : public Subject
{

public:
    GlobalMessageQueue();
    void push_new_message(Aspect);
    Aspect pull_new_message();

private:
    vector<Aspect> message_queue;
};
