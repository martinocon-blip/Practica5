#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int hr = 75;
int spo2 = 98;

void setup() {
  Serial.begin(115200);
  Wire.begin(8, 9);

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println("Error OLED");
    while(true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Iniciando...");
  display.display();
  delay(2000);
}

void loop() {

  hr = random(60, 100);
  spo2 = random(95, 100);

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("BIOMETRIA");

  display.setTextSize(2);
  display.setCursor(0,16);
  display.print("HR:");
  display.print(hr);

  display.setCursor(0,40);
  display.print("O2:");
  display.print(spo2);

  display.display();

  delay(1000);
}