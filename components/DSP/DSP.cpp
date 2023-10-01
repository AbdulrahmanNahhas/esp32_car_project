// // #include "DSP.h"

// // static const char *TAG = "DSP";

// //  void DSP::task(void *parameter) {
// //   while(1) {
    // // When recieve data from React-Native
// //     if(xQueueReceive(data_bus.queue_recieve, (void *)&json_string, 0) == pdPASS) {
// //       LOGI(TAG, "I received data from nimble");
// //     }

    // // Update the data
// //     json.update_values(50, 12204, -12103);
// //     json_string = json.print();

    // // Send data to Nimble
// //     if (xQueueSend(data_bus.queue_send, (void *)&json_string, 10) != pdPASS) {
// //       LOGI(TAG, "ERROR: Could not put item on delay queue.");
// //     }

// //     vTaskDelay(pdMS_TO_TICKS(50));
// //   }
// // }
