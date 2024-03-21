// GameServer.cpp
#include "GameServer.h"
#include <iostream>
#include <unordered_map>
#include <string>

#if defined(IS_SERVER)
extern "C" {
#include <enet/enet.h>
}

GameServer::GameServer() {
    if (enet_initialize() != 0) {
        std::cerr << "An error occurred while initializing ENet." << std::endl;
        exit(EXIT_FAILURE);
    }
}

void GameServer::start() {
    ENetAddress address;
    ENetHost* server;
    ENetEvent event;

    enet_address_set_host(&address, "localhost");
    address.port = 44444;

    server = enet_host_create(&address, 32, 2, 0, 0);
    if (!server) {
        std::cerr << "Failed to create ENet server." << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Server started on localhost:44444" << std::endl;

    // Map to store client state
    std::unordered_map<ENetPeer*, std::string> clients;

    bool running = true;
    while (running) {
        while (enet_host_service(server, &event, 1000) > 0) { // 1000 milliseconds timeout
            switch (event.type) {
                case ENET_EVENT_TYPE_CONNECT: {
                    std::cout << "A new client connected from "
                        << event.peer->address.host << ":"
                        << event.peer->address.port << "."
                        << std::endl;
                    // Send a message to the client asking for their username
                    const char* requestUsernameMsg = "Please send your username.";
                    ENetPacket* packet = enet_packet_create(requestUsernameMsg,
                        strlen(requestUsernameMsg) + 1,
                        ENET_PACKET_FLAG_RELIABLE);
                    enet_peer_send(event.peer, 0, packet);

                    // Set initial timeout for username response to 30 seconds
                    event.peer->timeoutLimit = 30;
                    break;
                }
                case ENET_EVENT_TYPE_RECEIVE: {
                    std::cout << "Received a packet from "
                        << event.peer->address.host << ":"
                        << event.peer->address.port
                        << ", on channel " << (unsigned)event.channelID << std::endl;

                    // Here, you'd typically parse the packet and handle different message types
                    // For simplicity, we assume any received packet in this example contains a username
                    std::string username(reinterpret_cast<char*>(event.packet->data));
                    clients[event.peer] = username; // Store the username
                    std::cout << "Username received: " << username << std::endl;

                    // Reset timeout to default after receiving username
                    event.peer->timeoutLimit = ENET_PEER_TIMEOUT_LIMIT;

                    enet_packet_destroy(event.packet);
                    break;
                }
                case ENET_EVENT_TYPE_DISCONNECT: {
                    std::cout << "Client disconnected: "
                        << clients[event.peer] << std::endl;
                    clients.erase(event.peer);
                    break;
                }
            }
        }
    }

    enet_host_destroy(server);
    enet_deinitialize();
}

#else

GameServer::GameServer() {
    std::cerr << "Error: IS_SERVER is not defined. GameServer instantiation is not allowed." << std::endl;
    exit(EXIT_FAILURE);
}

void GameServer::start() {
    // Since the constructor exits the application if IS_SERVER is not defined,
    // this function body can be left empty or filled with logic as needed.
}

#endif
