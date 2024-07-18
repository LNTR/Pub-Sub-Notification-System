#include <iostream>
#include <sstream>
#include <boost/asio.hpp>
#include <array>
#include <chrono>
#include <thread>

namespace asio = boost::asio;
namespace ip = asio::ip;

using std::string, std::array, std::cout, std::thread, std::cin;
void handle_client(ip::tcp::socket socket)
{
    boost::system::error_code error_code;
    auto thread_id = std::this_thread::get_id();
    std::stringstream stream;
    stream << thread_id;
    string message = "This is from server thread " + stream.str() + "\n";
    array<char, 1024> char_buffer;

    asio::mutable_buffer buffer = asio::buffer(char_buffer, message.length());
    socket.write_some(buffer, error_code);
    for (;;)
    {
        std::getline(cin, message);
        message += "\n";
        asio::mutable_buffer buffer = asio::buffer(message, message.length());
        socket.write_some(buffer, error_code);
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
        // thread connection(handle_client, std::move(socket));
        handle_client(std::move(socket));
        // connection.detach();
    }
}