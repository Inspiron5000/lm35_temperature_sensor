/*
LM 35 TEMPERATURE SENSOR

Connect the Pin 1 of the LM 35 to +5V on the Arduino
Connect the Pin 2 of the LM 35 to A0 on the Arduino
Connect the Pin 3 of the LM 35 to GND on the Arduino

*/

/* 
Define the Pin of Temperature Sensor LM 35 
which is attached to A0 on Arduino
*/
int tempPin= A0; 	

/* Global Varibales to store the temperature value */
float temp;
 

void setup()
{
      Serial.begin(9600);
      
      // Setting the Pin Mode for the Sensor attached, either INPUT or OUTPUT
      pinMode(tempPin, INPUT);
      
      // Print the output on the Serial Monitor
      Serial.println("LM 35 TEMPERATURE SENSOR");
}


void loop()
{
        // Call the function to get the sensor value and store in our global variable
        temp = getTemperature (tempPin);
        
        // Print the output on the Serial Monitor
        Serial.println("");
        Serial.println("******************************");
        
        Serial.print("Temperature of Room =  ");
        Serial.print(temp);
        Serial.println(" degrees Celsius");

        Serial.print("Temperature of Room =  ");
        Serial.print((temp * 9.0)/5.0 + 32.0);
        Serial.println(" degrees Fahrenheit");

        Serial.print("Temperature of Room =  ");
        Serial.print(temp + 273.15);
        Serial.println(" degrees Kelvin");

        Serial.println("******************************");
        Serial.println("");

        // Delay of 5 sec to take the sensor value again
        delay(5000);
} 


/*********** Temperature Read function*********/
float getTemperature(int tempPin)
{  	
        int sensorValue = analogRead(tempPin);   

  	    float milliVoltsTemp = sensorValue*(5.0/1023.0)*1000;

        // There will be 1°C change for every 10mV of output
  	    return milliVoltsTemp/10;
}

