#ifndef GLOBAL_MESSAGE_QUEUE
#define GLOBAL_MESSAGE_QUEUE
#include "GlobalMessageQueue.hpp"
#endif

GlobalMessageQueue::GlobalMessageQueue()
{
    message_queue = {};
}

void GlobalMessageQueue::push_new_message(Aspect aspect)
{
    shared_lock.lock();
    message_queue.push_back(aspect);
    notify();
    shared_lock.unlock();
}

Aspect GlobalMessageQueue::pull_new_message()
{
    Aspect aspect = message_queue.back();
    return aspect;
}