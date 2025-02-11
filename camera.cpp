#include "camera.h"
#include <ArduCAM.h>

ArduCAM myCAM;

void initCamera() {
    myCAM.begin();
}

void captureImage() {
    myCAM.flush_fifo();
    myCAM.start_capture();
}
