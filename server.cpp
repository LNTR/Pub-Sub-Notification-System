#include "Server.hpp"
#include "GlobalMessageQueue.hpp"

using std::string;

ServerPublisher::ServerPublisher(string topic)
{
    this->topic = topic;
};

void ServerPublisher::publish_message(string message)
{
    global_message_queue->push_new_message(message);
}

void ServerSubscriber::update(Subject *changed_subject)
{
    if (global_message_queue == changed_subject)
    {
        string new_message = global_message_queue->pull_new_message();
        subscriber_message_queue.push_back(new_message);
    }
}