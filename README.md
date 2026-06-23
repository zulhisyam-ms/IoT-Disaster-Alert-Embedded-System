# IoT Multi-Sensor Disaster Alert and Response System

## 📌 Project Overview
An award-winning **IoT Multi-Sensor Disaster Alert Framework** designed to optimize natural disaster mitigation and crisis management. The system integrates real-time telemetry from multiple environmental sensors to automate early threat detection, activate local sirens, and push instant cloud alerts during floods, fires, or landslide anomalies.

> 🏆 **Achievement:** Awarded **1st Place** in a group engineering project competition for its innovative, scalable approach to ethical disaster management and public safety infrastructure.

## 🛠️ Tech Stack & Engineering Concepts
- **Core Platform:** Microcontroller Programming (ESP32/Arduino Framework)
- **Firmware Development:** Embedded C++ (Asynchronous Sensor Sampling)
- **Circuit Architecture:** Multi-sensor hardware integration, analog-to-digital data smoothing, power distribution routing.
- **Key Fields:** Internet of Things (IoT), Disaster Management, Embedded Systems.

---

## 🏗️ Hardware Architecture & Sensor Array (`hardware/`)

The prototype framework orchestrates four specialized environmental detection layers:
1. **Flood Ingestion Layer:** Monitors real-time water levels using active fluid-depth sensor configurations.
2. **Debris Telemetry Tracker:** Leverages ultrasonic sound propagation to track close-range physical obstructions or rising flash flood thresholds.
3. **Landslide Risk Module:** Evaluates volumetric soil saturation trends via localized soil-moisture nodes.
4. **Fire Diagnostics Hub:** Detects hazardous smoke particles and toxic gas leaks to handle sudden structural fire containment.

---

## 📊 Evaluation & Validation Metrics

The embedded firmware evaluates sensor signals against a strict algorithmic risk matrix:

### Real-Time Diagnostics Test
```text
[System Diagnostics] Ingesting environmental matrices...
Sensor 01 (Water Level): 1200 Normal
Sensor 02 (Ultrasonic Clearance): 45cm Clear
Sensor 03 (Soil Saturation): 35% Stable
--------------------------------------------
Status: ENVIRONMENT SECURE [Telemetry logged successfully]
