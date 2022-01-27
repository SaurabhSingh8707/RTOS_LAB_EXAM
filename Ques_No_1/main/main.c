#include<stdio.h>
#include<driver/gpio.h>
#include<freertos/FreeRTOS.h>
#include<freertos/task.h>
#include<freertos/queue.h>
 QueueHandle_t sending_queue;

 void sensor_task(void *pv)
 {
   while(1){
   printf("sensor_task\n");
   vTaskDelay(1000 /portTICK_PERIOD_MS);
 }
 }
 void pressure_task(void *pv)
 {
   while(1){
   printf("pressure_task\n");
   vTaskDelay(2000 /portTICK_PERIOD_MS);
 }
 }
 void processing_task(void *pv)
 {
   while(1){
   printf("processing_task\n");
   vTaskDelay(5000 /portTICK_PERIOD_MS);
 }
 }
 void send_data_task(void *pv)
 {
     int send_data=0;
   while(1){
   send_data++;
   printf("send_data_task:send_data:%d\n",send_data);
   xQueueSend(sending_queue, &send_data, portMAX_DELAY);
   vTaskDelay(1000 /portTICK_PERIOD_MS);
 }
 }
 void recieve_data_task(void *pv)
 {
   int recv_data=0;
   while(1){
    xQueueReceive(sending_queue, &recv_data, portMAX_DELAY);
   printf("recieve_data_task:recv_data:%d\n",recv_data);
   vTaskDelay(1000 /portTICK_PERIOD_MS);
 }
 }
 void app_main()
 {
    sending_queue = xQueueCreate(10, sizeof(int));
    xTaskCreate(sensor_task,"sensor_task",2048,NULL,5,NULL);
    xTaskCreate(pressure_task,"pressure_task",2048,NULL,6,NULL);
    xTaskCreate(processing_task,"processing_task",2048,NULL,7,NULL);
    xTaskCreate(send_data_task,"send_data_task",2048,NULL,8,NULL);
    xTaskCreate(recieve_data_task,"recieve_data_task",2048,NULL,9,NULL);
 }
