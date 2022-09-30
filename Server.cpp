// Server.cpp
// Created by leero on 9/28/2022.
//

#include "Server.h"

/**
 * Default constructor, initialized name to blank
 */
Server::Server() {
    requestStartTime = 0;
    serverName = ' ';
};

/**
 * Overloaded constructor, initialized name to input char
 */
Server::Server(char c) {
    requestStartTime = 0;
    serverName = c;
};

/**
 * Adds a request for the server to process
 * @param req
 * @param currTime
 */
void Server::addRequest(Request req, int currTime) {
    r = req;
    requestStartTime = currTime;
};

/**
 * Returns whether a request has finished
 * @param current_time
 * @return bool, true if request finished
 */
bool Server::isRequestDone(int current_time) {
    return (requestStartTime + r.time <= current_time);
};

/**
 * Gets the request from the server
 * @return Request
 */
Request Server::getRequest() {
    return r;
}

/**
 * Gets the Name of the server
 * @return char, name of server
 */
char Server::getName() {
    return serverName;
}