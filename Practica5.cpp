#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  Wire.begin(8, 9);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("Error OLED");
    while(true);
  }

  display.clearDisplay();
  display.display();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);

  display.println("Funciona :)");
  display.println("OLED OK");

  display.display();
}

int contador = 0;

void loop() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Sistema I2C");

  display.setTextSize(2);
  display.setCursor(0,20);
  display.print(contador);

  display.display();

  contador++;

  delay(1000);
}