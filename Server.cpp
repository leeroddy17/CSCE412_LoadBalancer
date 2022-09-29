//
// Created by leero on 9/28/2022.
//

#include "Server.h"

Server::Server() {
    requestStartTime = 0;
    serverName = ' ';
};
Server::Server(char c) {
    requestStartTime = 0;
    serverName = c;
};
void Server::addRequest(Request req, int currTime) {
    r = req;
    requestStartTime = currTime;
};
