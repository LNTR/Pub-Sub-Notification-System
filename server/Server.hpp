#include <string>
#include <array>
#include <boost/asio.hpp>
#include <list>

#ifndef GLOBAL_MESSAGE_QUEUE
#define GLOBAL_MESSAGE_QUEUE
#include "GlobalMessageQueue.hpp"
#endif

namespace asio = boost::asio;
namespace ip = asio::ip;

using std::string, std::array, std::list;

class ServerPublisher
{

public:
    ServerPublisher(string topic, ip::tcp::socket socket_, GlobalMessageQueue *);
    void read_new_message();
    void publish_message(string message);

private:
    GlobalMessageQueue *global_message_queue;
    string topic;
    ip::tcp::socket socket;
};

class ServerSubscriber : public Observer
{
public:
    ServerSubscriber(string topic, ip::tcp::socket socket_, GlobalMessageQueue *);
    string get_topic();
    void update(Subject *changed_subject);

private:
    GlobalMessageQueue *global_message_queue;
    string topic;
    ip::tcp::socket socket;
};

// Replace with factory method
bool is_publisher(ip::tcp::socket &socket);