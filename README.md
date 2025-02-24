# Micro-ROS Publisher on ESP-IDF(ESP32)

This repository contains an implementation of a simple ROS2 Micro-ROS publisher using ESP32. The project publishes an integer counter to the `/count_pub` topic.

## Project Structure

- `sim_pub.hpp`: Header file defining the `simPub` class, which handles the ROS2 publisher.
- `sim_pub.cpp`: Implementation of the `simPub` class, including initialization and timer callback function.
- `main.cpp`: Entry point of the program, initializing the ROS2 Micro-ROS node and adding the publisher component.

## Dependencies

To run this project, you need:
- **ESP-IDF** with Micro-ROS support
- **Micro-ROS Agent** running on a host system
- **ROS2 (Humble or newer)** installed on the host
- **Micro-ROS ESP32 Component**: [micro_ros_espidf_component](https://github.com/micro-ROS/micro_ros_espidf_component.git)
- **Custom Micro Handler**: [urosHandler](https://github.com/gawar55/urosHandler.git)

## Installation & Setup

### 1. Clone the Repository
```sh
git clone https://github.com/Chinmay-ESP/PUB_MicroRos_IDF.git
cd PUB_MicroRos_IDF
```

### 2. Install ESP-IDF & Micro-ROS
Follow the official [Micro-ROS on ESP32](https://micro.ros.org/docs/tutorials/core/first_application_esp32/) guide to set up ESP-IDF and Micro-ROS.

### 3. Add Required Components
```sh
git clone https://github.com/micro-ROS/micro_ros_espidf_component.git components/micro_ros_espidf_component
git clone https://github.com/gawar55/urosHandler.git components/urosHandler
```

### 4. Build & Flash the Code
```sh
idf.py set-target esp32
idf.py build
idf.py flash
```

### 5. Run the Micro-ROS Agent
On your host machine, start the Micro-ROS Agent:
```sh
docker run -it --rm --ipc host --network host --privileged microros/micro-ros-agent:humble serial -b 115200 --dev /dev/ttyUSB0
```

## How It Works

1. **`simPub` Class**:
   - Creates a publisher on the `/count_pub` topic.
   - Uses a timer callback to publish an increasing integer value.
   - Publishes data at a frequency of **10 Hz**.

2. **Main Execution (`app_main`)**:
   - Initializes the `uros_master_node`.
   - Registers the `simPub` publisher.

## Expected Output
Once the ESP32 is running and the Micro-ROS Agent is active, you should see messages being published in ROS2:
```sh
ros2 topic echo /count_pub
```
Output:
```
data: 0
data: 1
data: 2
...
```
