#include <WiFi.h>
#include <WebServer.h>

const char* ssid     = "Orange-21A5";
const char* password = "FB369djhqkjd";

WebServer server(80);
int motor1_fw = 27;
int motor1_bw = 26;
int motor2_fw = 33;
int motor2_bw = 16;  
int motor1_speed = 14; 
int motor2_speed = 32;  

void handleRoot() {
  const char html[] PROGMEM = R"rawliteral(
  <!DOCTYPE HTML><html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">
    <style>
      html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center; }
      .button { -webkit-user-select: none; -moz-user-select: none; -ms-user-select: none; user-select: none; background-color: #FF0000; border: none; color: white; padding: 12px 28px; text-decoration: none; font-size: 26px; margin: 1px; cursor: pointer; }
      .button2 {background-color: #555555;}
    </style>
    <script>
      function moveForward() { fetch('/forward'); }
      function moveLeft() { fetch('/left'); }
      function stopRobot() { fetch('/stop'); }
      function moveRight() { fetch('/right'); }
      function moveReverse() { fetch('/reverse'); }
    </script>
  </head>
  <body>
    <h1>ESP32 Motor Control</h1>
    <p><button class="button" onclick="moveForward()">FORWARD</button></p>
    <div style="clear: both;">
      <p>
        <button class="button" onclick="moveLeft()">LEFT</button>
        <button class="button button2" onclick="stopRobot()">STOP</button>
        <button class="button" onclick="moveRight()">RIGHT</button>
      </p>
    </div>
    <p><button class="button" onclick="moveReverse()">REVERSE</button></p>
  </body>
  </html>)rawliteral";
  server.send(200, "text/html", html);
}

void handleForward() {
  Serial.println("Forward");
  digitalWrite(motor1_speed, HIGH); 
  digitalWrite(motor2_speed, HIGH);  
  digitalWrite(motor1_fw, LOW);
  digitalWrite(motor1_bw, HIGH); 
  digitalWrite(motor2_fw, LOW);
  digitalWrite(motor2_bw, HIGH);
  server.send(200);
}

void handleLeft() {
  Serial.println("Left");
  digitalWrite(motor1_speed, HIGH);  
  digitalWrite(motor2_speed, HIGH); 
  
  digitalWrite(motor1_fw, LOW); 
  digitalWrite(motor1_bw, LOW); 
  digitalWrite(motor2_fw, LOW);
  digitalWrite(motor2_bw, HIGH);
  server.send(200);
}

void handleStop() {
  Serial.println("Stop");
  digitalWrite(motor1_speed, LOW);  
  digitalWrite(motor2_speed, LOW);  
  
  digitalWrite(motor1_fw, LOW); 
  digitalWrite(motor1_bw, LOW); 
  digitalWrite(motor2_fw, LOW);
  digitalWrite(motor2_bw, LOW);   
  server.send(200);
}

void handleRight() {
  Serial.println("Right");
  digitalWrite(motor1_speed, HIGH);  
  digitalWrite(motor2_speed, HIGH);  
  
  digitalWrite(motor1_fw, LOW); 
  digitalWrite(motor1_bw, HIGH); 
  digitalWrite(motor2_fw, LOW);
  digitalWrite(motor2_bw, LOW);    
  server.send(200);
}

void handleReverse() {
  Serial.println("Reverse");
  digitalWrite(motor1_speed, HIGH); 
  digitalWrite(motor2_speed, HIGH);  
  
  digitalWrite(motor1_fw, HIGH);
  digitalWrite(motor1_bw, LOW); 
  digitalWrite(motor2_fw, HIGH);
  digitalWrite(motor2_bw, LOW);          
  server.send(200);
}

void setup() {
  Serial.begin(115200);
  pinMode(motor1_fw, OUTPUT);
  pinMode(motor1_bw, OUTPUT);
  pinMode(motor2_fw, OUTPUT);
  pinMode(motor2_bw, OUTPUT);
  pinMode(motor1_speed, OUTPUT);
  pinMode(motor2_speed, OUTPUT);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", handleRoot);
  server.on("/forward", handleForward);
  server.on("/left", handleLeft);
  server.on("/stop", handleStop);
  server.on("/right", handleRight);
  server.on("/reverse", handleReverse);

  server.begin();
}

void loop() {
  server.handleClient();
}
