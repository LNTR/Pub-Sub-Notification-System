#include "GlobalMessageQueue.hpp"

GlobalMessageQueue::GlobalMessageQueue()
{
    message_queue = {};
}

void GlobalMessageQueue::push_new_message(string message)
{
    shared_lock.lock();
    message_queue.push_back(message);
    notify();
    shared_lock.unlock();
}

string GlobalMessageQueue::pull_new_message()
{
    string message = message_queue.back();
    return message;
}