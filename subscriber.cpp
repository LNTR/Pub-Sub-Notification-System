#include "client/Client.hpp"

int main()
{
    std::system("cls");
    ClientSubscriber client("TOPIC");
    client.connect("127.0.0.1", "88");
    for (;;)
    {
        string message = client.pull_new_message();
        std::cout << message;
    }
    return 0;
}