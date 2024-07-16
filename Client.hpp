#include <iostream>
#include <boost/asio.hpp>
#include <vector>
#include <chrono>
#include <thread>
#include <string>
#include <array>
#include <boost/asio.hpp>

namespace asio = boost::asio;
namespace ip = asio::ip;

using std::string, std::vector, std::array;
enum ClientType
{
    publisher,
    subscriber
};
class Client
{
public:
    Client(string topic, ClientType type);
    ~Client();
    void connect(string ip, string port);
    void disconnect();

private:
    asio::io_context io_context;
    ip::tcp::socket socket;
    string topic;
    ClientType type;
    array<char, 1024> char_buffer;
};

class ClientPublisher : public Client
{
public:
    ClientPublisher(string topic);
    void publish_message(string message);
};
