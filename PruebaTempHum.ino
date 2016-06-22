#include <dht.h>

#define dht_apin A0 // Analog Pin sensor is connected to
 
dht DHT;
int bandera;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");

  switch((int) DHT.humidity % 5) {
    case 0:
      bandera = 5;
      break;
    case 1:
      bandera = 6;
      break;
    case 2:
      bandera = 7;
      break;
    case 3:
      bandera = 8;
      break;
    default:
      bandera = 9;
      break;
  }
  Serial.print("Bandera = ");
  Serial.println(bandera);

  delay(5000);//Wait 2 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop()
