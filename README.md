Before Running the Project in Visual Studio 2022

Run: .\Setup.bat ~ For Windows
Run: ./Setup.sh ~ For Linux [TODO]


Why do we need the Dependecies we have~
1. **bext-sml**
   - **Why it's needed**: `sml` stands for State Machine Language, a header-only, fast, compile-time state machine library. It can be used to manage game states (like menu, in-game, pause) efficiently, enabling clean and clear transitions and logic separation.

2. **cereal**
   - **Why it's needed**: A C++11 library for serialization. It's useful for saving game states, player progress, or any data that needs to be persisted between sessions or sent over a network.

3. **cpp-httplib**
   - **Why it's needed**: A single-file, header-only library for serving and consuming HTTP/HTTPS requests. It can be used for networking tasks like leaderboards, multiplayer session management, or downloading/uploading content.

4. **enet**
   - **Why it's needed**: A robust, simple, and lightweight networking library ideal for real-time applications like multiplayer games. ENet's features include sequencing, reliable delivery, and congestion control, essential for fast-paced multiplayer interaction.

5. **entt**
   - **Why it's needed**: An entity-component-system (ECS) library providing a way to efficiently organize game entities and components, improving performance and maintainability, especially in complex game worlds.

6. **imgui**
   - **Why it's needed**: Stands for Immediate Mode GUI. It's a library for building graphical user interfaces that are easy to integrate into game engines and tools, useful for debugging, tools, and in-game overlays.

7. **jsoncpp**
   - **Why it's needed**: A C++ library for interacting with JSON. It's useful for configuration files, saving/loading game data, and data interchange with web services.

8. **libgit2**
   - **Why it's needed**: A portable, pure C implementation of the Git core methods. It can be used for version control integration within the engine, allowing for asset tracking, versioning, and collaboration.

9. **luajit**
   - **Why it's needed**: A Just-In-Time Compiler for Lua, offering high performance execution of Lua scripts. It's ideal for scripting game logic, customizations, and automating tasks within the engine.

10. **opengl**
    - **Why it's needed**: A cross-language, cross-platform API for rendering 2D and 3D vector graphics. It's essential for rendering scenes, characters, and effects in the game.

11. **recastnavigation**
    - **Why it's needed**: A library for pathfinding and navigation mesh generation, used for AI character movement allowing them to navigate complex worlds efficiently.

12. **sdl2**
    - **Why it's needed**: The Simple DirectMedia Layer is a cross-platform development library designed to provide low-level access to audio, keyboard, mouse, joystick, and graphics hardware. It's foundational for game window management, event handling, and multimedia operations.

13. **uwebsockets**
    - **Why it's needed**: A library for building high-performance web server applications. It could be used for multiplayer game server communications, especially in browser-based or networked games.

14. **bullet3**
    - **Why it's needed**: A physics engine for simulating collision detection, rigid body dynamics, and soft body dynamics. It's essential for adding realistic physical interactions in the game world.