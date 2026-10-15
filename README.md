# Helmet Detection System

## About the Project

The Helmet Detection System is a computer vision application that uses a trained YOLO model to detect helmets. It supports real-time detection through a webcam and detection from saved images. The application also includes a built-in detection log that records the date and time of detection events.

## Features

- **Real-Time Webcam Detection:** Detect helmets using a live webcam feed.
- **Saved Image Detection:** Detect helmets in images stored on the computer.
- **Detection Log:** Records the date and time of detection events for tracking and review.
- **YOLO Object Detection:** Uses a trained model to identify helmets.
- **Windows Application:** Includes an executable for running the application on Windows.

## Technologies Used

- Python
- YOLO
- C programming language
- Computer vision

## Project Structure

```text
helmet-detector/
├── detect_helmet.py
├── program.c
├── helmet.pt
├── program.exe
├── README.md
└── images/
    ├── webcam-detection.png
    ├── image-detection.png
    └── detection-log.png
```

## Screenshots

### Real-Time Webcam Detection

![Webcam Detection](images/webcam-detection.png)

### Saved Image Detection

![Saved Image Detection](images/image-detection.png)

### Detection Log

![Detection Log](images/detection-log.png)

## Installation and Usage

### Running the Windows Application

1. Download `program.exe` and any required supporting files.
2. Ensure a webcam is connected for real-time detection.
3. Run `program.exe`.
4. Select the desired detection mode.
5. View the detection log to review recorded events.

### Running the Python Script

1. Install Python.
2. Install the required Python packages.
3. Ensure `helmet.pt` is in the correct location.
4. Run the following command:

   ```bash
   python detect_helmet.py
   ```

The application requirements and setup may vary depending on the project configuration.

## File Descriptions

| File | Description |
|---|---|
| `detect_helmet.py` | Python script for helmet detection. |
| `program.c` | C source code associated with the project. |
| `helmet.pt` | Trained YOLO model weights. |
| `program.exe` | Windows executable application. |
| `images/` | Screenshots demonstrating the project features. |

## Project Objectives

- Apply computer vision techniques to helmet detection.
- Support detection through webcams and saved images.
- Record detection event timestamps for review.
- Demonstrate the use of object detection in safety monitoring.

## Future Improvements

- Improve detection accuracy in different lighting conditions.
- Add detailed detection reports and statistics.
- Enhance the user interface and logging functionality.

## Author

[deivan1206]

## Disclaimer

This project is intended for educational and demonstration purposes. Detection results may not always be accurate and should not be used as the sole method for enforcing safety compliance.
