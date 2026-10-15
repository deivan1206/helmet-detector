#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <commdlg.h>   // For Windows File Dialog
#include <direct.h>    // For _chdir

#define MAX_PATH_LEN 500

int main() {
    char choice;
    int runCount;
    char imagePath[MAX_PATH_LEN];  //array

    //pointer
    const char *pythonScript = "C:\\Users\\lalit\\OneDrive\\Desktop\\HelmetDetection\\python_ai\\detect_helmet.py";
    const char *modelPath  = "C:\\Users\\lalit\\OneDrive\\Desktop\\HelmetDetection\\models\\helmet.pt";

    //file handling
    FILE *logFile = fopen("C:\\Users\\lalit\\OneDrive\\Desktop\\HelmetDetection\\detection_log.txt", "a");
    if (!logFile) {
        printf("Error opening log file.\n");
        return 1;
    }

    // Ensure working directory is root folder
    _chdir("C:\\Users\\lalit\\OneDrive\\Desktop\\HelmetDetection");

    //repetition structure
    while (1) {
        printf("\n====== Helmet Detection Menu ======\n");
        printf("1 - Run webcam detection\n");
        printf("2 - Upload and detect image\n");
        printf("3 - View previous detection logs\n");
        printf("4 - Exit\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        //selection structure
        if (choice == '4') {
            printf("Exiting program.\n");
            break;
        }

        char command[MAX_PATH_LEN + 200] = {0};

        if (choice == '1') {
            // Webcam detection
            snprintf(command, sizeof(command),
                     "python \"%s\" \"%s\" 0", pythonScript, modelPath);
        } 
        else if (choice == '2') {
            // Windows File Dialog to select image
            OPENFILENAME ofn;
            ZeroMemory(&ofn, sizeof(ofn));
            ofn.lStructSize = sizeof(ofn);
            ofn.hwndOwner = NULL;
            ofn.lpstrFilter = "Image Files\0*.jpg;*.jpeg;*.png;*.bmp\0";
            ofn.lpstrFile = imagePath;
            imagePath[0] = '\0';
            ofn.nMaxFile = MAX_PATH_LEN;
            ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
            ofn.lpstrTitle = "Select Image for Helmet Detection";

            if (!GetOpenFileName(&ofn)) {
                printf("No file selected.\n");
                continue;            }

            // Prepare Python command
            snprintf(command, sizeof(command),
                     "python \"%s\" \"%s\" \"%s\"", pythonScript, modelPath, imagePath);
        } 
        else if (choice == '3') {
            // View log file
            // File handling
            printf("\n--- Detection Log ---\n");
            FILE *readLog = fopen("C:\\Users\\lalit\\OneDrive\\Desktop\\HelmetDetection\\detection_log.txt", "r");
            if (!readLog) {
                printf("No log file found.\n");
            } else {
                char line[500];
                while (fgets(line, sizeof(line), readLog)) {
                    printf("%s", line);
                }
                fclose(readLog);
            }
            continue;
        } 
        else {
            printf("Invalid choice! Please enter 1, 2, 3, or 4.\n");
            continue;
        }

        // Ask how many times to run detection
        printf("How many times to run detection? ");
        scanf("%d", &runCount);
        // Repetition structure
        for (int i = 0; i < runCount; i++) {
            time_t now = time(NULL);
            struct tm *local = localtime(&now);
            char timestamp[100];
            strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", local);

            printf("\n=============================\n");
            printf("[RUN %d] Starting detection at %s\n", i + 1, timestamp);
            printf("=============================\n");
            int result = system(command);
            if (result == 0) {
                printf("Detection succeeded.\n");
                fprintf(logFile, "[%s] Run %d: Success\n", timestamp, i + 1);
            } else {
                printf("Detection FAILED.\n");
                fprintf(logFile, "[%s] Run %d: Failed\n", timestamp, i + 1);
            }
        }
    }

    fclose(logFile);
    return 0;
}
