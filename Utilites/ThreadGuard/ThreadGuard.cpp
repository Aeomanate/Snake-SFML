//
// Created by Lyosha12 on 26.06.2018.
//

#include "ThreadGuard.hpp"

ThreadGuard::~ThreadGuard() {
    if(thread.joinable()) {
        live_controller = false;
        thread.join();
    }
}
