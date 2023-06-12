#include <ESP8266HTTPClient.h>

#include <ESP8266wifi.h>
#include <Arduino.h>
#include <ESP8266WiFiMulti.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>
#include "DHT.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Adafruit_seesaw.h"



//Dirección donde se aloja el bakcend
String serverName = "http://clarys.ddns.net/sensitive/enviar.php";
String serverNameEstado = "http://clarys.ddns.net/sensitive/enviar_estado.php";



//led wifi placa
#define ledPIN 2

//sensor DHT22
#define DHTPIN 0  // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
float humedad = 0.0;
float temperatura = 0.0;

//estado de la cara
int estado = 0;
int contador = 0;

//sensor luz ambiente LDR
int luzAMB = 0;
int mapAMB = 0;

//sensor humedad tierra
Adafruit_seesaw ss;
float tempC = 0.0;
uint16_t capread = 0;
int mapHUM = 0;

//temporizador1 para envio de datos a la BD
unsigned long previousMillis = 0;  // will store last time LED was updated
unsigned long currentMillis = 0;

// Tiempo de temporizacion en ms
const long interval = 120000;  //10 minutos entre envio a BD

//temporizador2 para ejecutar programa, cambiar cara, etcc
unsigned long previousMillis2 = 0;  // will store last time LED was updated
unsigned long currentMillis2 = 0;

// Tiempo de temporizacion en ms
const long interval2 = 5000;  //5 segundos

//OLED SETTINGS
#define SCREEN_WIDTH 128     // OLED display width, in pixels
#define SCREEN_HEIGHT 64     // OLED display height, in pixels
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int eye_width = 15;
int eye_height = 45;
int i = 1;

const unsigned char bitmap_1[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x06, 0x00, 0x00, 0x00, 0x00, 0x10, 0x07, 0x00, 0x00, 0x00, 0x00, 0x18, 0x03, 0x80, 0x00, 0x00,
  0x00, 0x0c, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x06, 0x00, 0x7f, 0xe0, 0x00, 0x00, 0x03, 0x00, 0x0f,
  0xf0, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
  0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00,
  0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x03,
  0xc0, 0x00, 0x00, 0x00, 0x80, 0x3f, 0xe0, 0x00, 0x00, 0x01, 0x80, 0x78, 0x00, 0x00, 0x00, 0x01,
  0x81, 0xc0, 0x00, 0x00, 0x00, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x03, 0x06, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char bitmap_2[] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x60, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x3f, 0xfe, 0x00, 0x00, 0xe0, 0x00, 0x07, 0xfe, 0x00,
  0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x06,
  0x00, 0x0f, 0x80, 0x00, 0x00, 0x0c, 0x00, 0x78, 0x00, 0x00, 0x00, 0x0c, 0x00, 0xf0, 0x00, 0x00,
  0x00, 0x0c, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//-------------------------------- OLED SETTINGS END --------------------------------------------
AsyncWebServer server(80);

ESP8266WiFiMulti wifiMulti;

void setup(void) {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);

  // Redes conocidas
  wifiMulti.addAP("calpanxo", "ritarita1");
  wifiMulti.addAP("TAYDESIGNER", "AlbertoBla19Cal");
  // WiFi.scanNetworks retorna el numero de redes detectadas
  int n = WiFi.scanNetworks();
  Serial.println();
  Serial.println("Scanning networks");
  if (n == 0) {
    Serial.println("No networks found");
  } else {
    Serial.print(n);
    Serial.println(" Networks found");
    Serial.println();
    for (int i = 0; i < n; ++i) {
      // Print SSID and RSSI for each network found
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == AUTH_OPEN) ? " " : "*");
      delay(10);
    }
  }

  // Conexión a la wifi con mayor cobertura
  Serial.println();
  Serial.println("Connecting Wifi...");
  if (wifiMulti.run() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("Network: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.print("MAC address: ");
    Serial.println(WiFi.macAddress());
    delay(2000);
  }

  //Server OTA para la actualización via web
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(200, "text/plain", "Bienvenido a Sensitive Pot.\tEscribe /update para actualizar.");
  });

  AsyncElegantOTA.begin(&server);
  server.begin();
  Serial.println("HTTP server started");
  Serial.println();

  pinMode(ledPIN, OUTPUT);
  dht.begin();
  ss.begin(0x36);
  if (!ss.begin(0x36)) {
    Serial.println("ERROR! seesaw not found");

  } else {
    Serial.print("seesaw started! version: ");
    Serial.println(ss.getVersion(), HEX);
  }


  //incio del OLED y mostrado datos de conexion
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(1, 0);
  display.setCursor(0, 0);
  display.print(F("Red: "));
  display.print(WiFi.SSID());
  display.setCursor(0, 15);
  display.print(F("IP: "));
  display.print(WiFi.localIP());
  display.setCursor(0, 30);
  display.print(F("MAC ADRESS: "));
  display.setCursor(0, 45);
  display.print(WiFi.macAddress());
  display.display();
  delay(5000);
  eyes_placement(0, 0, 0);
  programa();
  enviarDatos();
}

