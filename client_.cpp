#include <iostream>
#include <boost/asio.hpp>
#include <vector>
#include <chrono>
#include <conio.h>
#include <thread>
#include <boost/regex.hpp>
namespace asio = boost::asio;
namespace ip = asio::ip;

using std::string, std::array, std::cout, std::vector;

int main()
{
    std::system("cls");
    boost::system::error_code error_code;
    asio::io_context io_context;
    ip::address server_address = ip::make_address("127.0.0.1");
    ip::port_type server_port = ip::port_type(334);
    ip::tcp::endpoint endpoint(server_address, server_port);
    ip::tcp::socket socket(io_context);
    socket.connect(endpoint);
    array<char, 1024> char_buffer;
    asio::mutable_buffer buffer = asio::buffer(char_buffer, 1024);
    for (;;)
    {
        int char_count = socket.read_some(buffer, error_code);
        string message(char_buffer.begin(), char_count);
        cout << message;
    }
    cout << "Hello from Client\n";
}