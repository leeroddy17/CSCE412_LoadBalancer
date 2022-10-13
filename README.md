# CSCE412_LoadBalancer

This repository demonstrates the functionality of a load balancer.
It allows the user to instantiate a number of servers, and processes requests
while randomly generating new ones as well.

# Compilation
This project was created using CLion and, thus, can be run using cmake. You can also compile using gcc.

# Usage
Example Usage...
```bash
Welcome to Load Balancer!
To start, please enter the number of servers: 
10
Now enter the time you want to run the load balancer:  
10000
```

```bash
Initializing queue...
Queue Size: 20
Creating 10 servers...
At time t=233 D processed request from 99.51.159.201 to 154.102.50.13
At time t=367 H processed request from 135.112.233.62 to 161.65.225.252
At time t=381 B processed request from 205.186.171.242 to 251.227.70.124
At time t=401 B processed request from 5.60.124.148 to 117.216.190.97
...
At time t=9785 F processed request from 69.165.85.139 to 117.45.134.202
At time t=9853 D processed request from 55.202.69.120 to 177.115.52.242
At time t=9957 H processed request from 112.160.104.123 to 161.254.146.53
```
By default, this program will initialize the number of requests to twice the size of the number of servers input, so 10 servers will initialize the queue to 20 requests.

By default, this program will randomly add to the request queue 5% of the time.
This new request is not printed to the console, but it can be printed by uncommenting lines 91 and 92 in main.cpp. 
# Documentation
Documentation for this program has been created using Doxygen, and can 
be found [here](https://people.tamu.edu/~leeroddy17/).
