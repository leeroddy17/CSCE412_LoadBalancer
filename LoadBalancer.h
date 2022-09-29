//
// Created by leero on 9/29/2022.
//

#ifndef CS412_LOADBALANCER_LOADBALANCER_H
#define CS412_LOADBALANCER_LOADBALANCER_H

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

#include <queue>

class LoadBalancer {
public:
    LoadBalancer();

private:
    int systemTime;
};



#endif //CS412_LOADBALANCER_LOADBALANCER_H
