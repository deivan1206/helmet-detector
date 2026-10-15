# Helmet Detection System

## About the Project

The Helmet Detection System is a computer vision project designed to detect helmets using the YOLO object detection model. It can help identify whether helmets are present in images or video, depending on how the program is used.

This project demonstrates the use of object detection for safety monitoring and helmet compliance.

## Features

- Detects helmets using a trained YOLO model.
- Uses computer vision for object detection.
- Includes a Python detection script.
- Includes a compiled application for Windows.

## Technologies Used

- Python
- YOLO object detection
- C programming language
- Computer vision

## Project Files

| File | Description |
|---|---|
| `detect_helmet.py` | Python script for helmet detection. |
| `program.c` | C source code associated with the project. |
| `helmet.pt` | Trained YOLO model weights used for detection. |
| `program.exe` | Executable application for Windows. |

## Requirements

- Python (if running the Python script).
- The required Python packages for the detection program.
- The trained model file, `helmet.pt`.
- Windows (if running `program.exe`).

## How to Run

### Option 1: Run the Windows Application

1. Download `program.exe` from this repository.
2. Download any additional files required by the application.
3. Run `program.exe` on a compatible Windows computer.

### Option 2: Run the Python Script

1. Install Python.
2. Install the required packages used by the project.
3. Make sure `helmet.pt` is in the correct location.
4. Run the following command in your terminal:

   ```bash
   python detect_helmet.py
   ```

Note: The exact setup and input requirements depend on how the program was developed.

## Project Purpose

This project explores how computer vision can be applied to helmet detection and safety monitoring. It also provides practical experience in object detection and software development.

## Author

[deivan1206]

## Disclaimer

This project is intended for educational and demonstration purposes. Detection results may not always be accurate and should not be used as the sole method for enforcing safety compliance.