##Українська версія:
# Batlebox
## Arduino Система моніторингу ґрунту та повітря

### Огляд
Цей проєкт на базі Arduino – це проста система моніторингу, яка відображає рівень вологості ґрунту, температуру та вологість повітря на LCD-екрані з інтерфейсом I2C. Також є привітальне повідомлення та кнопка для перемикання між різними режимами відображення.

### Необхідні компоненти
- Плата Arduino (наприклад, Arduino Uno)
- Датчик температури та вологості DHT11
- Датчик вологості ґрунту
- LCD 16x2 з інтерфейсом I2C
- Кнопка
- З’єднувальні дроти

### Використані бібліотеки
Перед завантаженням коду встановіть у Arduino IDE наступні бібліотеки:
- `LiquidCrystal_I2C.h` (для LCD із I2C-інтерфейсом)
- `DHT.h` (для роботи з датчиком DHT11)

### Конфігурація підключення
| Компонент                | Підключення до плати  |
|--------------------------|----------------------|
| Датчик DHT11             | Data -> Pin 3        |
| Датчик вологості ґрунту  | PWM -> Pin 6        |
| LCD (I2C)                | SDA -> A4, SCL -> A5 |
| Кнопка                   | Digital -> Pin 2     |

### Як це працює
1. **Запуск та привітальне повідомлення:**
   - Після ввімкнення живлення на LCD-екрані з’являється випадкове привітальне повідомлення.

2. **Режими відображення:**
   - Натискаючи кнопку, можна перемикати режими відображення.
   - Система циклічно перемикає такі екрани:
     - Привітальне повідомлення
     - Рівень вологості ґрунту
     - Температура
     - Вологість повітря
     - Вимкнення підсвічування LCD

3. **Автоматичне оновлення дисплея:**
   - Дані на LCD оновлюються лише у разі зміни показників, щоб уникнути зайвого мерехтіння екрану.

### Опис функцій коду
- `getGroundHumidity()`: Зчитує та відображає рівень вологості ґрунту.
- `getTemperature()`: Зчитує та відображає температуру повітря.
- `getAirHumidity()`: Зчитує та відображає вологість повітря.
- `greetingWrite()`: Відображає випадкове привітальне повідомлення.
- `loop()`: Постійно перевіряє стан кнопки та змінює режим відображення.

### Інструкція з налаштування
1. Підключіть компоненти відповідно до таблиці конфігурації.
2. Встановіть необхідні бібліотеки в Arduino IDE.
3. Завантажте код у плату Arduino.
4. Спостерігайте за показниками вологості ґрунту, температури та вологості повітря на LCD-дисплеї.

### Додаткові нотатки
- Кнопка використовується для перемикання між режимами відображення.
- LCD-підсвічування вимикається після перегляду всіх режимів.
- Якщо необхідно, змініть пін-коди датчиків та адресу LCD відповідно до вашого обладнання.

##English version:
# Batlebox
 # Arduino Soil and Air Monitoring System

## Overview
This Arduino project is a simple monitoring system that displays soil moisture, temperature, and air humidity on an LCD screen with an I2C interface. It also includes a greeting message and a button to switch between different display modes.

## Components Required
- Arduino Board (e.g., Arduino Uno)
- DHT11 Temperature and Humidity Sensor
- Soil Moisture Sensor
- 16x2 LCD with I2C Interface
- Push Button
- Connecting Wires

## Libraries Used
Make sure to install the following libraries in your Arduino IDE:
- `LiquidCrystal_I2C.h` (for LCD with I2C interface)
- `DHT.h` (for the DHT11 sensor)

## Pin Configuration
| Component               | Pin Connection       |
|-------------------------|----------------------|
| DHT11 Sensor            | Data -> Pin 3        |
| Soil Moisture Sensor    | PWM -> Pin 6      |
| LCD (I2C)               | SDA -> A4, SCL -> A5 |
| Push Button             | Digital -> Pin 2     |

## How It Works
1. **Startup & Greeting Message:**
   - Upon powering up, the LCD displays a random greeting message.

2. **Display Modes:**
   - Press the button to cycle through different display modes.
   - The system cycles through the following displays:
     - Greeting Message
     - Soil Moisture Level
     - Temperature
     - Air Humidity
     - LCD Backlight Off

3. **Automatic Display Updates:**
   - The LCD only updates when a new sensor reading differs from the last one.
   - This helps reduce unnecessary screen refreshes and flickering.

## Code Breakdown
- `getGroundHumidity()`: Reads and displays soil moisture level.
- `getTemperature()`: Reads and displays air temperature.
- `getAirHumidity()`: Reads and displays air humidity.
- `greetingWrite()`: Displays a random greeting message.
- `loop()`: Continuously checks the button state to change display modes.

## Setup Instructions
1. Connect the components as per the pin configuration table.
2. Install required libraries in the Arduino IDE.
3. Upload the provided code to the Arduino board.
4. Monitor soil moisture, temperature, and humidity using the LCD display.

## Notes
- The button allows toggling between different display modes.
- The LCD backlight turns off when no data is being displayed (after cycling through all modes).
- Modify sensor pins and LCD address as per your hardware setup if needed.
