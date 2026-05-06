# IMU Based Smart Exercise Rep Counter with Automatic Workout Detection

A wearable real-time exercise tracking system that uses a single **MPU6050 IMU sensor** and an **ESP8266 NodeMCU** to automatically detect and count exercises using a browser-based machine learning pipeline.

The system classifies exercises in real time using a **k-Nearest Neighbour (k-NN)** classifier running entirely in JavaScript with no cloud dependency.

---

## Features

- Real-time exercise detection and repetition counting
- Automatic classification of:
  - Bicep Curl
  - Hammer Curl
  - Front Raise
- Browser-based dashboard
- Live IMU sensor monitoring
- WebSocket-based wireless data streaming
- Motion filtering and stability detection
- Real-time probability visualization
- Machine learning inference directly in the browser

---

# Website Interface

<p align="center">
  <img src="Interface.png" width="850" alt="Dashboard Interface">
</p>

> Add your dashboard screenshot inside `images/dashboard.png`

---

## Hardware Used

| Component | Purpose |
|---|---|
| ESP8266 NodeMCU | Main microcontroller |
| MPU6050 IMU | Accelerometer + Gyroscope |
| Power Bank / USB | Power supply |
| WiFi Hotspot | Wireless communication |

---

## Hardware Connections

| MPU6050 | ESP8266 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SCL | D1 (GPIO5) |
| SDA | D2 (GPIO4) |
| AD0 | GND |

---

## System Architecture

```text
MPU6050 IMU
     │
     ▼
ESP8266 NodeMCU
(WebSocket Server)
     │
 WiFi JSON Stream
     ▼
Browser Dashboard
     ├── Feature Extraction
     ├── k-NN Classifier
     ├── FSM Rep Counter
     └── Live Visualization