//---------------------------------------------------loop--------------------------------------------------
void loop(void) {
  //Si ha conexion wifi el led de la placa estará encendido
  if (WiFi.status()) {
    digitalWrite(ledPIN, HIGH);
  }



  currentMillis2 = millis();
  //primer temporizador, ejecutaremos el programa principal
  if (currentMillis2 - previousMillis2 >= interval2) {
    previousMillis2 = currentMillis2;
    programa();   
    if (mapAMB > 10) {
      //Programa de dia
      if (mapHUM < 20) {
        estado = 3;
      } else if (mapHUM > 40) {
        estado = 2;
      }else{
        estado = 1;
      }
    } else {
      //Programa de noche
      estado = 5;
    }
    contador++;
    pintaCara(estado);
    enviarEstado();    
    envioSerial();
    if (contador > 11) {
      pintarOLED();
      contador = 0;
      delay(10000);
    }
  }


  currentMillis = millis();
  //segundo temporizador, hace una lectura de datos y los envia al backend
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    programa();
    enviarDatos();
    pintarOLED();
    delay(5000);
  }
}
//--------------------------------------------final loop------------------------------------------------


//--------------------------------------------funciones-------------------------------------------------

//funcion que agrupa toda la lectura de datos
void programa() {
  leerDHT();
  leerLDR();
  leerHUMT();
}

//funcion leer datos del DHT
void leerDHT() {
  humedad = dht.readHumidity();
  temperatura = dht.readTemperature();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(1, 0);



  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println(F("Error de lectura DHT!"));
    display.setCursor(40, 5);
    display.println("Error DHT");
    display.display();
    return;
  }

}

//funcion leer luz ambiente
void leerLDR() {
  luzAMB = analogRead(0);
  //mapeo de la luz ambiente en un rango de 0 a 127
  mapAMB = map(luzAMB, 0, 1030, 0, 127);
}

//funcion leer humedad maceta
void leerHUMT() {
  tempC = ss.getTemp();
  capread = ss.touchRead(0);
  //mapeo de la humedad en un rango de 0 a 100
  mapHUM = map(capread, 310, 1030, 0, 127);
}

//funcion para pintar datos en el OLED
void pintarOLED() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(1, 0);
  display.setCursor(0, 0);
  display.print("Humedad   Temperatura");
  display.setTextSize(2);
  display.setTextColor(1, 0);
  display.setCursor(0, 20);
  display.print(humedad, 1);
  display.setCursor(72, 20);
  display.print(temperatura, 1);    
  display.fillRect(0, 58, mapAMB, 61, SSD1306_INVERSE);
  display.display();
}

//funcion para enviar datos por el puerto serie
void envioSerial() {
  Serial.print(F("Humedad: "));
  Serial.print(humedad);
  Serial.print(F("%  Temperatura: "));
  Serial.print(temperatura);
  Serial.println(F("°C "));

  Serial.print("Luz ambiente: ");
  Serial.print(luzAMB);
  Serial.print("  Map luz ambiente: ");
  Serial.println(mapAMB);
  Serial.println();

  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println("*C");
  Serial.print("Capacitive: ");
  Serial.print(capread);
  Serial.print(" Map : ");
  Serial.println(mapHUM);
  Serial.println();
  Serial.println("**************************************************************************************");
  Serial.println();
  delay(100);
}


//funcion para enviar datos al backend
void enviarDatos() {

  Serial.println("Inicio envio datos backend ");
  WiFiClient client;
  HTTPClient http;

  // preparacion de Http request
  String serverPath = serverName + "?tempAmb=" + String(temperatura, 1) + "&humAmb=" + String(humedad, 0) + "&humTer=" + String(mapHUM) + "&luzAmb=" + String(mapAMB) + "";
  Serial.print("serverPath: ");
  Serial.println(serverPath);
  http.begin(client, serverPath.c_str());

  // Envio HTTP GET request
  int httpResponseCode = http.GET();

  //comprobación errores de respuesta del servidor
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Libero recursos
  http.end();
}

