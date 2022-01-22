#include<Wire.h>
#include <FirebaseESP32.h>


#define FIREBASE_HOST "xxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
    
#define FIREBASE_AUTH "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"    
FirebaseData fbdo;
FirebaseJson json;
FirebaseJson json2;
const char* ssid = "0209"; //Provide your SSID
const char* password = "12345678"; // Provide Password

void setup(){
  Serial.begin(115200);
  

  delay(10);
  Serial.println('\n');
  
  WiFi.begin(ssid, password);             // Connect to the network
  Serial.print("Connecting to ");
  Serial.print(ssid);

  while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
    delay(500);
    Serial.print('.');
  }

  Serial.println('\n');
  Serial.println("Connection established!");  
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP()); 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  Firebase.setReadTimeout(fbdo, 1000 * 60);
  Firebase.setwriteSizeLimit(fbdo, "tiny"); 
}

void loop() {
json2.set("child_of_002", 123.456);
json.set("parent_001", "parent 001 text");
json.set("parent 002", json2);

Firebase.pushJSON(fbdo, "/test/append", json);

  
delay(10000);
}
