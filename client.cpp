#include "Client.hpp"

Client::Client(string topic, ClientType type) : io_context(), socket(io_context)
{
    this->type = type;
    this->topic = topic;
}

void Client::connect(string ip, string port)
{
    ip::address server_address = ip::make_address(ip);
    ip::port_type server_port = ip::port_type(std::stoi(port));
    ip::tcp::endpoint endpoint(server_address, server_port);
    socket.connect(endpoint);
}

void Client::disconnect()
{
    socket.close();
}
