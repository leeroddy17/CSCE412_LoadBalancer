// main.cpp
// Created by leero on 9/28/2022.
//

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>

#include "LoadBalancer.h"
#include "Server.h"

using namespace std;

/**
 * Generates a random IP4 Address
 * @return string, random IP4 Address
 */
string generateIP() {
    int ip1 = rand() % 256; //creates a randomly generated IP Octet
    int ip2 = rand() % 256;
    int ip3 = rand() % 256;
    int ip4 = rand() % 256;

    stringstream ss;
    ss << ip1 << "." << ip2 << "." << ip3 << "." << ip4;
    return ss.str();
}

/**
 * Generates a random time between (0, 999)
 * @return int, random time
 */
int generateTime() {
    return rand() % 999; //creates a randomly generated time between 0 < x < 1000
}


int main(int argc, char** argv) {

    int num_servers;
    int time;

    // Take in User Input
    cout << "Welcome to Load Balancer!" << endl;
    cout << "To start, please enter the number of servers: " << endl;
    cin >> num_servers;
    cout << "Now enter the time you want to run the load balancer:  " << endl;
    cin >> time;
    cout << "Initializing queue..." << endl;

    // Create LoadBalancer and populate
    int lb_size = num_servers * 2;
    LoadBalancer lb = LoadBalancer();
    for (int i = 0; i < lb_size; i++) {
        Request req = {generateIP(), generateIP(), generateTime()};
        lb.addRequestToQueue(req);
    }

    cout << "Queue Size: " <<  lb.getQueueSize() << endl;
//    Request sample = lb.getRequest();
//    cout << "Sample: " << sample.source << " " <<  sample.destination << "  " << sample.time << endl;
//    cout << "Queue Size: " <<  lb.getQueueSize() << endl;

    // Create an array of servers
    cout << "Creating " << num_servers << " servers..." << endl;
    Server server_arr[num_servers];
    for (int i = 0; i < num_servers; i++) {
        server_arr[i] = Server((char)(i + 65));
        server_arr[i].addRequest(lb.getRequest(), lb.getTime());
    }

    while (lb.getTime() < time) {

        if (lb.isRequestQueueEmpty()) {
            cout << "Request Queue is empty!! Exiting..." << endl;
            break;
        }

        int current_time = lb.getTime();
        if (server_arr[current_time % num_servers].isRequestDone(current_time)) {
            Request req = server_arr[current_time % num_servers].getRequest();
            cout << "At time t=" << current_time << " " << server_arr[current_time % num_servers].getName() <<
            " processed request from " << req.ip_in << " to " << req.ip_out << endl;

            // Give Server new request
            server_arr[current_time % num_servers].addRequest(lb.getRequest(), current_time);
        }

        // 10% chance to randomly add new request to the queue
        if (rand() % 10 == 0) {
            Request to_add = {generateIP(), generateIP(), generateTime()};
            lb.addRequestToQueue(to_add);
//            cout << "At time t=" << current_time << " " << server_arr[current_time % num_servers].getName() <<
//                 " received a new request from " << to_add.ip_in << " to " << to_add.ip_out << endl;
        }

        lb.incrementTime();

    }

    return 0;
}
