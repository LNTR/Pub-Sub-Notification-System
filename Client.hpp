#include <iostream>
#include <boost/asio.hpp>
#include <vector>
#include <chrono>
#include <thread>
#include <string>
#include "Observer.hpp"
#include "GlobalMessageQueue.hpp"

namespace asio = boost::asio;
namespace ip = asio::ip;

using std::string, std::vector;

class Client
{
public:
    Client(string topic);
    ~Client();
    void connect(string ip, string port);
    void disconnect();
    string get_subscribed_topic();

private:
    string topic;
};

class Publisher : public Client
{
public:
    Publisher(string topic) : Client(topic){};
    void publish_message(Subject *subject);
};

class Subscriber : public Client, public Observer
{
public:
    Subscriber(string topic) : Client(topic){};
    void update(Subject *changed_subject) {

    };

private:
    GlobalMessageQueue *global_message_queue;
};
