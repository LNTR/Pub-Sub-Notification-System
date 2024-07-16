#include <string>
#include <vector>
#include <unordered_set>
#include "ObserverPattern.hpp"

using std::string, std::vector, std::unordered_set;

class GlobalMessageQueue : public Subject
{

public:
    GlobalMessageQueue();

    void push_new_message(string message);
    string pull_new_message();

private:
    vector<string> message_queue;
};
