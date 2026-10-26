# ESP32 Temperature and Humidity Monitoring using ThingSpeak

## Student Information
- Name: Omar Haj Daoud
- University ID: 12240090
- Course: Internet of Things (IoT)

## Project Description
This project demonstrates a temperature and humidity monitoring system using an ESP32 microcontroller and a DHT22 sensor.

The project is implemented using the Wokwi simulator. The ESP32 reads temperature and humidity values from the DHT22 sensor and sends the readings to ThingSpeak over Wi-Fi.

ThingSpeak stores the collected data and displays it using publicly accessible charts.

## Components
- ESP32 Dev Board
- DHT22 Temperature and Humidity Sensor
- Wokwi Simulator
- ThingSpeak IoT Platform

## Wiring Connections

| DHT22 Pin | ESP32 Pin |
|-----------|-----------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO 15 |

## Implementation
1. The ESP32 connects to the Wokwi-GUEST Wi-Fi network.
2. The DHT22 sensor measures temperature and humidity.
3. The ESP32 reads the sensor values.
4. The readings are sent to ThingSpeak every 20 seconds using HTTP requests.
5. The university ID is printed in the Serial Monitor.
6. ThingSpeak displays the collected readings in public charts.

## ThingSpeak Channel

Channel Name: Omar_HajDaoud_12240090

Channel ID: 3551749

Public URL:
https://thingspeak.mathworks.com/channels/3551749

### ThingSpeak Fields
- Field 1: Temperature (°C)
- Field 2: Humidity (%)

## Wokwi Simulation

Simulation URL:
https://wokwi.com/projects/478964088021766145


## Screenshots

The project screenshots, including the Wokwi simulation,
ThingSpeak channel, temperature graph, and humidity graph,
are available in the [IOT_screenshots](IOT_screenshots/) folder.


## Results
The ESP32 successfully connected to Wi-Fi and sent temperature and humidity readings to ThingSpeak.
The readings were updated approximately every 20 seconds.

The ThingSpeak channel displayed both temperature and humidity values on public charts. Changes in the simulated sensor readings were reflected in the graphs.

## Conclusion
This project demonstrates how IoT devices can collect environmental data and transmit it to a cloud platform for remote monitoring and visualization.
