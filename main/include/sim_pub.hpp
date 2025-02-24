#ifndef SIM_PUB_HPP
#define SIM_PUB_HPP

#include "urosElement.hpp"
#include <std_msgs/msg/int32.h>
#include "esp_log.h"

class simPub : public urosElement {

    public:

        static simPub* pub;
        simPub();
        
        // microros initialization
        void init();

        // publisher callback functions
        static void timer_callback(rcl_timer_t* timer, int64_t num);


    private:
        rcl_timer_t timer;
        rcl_publisher_t simple_publisher;
        int counter = 0;
        int frequency = 10;
};


#endif