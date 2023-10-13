#ifndef NIMBLE_H
#define NIMBLE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "esp_log.h"
#include "nvs_flash.h"
#include "driver/gpio.h"
#include "esp_nimble_hci.h"
#include "nimble/nimble_port.h"
#include "nimble/nimble_port_freertos.h"
#include "host/ble_hs.h"
#include "host/util/util.h"
#include "host/ble_uuid.h"
#include "console/console.h"
#include "services/gap/ble_svc_gap.h"
#include "services/gatt/ble_svc_gatt.h"
#include <stdbool.h>
#include "nimble/ble.h"
#include "modlog/modlog.h"
#include "../../../config.h"

// ===== GATT server ===== //
#define GATT_SVR_SVC_ALERT_UUID               0x1811
#define GATT_SVR_CHR_SUP_NEW_ALERT_CAT_UUID   0x2A47
#define GATT_SVR_CHR_NEW_ALERT                0x2A46
#define GATT_SVR_CHR_SUP_UNR_ALERT_CAT_UUID   0x2A48
#define GATT_SVR_CHR_UNR_ALERT_STAT_UUID      0x2A45
#define GATT_SVR_CHR_ALERT_NOT_CTRL_PT        0x2A44

// ===== Misc ===== //
void print_bytes(const uint8_t *bytes, int len);
void print_addr(const uint8_t *addr);

extern TaskHandle_t xHandle;
extern char notification[100];
extern bool notify_state;

struct ble_hs_cfg;
struct ble_gatt_register_ctxt;

// ? ==================================================================== ? //

void startBLE(struct json_bus* data); /* Starts the BLE stack and initializes the BLE host task. */

void stopBLE(); /* Stops the BLE stack and deinitializes the BLE host task. */

void bleprph_host_task(void* param); /* BLE host task. This task handles BLE events, such as incoming GATT requests, sending notifications to the client, and processing other BLE-related tasks. */

void startNVS(); /* Starts the NVS flash storage system. This function must be called before any NVS operations can be performed. */

void gatt_svr_register_cb(struct ble_gatt_register_ctxt *ctxt, void *arg); /* Callback function for GATT service, characteristic, and descriptor registration events. This function can be used to track the state of the GATT server and to handle requests from client devices. */

int gatt_svr_init(void); /* Initializes the GATT server. This function must be called before any GATT services can be registered or used. */

// // void handle_write_command(char *command); /* Handles a write command from the client. This function can be used to implement various features on the device, such as controlling LEDs or motors. */

void sendNotification();
void vTasksendNotification(void *parameter);

#ifdef __cplusplus
}
#endif

#endif