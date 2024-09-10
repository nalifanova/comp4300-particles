#include <iostream>

#include "Application.hpp"

int main()
{
    std::cout << "Hello, Particles!" << std::endl;
    auto app = Application();
    app.run();

    return 0;
}