//funcion para enviar datos al backend
void enviarEstado() {

  Serial.println("Inicio envio datos backend ");
  WiFiClient client;
  HTTPClient http;

  // preparacion de Http request
  String serverPath = serverNameEstado + "?estado=" + String(estado) + "";
  Serial.print("serverPath: ");
  Serial.println(serverPath);
  http.begin(client, serverPath.c_str());

  // Envio HTTP GET request
  int httpResponseCode = http.GET();

  //comprobación errores de respuesta del servidor
  if (httpResponseCode > 0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);
  } else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Libero recursos
  http.end();
}


//---------------------------------- EYES OLED --------------------------------------


void eyes_placement(int x, int y, int dh) {  //default: (0, 0, 0)
  display.clearDisplay();

  display.fillRect(25 + x, 11 + y - (dh / 2), eye_width, eye_height + dh, SSD1306_INVERSE);
  display.fillRect(88 + x, 11 + y - (dh / 2), eye_width, eye_height + dh, SSD1306_INVERSE);

  display.display();
}

void eyes_blink(int x, int y) {  //default: (0, 0)
  display.clearDisplay();
  eyes_placement(x, y, 0);

  for (int i = 0; i < 3; i++) {
    display.clearDisplay();

    eyes_placement(x, y, -14 * i);
    display.display();
  }
  for (int i = 3; i >= 0; i--) {
    display.clearDisplay();

    eyes_placement(x, y, -14 * i);
    display.display();
  }
}

void state_default() {
  int rand_disp_x = random(-20, 20);
  int rand_disp_y = random(-10, 10);
  int rand_delay = random(3000, 6000);
  int blink_bool = random(0, 2);

  eyes_placement(rand_disp_x, rand_disp_y, 0);
  if (blink_bool == 1) {
    eyes_blink(rand_disp_x, rand_disp_y);
  }
  delay(rand_delay);
}

void state_happy() {
  String text = "^ ^";

  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);

  display.setCursor(22, 24);
  display.println(text);
  display.display();
  delay(400);

  display.clearDisplay();
  display.setCursor(22, 16);
  display.println(text);
  display.display();
  delay(400);
}

void state_angry(void) {
  String text = "- -";

  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);

  display.setCursor(21, 40);
  display.println(text);
  display.drawBitmap(84, 0, bitmap_1, 48, 48, WHITE);
  display.display();
  delay(300);

  display.clearDisplay();
  display.setCursor(23, 40);
  display.println(text);
  display.drawBitmap(84, 0, bitmap_2, 48, 48, WHITE);
  display.display();
  delay(600);
}

void state_sad(void) {
  String text = "- -";
  int side_bool = random(0, 2);
  int tear_size = random(8, 12);
  int tear_speed = random(5, 8);
  int tear_disp = random(30, 40);

  for (int i = 0; i < 15; i++) {
    display.clearDisplay();

    display.setTextSize(5);
    display.setTextColor(WHITE);

    display.setCursor(20 + (i % 2), 10);
    display.println(text);

    display.fillRect(41 + (40 * (side_bool)), tear_disp + tear_speed * i, 4, tear_size, SSD1306_INVERSE);

    display.display();

    delay(100);
  }
}

void state_dead() {
  String text = "X X";

  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);

  display.setCursor(22, 18);
  display.println(text);
  display.display();
  delay(1000);
}

void state_sleep() {
  String text = "- -";

  display.clearDisplay();
  display.setTextSize(5);
  display.setTextColor(WHITE);

  display.setCursor(22, 18);
  display.println(text);
  display.display();

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(70, 0);
  display.println(F("ZZZ"));
  display.display();

  display.startscrollright(0, 10);
  delay(1000);
  display.stopscroll();
  delay(1000);
}

void pintaCara(int cara) {

  switch (cara) {
    case 1:
      eyes_blink(0, 0);
      break;
    case 2:
      state_happy();
      break;
    case 3:
      state_angry();
      break;
    case 4:
      state_sad();
      break;
    case 5:
      state_sleep();
      break;
    case 6:
      state_dead();
      break;
    default:
      break;
  }
}
