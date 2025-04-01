#include <LiquidCrystal_I2C.h>  // Include library for LCD with I2C interface
#include <DHT.h>  // Include library for DHT temperature and humidity sensor

// Define pin and type for DHT sensor
int DHTPIN = 3;       
int DHTTYPE = DHT11;  
DHT dht(DHTPIN, DHTTYPE);

// Array of greeting messages
String greeting[3] = {"Good day!", ":)", "(* *)"};

// Initialize LCD with I2C address 0x27, 16 columns, and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define button pin to change display mode
int changeButtonPin = 2;  

// Define soil moisture sensor pin
int sensorHumidityGround = 6;  

// Variables to track display state and last sensor readings
int condition = 0;
int lastCondition = -1;
int lastHumidityGround = -1;
int lastGreeting = -1;
float lastTemp = -1;
float lastAirHumidity = -1;

// Function to read and display soil humidity
void getGroundHumidity() {
    int humidity = analogRead(sensorHumidityGround); // Read soil moisture sensor value
    if (humidity != lastHumidityGround) {  // Update display only if value changed
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Soil Humidity:");
        lcd.setCursor(0, 1);
        lcd.print(humidity);
        lastHumidityGround = humidity;
    }
}

// Function to read and display temperature
void getTemperature() {
    float temp = dht.readTemperature(); // Read temperature from DHT sensor
    if (temp != lastTemp) {  // Update display only if value changed
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp: ");
        lcd.print(temp);
        lcd.print("C");
        lastTemp = temp;
    }
}

// Function to read and display air humidity
void getAirHumidity() {
    float hum = dht.readHumidity(); // Read humidity from DHT sensor
    if (hum != lastAirHumidity) {  // Update display only if value changed
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Air Humidity: ");
        lcd.setCursor(0, 1);
        lcd.print(hum);
        lcd.print("%");
        lastAirHumidity = hum;
    }
}

// Function to display a greeting message once
void greetingWrite()
{
   if(lastGreeting == -1)  // Only display greeting if it hasn't been shown
   {
      lcd.setCursor(0, 0);
      lcd.print(greeting[random(3)]);  // Select random greeting message
      lastGreeting = 1;  // Mark greeting as displayed
   }
}

void setup() {
    pinMode(changeButtonPin, INPUT); // Set button pin as input
    lcd.begin();  // Initialize LCD
    lcd.clear();  // Clear LCD display
    lcd.backlight();  // Turn on LCD backlight
    dht.begin();  // Initialize DHT sensor
}

void loop() {
    // Check if the button is pressed to change display mode
    if (digitalRead(changeButtonPin)) {
        condition++;  // Move to the next condition
        if (condition > 4) {  // Reset condition if it exceeds the limit
            condition = 0;
        }
        delay(200);  // Debounce delay
    }

    // If condition has changed, reset previous readings to force display update
    if (condition != lastCondition) {
        lcd.clear();
        lastCondition = condition;
        lastHumidityGround = -1;
        lastTemp = -1; 
        lastAirHumidity = -1; 
        lastGreeting = -1; 
    }
    
    // Determine what to display based on current condition
    if (condition == 0) {  // Display greeting
        lcd.backlight();
        greetingWrite();
    } else if (condition == 1) {  // Display soil humidity
        getGroundHumidity();
    } else if (condition == 2) {  // Display temperature
        getTemperature();
    } else if (condition == 3) {  // Display air humidity
        getAirHumidity();
    } else {  // Turn off LCD backlight
        lcd.noBacklight();
    }
    
    delay(100);  // Short delay before next loop iteration
}
