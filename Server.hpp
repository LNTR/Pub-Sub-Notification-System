#include <string>
#include "ObserverPattern.hpp"

class ServerPublisher
{

public:
    ServerPublisher(string topic);
    void publish_message(string message);

private:
    GlobalMessageQueue *global_message_queue;
    string topic;
};

class ServerSubscriber : public Observer
{
public:
    ServerSubscriber(string topic);
    string get_subscribed_topic();

    void update(Subject *changed_subject);

private:
    vector<string> subscriber_message_queue;
    GlobalMessageQueue *global_message_queue;
    string topic;
};
