#include <iostream>
#include <unordered_map>
#include "Server.hpp"

using std::string, std::cout, std::cin;

ServerPublisher::ServerPublisher(string topic, ip::tcp::socket socket_, GlobalMessageQueue *global_message_queue) : socket(std::move(socket_))
{
    this->topic = topic;
    this->global_message_queue = global_message_queue;
};

void ServerPublisher::read_new_message()
{
    array<char, 1024> char_buffer;
    boost::system::error_code error_code;
    asio::mutable_buffer buffer = asio::buffer(char_buffer, 1024);
    int char_count = socket.read_some(buffer, error_code);
    string message(char_buffer.begin(), char_count);

    if (message.length() > 1)
    {
        publish_message(message);
    }
}

void ServerPublisher::publish_message(string message)
{
    Aspect aspect = {topic, message};
    global_message_queue->push_new_message(aspect);
}

ServerSubscriber::ServerSubscriber(string topic, ip::tcp::socket socket_, GlobalMessageQueue *global_message_queue) : socket(std::move(socket_))
{
    this->topic = topic;
    this->global_message_queue = global_message_queue;
}

string ServerSubscriber::get_topic()
{
    return topic;
}

void ServerSubscriber::update(Subject *changed_subject)
{
    if (global_message_queue == changed_subject)
    {
        boost::system::error_code error_code;

        Aspect new_message = global_message_queue->pull_new_message();

        if (new_message.topic == topic)
        {
            asio::mutable_buffer buffer = asio::buffer(new_message.message, new_message.message.length());
            socket.write_some(buffer, error_code);
        }
    }
}

bool is_publisher(ip::tcp::socket &socket)
{

    array<char, 1024> char_buffer;
    boost::system::error_code error_code;
    asio::mutable_buffer buffer = asio::buffer(char_buffer, 1024);
    int char_count = socket.read_some(buffer, error_code);
    string message(char_buffer.begin(), char_count);
    if (message == "1")
    {
        return true;
    }
    return false;
}