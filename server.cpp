#include <iostream>
#include <sstream>
#include <boost/asio.hpp>
#include <array>
#include <chrono>
#include <thread>

namespace asio = boost::asio;
namespace ip = asio::ip;

using std::string, std::array, std::cout, std::thread;
void handle_client(ip::tcp::socket socket)
{
    auto thread_id = std::this_thread::get_id();
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::stringstream stream;
    stream << thread_id;
    string message = "This is from server thread " + stream.str() + "\n";
    auto buffer = asio::buffer(message, message.length());
    int bytes = socket.write_some(buffer);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    cout << "Thread ended\n";
}
int main()
{
    asio::io_context io_context;
    ip::address address = ip::make_address("127.0.0.1");
    ip::port_type port = ip::port_type(334);

    ip::tcp::endpoint endpoint(address, port);

    ip::tcp::acceptor acceptor(io_context, endpoint);
    ip::tcp::socket socket(io_context);
    for (;;)
    {
        acceptor.accept(socket);
        thread connection(handle_client, std::move(socket));
        connection.detach();
    }
}