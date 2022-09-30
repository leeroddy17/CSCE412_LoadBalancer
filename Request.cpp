// Request.cpp
// Created by leero on 9/29/2022.
//

#define REQUEST_CPP
#include <string>

/**
 * Struct to represent a request. Contains the Source and Destination
 * IP4 Address as well as the expected time to complete the request.
 */
struct Request
{
    std::string ip_in;
    std::string ip_out;
    int time;
};
