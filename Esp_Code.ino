#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <Wire.h>
#include <MPU6050.h>

const char* ssid     = "YOUR_WIFI";
const char* password = "YOUR_PASS";

MPU6050 mpu;
WebSocketsServer ws(81);

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println(WiFi.localIP());   // note this IP for the web app
  ws.begin();
}

void loop() {
  ws.loop();
  int16_t ax,ay,az,gx,gy,gz;
  mpu.getMotion6(&ax,&ay,&az,&gx,&gy,&gz);

  // Convert to real units
  float axg = ax / 16384.0;
  float ayg = ay / 16384.0;
  float azg = az / 16384.0;
  float gxd = gx / 131.0;
  float gyd = gy / 131.0;
  float gzd = gz / 131.0;

  String json = "{\"ax\":" + String(axg,4) +
                ",\"ay\":" + String(ayg,4) +
                ",\"az\":" + String(azg,4) +
                ",\"gx\":" + String(gxd,4) +
                ",\"gy\":" + String(gyd,4) +
                ",\"gz\":" + String(gzd,4) + "}";
  ws.broadcastTXT(json);
  delay(50);  // 20Hz
}