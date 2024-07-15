#include "GlobalMessageQueue.hpp"

GlobalMessageQueue::GlobalMessageQueue()
{
    message_vector = {};
}

void GlobalMessageQueue::push_new_message(string message)
{
    shared_lock.lock();
    message_vector.push_back(message);
    notify();
    shared_lock.unlock();
}

string GlobalMessageQueue::pull_new_message()
{
    string message = message_vector.back();
    return message;
}