#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// OLED display configuration
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET    -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pin configuration
const int smokeSensorPin = A1;    // MQ-2 sensor connected to analog pin A1
const int threshold = 200;        // Threshold value for smoke detection

void setup() {
  Serial.begin(115200);

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Halt if OLED initialization fails
  }

  // Clear the display
 // Display "Smoke Monitoring System" at startup
display.clearDisplay();

// Draw a graphical header
display.fillRect(0, 0, SCREEN_WIDTH, 16, WHITE); // Filled rectangle for header
display.setTextSize(1);
display.setTextColor(BLACK); // Invert text color for the header
display.setCursor(1, 1);
 

display.println("SMOKE MONITORING SYSTEM");  



// Display the content on the OLED
display.display();
delay(3000); // Hold the message for 3 seconds


  // Display the content on the OLED
  display.display();
  delay(3000); // Hold the message for 3 seconds
}

void loop() {
  // Read the analog value from the MQ-2 sensor
  int smokeValue = analogRead(smokeSensorPin);

  // Display smoke status on the OLED
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);

  if (smokeValue >= threshold) {
    display.println("Smoke Detected!");
  } else {
    display.println("You are:\n Safe");
  }

  display.display();
  delay(1000); // 1-second delay between readings
}
