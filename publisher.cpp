#include "client/Client.hpp"
#include <iostream>

int main()
{
    std::system("cls");
    ClientPublisher client("TOPIC");
    client.connect("127.0.0.1", "88");

    for (;;)
    {
        string test;
        std::getline(std::cin, test);
        test += "\n";
        client.push_new_message(test);
    }
    return 0;
}