// GameEditor.cpp
#include "GameEditor.h"
#include <iostream>

void GameEditor::main() {
#if defined(IS_EDITOR)
    std::cout << "Hello from GameEditor" << std::endl;
#else
    std::cerr << "Error: IS_EDITOR is not defined." << std::endl;
#endif
}
