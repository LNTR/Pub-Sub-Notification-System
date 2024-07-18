#include "server/Server.hpp"
#include <thread>
#include <iostream>

using std::thread, std::cout;

GlobalMessageQueue global_message_queue;

void handle_publisher(ServerPublisher publisher)
{
    for (;;)
    {
        publisher.read_new_message();
    }
}

void handle_subscriber(ServerSubscriber subscriber)
{
    global_message_queue.attach(&subscriber);
    for (;;)
    {
    }
}

int main()
{
    std::system("cls");

    asio::io_context io_context;
    ip::address address = ip::make_address("127.0.0.1");
    ip::port_type port = ip::port_type(88);

    ip::tcp::endpoint endpoint(address, port);

    ip::tcp::acceptor acceptor(io_context, endpoint);

    ip::tcp::socket socket(io_context);

    for (;;)
    {
        acceptor.accept(socket);
        if (is_publisher(socket))
        {
            ServerPublisher publisher("TOPIC2", std::move(socket), &global_message_queue);
            thread connection(handle_publisher, std::move(publisher));
            connection.detach();
        }
        else
        {
            ServerSubscriber subscriber("TOPIC1", std::move(socket), &global_message_queue);
            thread connection(handle_subscriber, std::move(subscriber));
            connection.detach();
        }
    }
}