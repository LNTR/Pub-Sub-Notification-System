#include "client/Client.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    std::system("cls");

    string ip = argv[1];
    string port = argv[2];
    string topic = argv[3];

    ClientPublisher client(topic);
    client.connect(ip, port);

    for (;;)
    {
        string test;
        std::getline(std::cin, test);
        test += "\n";
        client.push_new_message(test);
    }
    return 0;
}