#ifndef NIMBLE_H
#define NIMBLE_H

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


// ===== GATT server ===== //
#define GATT_SVR_SVC_ALERT_UUID               0x1811
#define GATT_SVR_CHR_SUP_NEW_ALERT_CAT_UUID   0x2A47
#define GATT_SVR_CHR_NEW_ALERT                0x2A46
#define GATT_SVR_CHR_SUP_UNR_ALERT_CAT_UUID   0x2A48
#define GATT_SVR_CHR_UNR_ALERT_STAT_UUID      0x2A45
#define GATT_SVR_CHR_ALERT_NOT_CTRL_PT        0x2A44


// ===== Misc ===== //
void print_bytes(const uint8_t *bytes, int len);
void print_addr(const void *addr);



extern TaskHandle_t xHandle;
extern char *notification;
extern bool notify_state;

struct ble_hs_cfg;
struct ble_gatt_register_ctxt;

// ? ==================================================================== ? //

/* Starts the BLE stack and initializes the BLE host task. */
void startBLE();

/* Stops the BLE stack and deinitializes the BLE host task. */
void stopBLE();

/* Callback function for BLE GAP events. This function handles various GAP events, such as connection requests, disconnections, and connection updates. */
static int bleprph_gap_event(struct ble_gap_event* event, void* arg);

// Callback function. When ever characrstic will be accessed by user, this function will execute
static int gatt__access(uint16_t conn_handle, uint16_t attr_handle, struct ble_gatt_access_ctxt* ctxt, void* arg);

/* Callback function. When ever user write to this characterstic,this function will execute */
static int gatt_svr_chr_write(struct os_mbuf* om, uint16_t min_len, uint16_t max_len, void* dst, uint16_t* len);

/* Callback function for BLE reset events. This function can be used to handle any special actions that need to be taken when the BLE stack is reset. */
static void bleprph_on_reset(int reason);

/* BLE host task. This task handles BLE events, such as incoming GATT requests, sending notifications to the client, and processing other BLE-related tasks. */
void bleprph_host_task(void* param);

/* Callback function for BLE sync events. This function can be used to handle any special actions that need to be taken when the BLE stack is synchronized. */
static void bleprph_on_sync(void);

/* Prints a connection descriptor. This function can be used for debugging purposes. */
static void bleprph_print_conn_desc(struct ble_gap_conn_desc* desc);

/* Starts advertising the device. This function makes the device visible to clients so that they can connect to it. */
static void bleprph_advertise(void);

/* Starts the NVS flash storage system. This function must be called before any NVS operations can be performed. */
void startNVS();

// Use this function to send notification once (after setting value of variable "notification")
void sendNotification();

// For sending notifications periodically as freetos task (after setting value of variable"notification")
void vTasksendNotification();

/* Callback function for GATT service, characteristic, and descriptor registration events. This function can be used to track the state of the GATT server and to handle requests from client devices. */
void gatt_svr_register_cb(struct ble_gatt_register_ctxt *ctxt, void *arg);

/* Initializes the GATT server. This function must be called before any GATT services can be registered or used. */
int gatt_svr_init(void);

/* Handles a write command from the client. This function can be used to implement various features on the device, such as controlling LEDs or motors. */
void handle_write_command(char *command);

/* Initializes the BLE store configuration. This configuration is used to save and restore the device's BLE settings, such as its advertising parameters and the GATT services that it offers. */
// // void ble_store_config_init(void);

// ? ==================================================================== ? //

// Tasks
void red_led_task(void* pvParameters);
void green_led_task(void *pvParameters);

#endif


