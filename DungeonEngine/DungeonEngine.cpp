// DungeonEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#if defined(IS_SERVER)
#include "Server/GameServer.h"
#elif defined(IS_EDITOR)
#include "GameEditor.h"
#elif defined(IS_CLIENT)
// Client-specific includes go here
#endif

int main() {
#if defined(IS_SERVER)
    GameServer server;
    server.start();
#elif defined(IS_EDITOR)
    GameEditor editor;
    editor.main();
#elif defined(IS_CLIENT)
    std::cout << "Hello from Client" << std::endl;
#else
    std::cerr << "Error: No valid application mode defined. Please define IS_SERVER, IS_EDITOR, or IS_CLIENT." << std::endl;
    return 1;
#endif

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
