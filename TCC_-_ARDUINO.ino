/* Bibliotecas usadas */
#include <dht.h>
#define dht_dpin A1 
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>

Adafruit_TSL2561_Unified tsl = Adafruit_TSL2561_Unified(TSL2561_ADDR_FLOAT, 12345);
dht DHT; 

void setup(){
  
  Serial.begin(9600);
  delay(1000);

  /* O if abaixo verifica se foi detectado o sensor TSL2561 */
  if(!tsl.begin()){
    Serial.print("Ooops, no TSL2561 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
  
  /* informações e configuração do sensor */
  displaySensorDetails();
  configureSensor();
  Serial.println("");
}


void displaySensorDetails(void){
  sensor_t sensor;
  tsl.getSensor(&sensor);
  delay(500);
}


void configureSensor(void){
  tsl.enableAutoRange(true);            
}

void loop() {
  DHT.read11(dht_dpin); 
  sensors_event_t event;
  tsl.getEvent(&event);
  Serial.print(DHT.humidity);
  Serial.print(";");
  Serial.print(DHT.temperature); 
  Serial.print(";");
  Serial.println(event.light); 
    
  delay(1000);  
}
