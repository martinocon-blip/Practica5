#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// WIFI
const char* ssid = "Nautilus";
const char* password = "20000Leguas";

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

WiFiServer server(80);

// Datos simulados
int hr = 75;
int spo2 = 98;

void setup() {
  Serial.begin(115200);
  Wire.begin(8, 9);

  // OLED
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);

  // WiFi
  WiFi.begin(ssid, password);
  Serial.print("Conectando a WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nConectado!");
  Serial.println(WiFi.localIP());

  server.begin();

  display.clearDisplay();
  display.setCursor(0,0);
  display.println("WiFi conectado");
  display.display();
  delay(2000);
}

void loop() {

  // Simulación
  hr = random(60, 100);
  spo2 = random(95, 100);

  // Mostrar en OLED
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

  // Web server
  WiFiClient client = server.available();

  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    // Página web
    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();

    client.println("<!DOCTYPE html><html>");
    client.println("<head><meta charset='UTF-8'><title>Biometria</title></head>");
    client.println("<body style='font-family:Arial; text-align:center;'>");
    client.println("<h1>Datos Biometricos</h1>");
    client.println("<h2>HR: " + String(hr) + "</h2>");
    client.println("<h2>SpO2: " + String(spo2) + "</h2>");
    client.println("</body></html>");

    client.stop();
  }

  delay(1000);
}