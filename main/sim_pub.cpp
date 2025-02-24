#include "sim_pub.hpp"

#define TAG "LSA"

const char * pub_topic_name = "/count_pub";

simPub* simPub::pub = 0;

// message type support
const rosidl_message_type_support_t * pub_type_support = ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32);

simPub::simPub() { pub = this; }

void simPub::init() {
    // ESP_LOGI(TAG, "Initializing line following publisher...");
    rclc_publisher_init_default(&simple_publisher, node, pub_type_support, pub_topic_name);

    rclc_timer_init_default(&timer, support, RCL_MS_TO_NS(1000 / frequency), simPub::timer_callback);

    rclc_executor_add_timer(exec, &timer);
    // ESP_LOGI(TAG, "publisher initialization successful");
}

void simPub::timer_callback(rcl_timer_t* timer, int64_t num) {

    std_msgs__msg__Int32 msg;
    std_msgs__msg__Int32__init(&msg);
    msg.data = pub->counter;
    // msg.data = 0;

    rcl_publish(&pub->simple_publisher, &msg, NULL);
    pub->counter++;
}