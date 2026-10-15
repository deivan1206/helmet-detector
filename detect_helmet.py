import sys
import cv2
import time
from ultralytics import YOLO
import os

# --------------------------------------------
# Validate arguments
# --------------------------------------------
if len(sys.argv) != 3:
    print("Usage: python detect_helmet.py <model_path> <source>")
    sys.exit(1)

model_path = sys.argv[1]
source = sys.argv[2]   # "0" for webcam OR path to image

if not os.path.exists(model_path):
    print(f"ERROR: Model not found — {model_path}")
    sys.exit(1)

# --------------------------------------------
# Load YOLO model
# --------------------------------------------
print(f"Loading model: {model_path}")
model = YOLO(model_path)

# Ensure outputs folder exists
os.makedirs("outputs", exist_ok=True)

# --------------------------------------------
# HELPER: Save output with timestamp
# --------------------------------------------
def generate_filename(prefix, extension="jpg"):
    timestamp = time.strftime("%Y%m%d_%H%M%S")
    return f"outputs/{prefix}_{timestamp}.{extension}"

# --------------------------------------------
# MODE 1 — Webcam detection
# --------------------------------------------
if source == "0":
    print("Starting webcam detection (10 seconds)...")
    cap = cv2.VideoCapture(0)
    if not cap.isOpened():
        print("ERROR: Cannot open webcam.")
        sys.exit(1)
    start_time = time.time()
    frame_count = 0
    last_frame = None

    while True:
        ret, frame = cap.read()
        if not ret:
            print("ERROR: Failed to read webcam frame.")
            break

        # Run YOLO detection
        results = model(frame)
        annotated_frame = results[0].plot()
        last_frame = annotated_frame

        cv2.imshow("Helmet Detection - Press Q to quit", annotated_frame)
        frame_count += 1

        # auto-stop after 10 seconds
        if time.time() - start_time > 10:
            print("Reached 10-second limit. Stopping webcam.")
            break

        # allow manual termination
        if cv2.waitKey(1) & 0xFF == ord('q'):
            print("User ended webcam.")
            break

    cap.release()
    cv2.destroyAllWindows()

    # Save last result
    if last_frame is not None:
        filename = generate_filename("webcam")
        cv2.imwrite(filename, last_frame)
        print(f"Webcam snapshot saved as: {filename}")
    else:
        print("No frame captured — nothing saved.")

    sys.exit(0)

# --------------------------------------------
# MODE 2 — Image detection
# --------------------------------------------
if not os.path.exists(source):
    print(f"ERROR: Image not found — {source}")
    sys.exit(1)

print(f"Running detection on image: {source}")

image = cv2.imread(source)
if image is None:
    print("ERROR: Unable to read image file.")
    sys.exit(1)

# Run YOLO
results = model(image)
annotated = results[0].plot()

# Save annotated image
base_name = os.path.splitext(os.path.basename(source))[0]
filename = generate_filename(base_name)
cv2.imwrite(filename, annotated)

print(f"Annotated image saved as: {filename}")

sys.exit(0)
