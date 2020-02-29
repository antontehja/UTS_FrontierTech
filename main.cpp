// #1

// #include<Arduino.h>

// const int buttonPin = 2;  

// int buttonState = 0;     
// int lastButtonState = 0; 
// int startPressed = 0;    
// int endPressed = 0;      
// int holdTime = 0;        
// bool status = false;

// void setup() {
//   pinMode(buttonPin, INPUT); // initialize the button pin as a input
//   pinMode(LED_BUILTIN, OUTPUT);
//   Serial.begin(115200);        // initialize serial communication
// }

// void updateState() {
//   if (buttonState == HIGH) {
//       endPressed = millis();
//       holdTime = endPressed - startPressed;
//       Serial.println("You released the button");
//       Serial.print("Time: ");
//       Serial.print(holdTime/1000);
//       Serial.println(" seconds");
//       digitalWrite(LED_BUILTIN, HIGH);
//       status = false;

//   } else {
//       startPressed = millis();
//       Serial.println("You pressed the button");
//       status = true;
//   }
// }
// void loop() {
//   buttonState = digitalRead(buttonPin); // read the button input

//   if (buttonState != lastButtonState) { // button state changed
//      updateState();
     
//      lastButtonState = buttonState;
//   }else if(millis()-startPressed>=10000 && status){
//     Serial.println("sudah 10 detik");
//     digitalWrite(LED_BUILTIN, HIGH);
//     delay(500);
//     status=false;
//   }else if (buttonState == LOW && status){
//     digitalWrite(LED_BUILTIN, LOW);
//     delay(500);
//     digitalWrite(LED_BUILTIN, HIGH);
//     delay(500);
//   }
// }

// #1 End

// #2
// #include <Arduino.h>
// #define Button_A 0         //GPIO0 
// #define Button_B 4         //GPIO4
// int button1=0, button2 = 0;
// int lastButtonState = 0;
// int blinktime=1000;
// int previousButton_A,previousButton_B = 1;

// void setup() {
//   Serial.begin(115200);
//     pinMode(Button_A, INPUT);
//     pinMode(Button_B,INPUT);
//     pinMode(LED_BUILTIN,OUTPUT);
// }

// void buttonA(){
//    int currentButton_A = digitalRead(Button_A);
//    if (currentButton_A != previousButton_A)
//     {
//         if (currentButton_A == 0)
//         {
//               blinktime= blinktime+100;
//               Serial.printf("%d ",blinktime);
//         }
//         else
//         {
//             Serial.println("You have just released button A");
//         }
//         previousButton_A = currentButton_A;
//     }
// }
// void buttonB(){
//   int currentButton_B = digitalRead(Button_B);
//   if (currentButton_B != previousButton_B)
//     {
//         if (currentButton_B == 0)
//         {
//               blinktime= blinktime-100;
//               Serial.printf("%d ",blinktime);
//         }
//         else
//         {
//             Serial.println("You have just released button B");
//         }
//         previousButton_B = currentButton_B;
//     }
// }
// void Blink(){
//   digitalWrite(LED_BUILTIN, LOW);
//     delay(blinktime);
//     digitalWrite(LED_BUILTIN, HIGH);
//     delay(blinktime);
// }

// void loop() {
//    if(blinktime>=2500){
//       digitalWrite(LED_BUILTIN, HIGH);
//     }
//     else {
//       buttonA();
//     }
//     if(blinktime<=100){
//       digitalWrite(LED_BUILTIN, HIGH);
//     }
//     else {
//       buttonB();
//     }
//     Blink();
    
// }
// #2 End

// #3
// #include <Arduino.h>

// #define BLYNK_PRINT Serial
// #include <WiFi.h>
// #include <WiFiClient.h>
// #include <BlynkSimpleEsp32.h>
// #include <Adafruit_NeoPixel.h>

// // You should get Auth Token in the Blynk App.
// // Go to the Project Settings (nut icon).
// char auth[] = "rIUgn-bK8RsQxftxlWa6JnuEk8kdgE8e";

// // Your WiFi credentials.
// // Set password to "" for open networks.
// char ssid[] = "Viel";
// char pass[] = "besaicai";

// #define NeoPixel 27
// #define NumPixels 1
// int r,g,b;
// Adafruit_NeoPixel pixels(NumPixels, NeoPixel, NEO_GRB + NEO_KHZ800);

// void setup() {
//   Serial.begin(115200);
//   Blynk.begin(auth, ssid, pass);
//   pinMode(NeoPixel, OUTPUT);
//   pixels.begin();
//   pixels.clear();
// }

// BLYNK_READ(V0){
//   int value = analogRead(36);
//   Blynk.virtualWrite(V0, value);
//   Serial.print("Analog Reading : ");
//   Serial.println(value);
//   if (value >= (0.8*4095)){
//     Blynk.notify("Its over 80%");
//   }
// }

// BLYNK_WRITE(V1) // zeRGBa assigned to V1 
// {
//     // get a RED channel value
//     r = param[0].asInt();
//     // get a GREEN channel value
//     g = param[1].asInt();
//     // get a BLUE channel value
//     b = param[2].asInt();

//   pixels.setPixelColor(0, pixels.Color(r, g, b));
// }

// void UseColor(){
//   pixels.setPixelColor(0, pixels.Color(r, g, b));
//   pixels.show();
// }

// void loop() {
//   Blynk.run();
//   UseColor();  
// }
// #3 End

// #4
// #include <WiFi.h>
// #include <PubSubClient.h>
// #include <Adafruit_NeoPixel.h>


// // Replace the next variables with your SSID/Password combination
// const char *ssid = "Viel";
// const char *password = "besaicai";

// // Add your MQTT Broker IP address, example
// const char *mqtt_server = "52.87.183.206";
// #define MQTT_TOPIC_ADC "IOT/KELOMPOK6/ADC"
// #define MQTT_TOPIC_RGB "IOT/KELOMPOK6/RGB"

// WiFiClient espClient;
// PubSubClient client(espClient);
// long lastMsg = 0;
// //char msg[50];
// int value = 0;

// #define LED_PIN 27
// #define LED_COUNT 1
// Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// void setColor(int r ,int g  ,int b ){
//     strip.setPixelColor(0,r,g,b);
//     strip.show();
// }

// void setup_wifi()
// {
//     delay(10);
//     Serial.println();
//     Serial.print("Connecting to ");
//     Serial.println(ssid);

//     WiFi.begin(ssid, password);

//     while (WiFi.status() != WL_CONNECTED)
//     {
//         delay(500);
//         Serial.print(".");
//     }

//     Serial.println("");
//     Serial.println("WiFi connected");
//     Serial.println("IP address: ");
//     Serial.println(WiFi.localIP());
// }

// void callback(char *topic, byte *message, unsigned int length)
// {
//     Serial.print("Message arrived on topic: ");
//     Serial.print(topic);
//     Serial.print(". Message: ");
//     String messageTemp;

//     for (int i = 0; i < length; i++)
//     {
//         Serial.print((char)message[i]);
//         messageTemp += (char)message[i];
//     }
//     Serial.println();

//     // Feel free to add more if statements to control more GPIOs with MQTT
//     // If a message is received on the topic esp32/output, we can check if the message is either "on" or "off".
//     if (String(topic) == MQTT_TOPIC_RGB)
//     {
//         Serial.print("Changing output to ");
//         if (messageTemp == "RED")
//         {
//             Serial.println("RED");
//             setColor(255,0,0);
//         }
//         else if (messageTemp == "GREEN")
//         {
//             Serial.println("GREEN");
//             setColor(0,255,0);
//         }
//         else if (messageTemp == "BLUE")
//         {
//             Serial.println("BLUE");
//             setColor(0,0,255);
//         }
//     }
// }

// void reconnect()
// {
//     // Loop until we're reconnected
//     while (!client.connected())
//     {
//         Serial.print("Attempting MQTT connection...");
//         // Attempt to connect
//         // Change to your username and password
//         if (client.connect("ESP32 MQTT Client", "reynaldo", "12345"))
//         {
//             Serial.println("connected");
//             // Subscribe
//             client.subscribe(MQTT_TOPIC_RGB);
//         }
//         else
//         {
//             Serial.print("failed, rc=");
//             Serial.print(client.state());
//             Serial.println(" try again in 3 seconds");
//             // Wait 3 seconds before retrying
//             delay(3000);
//         }
//     }
// }

// void setup()
// {
//     Serial.begin(115200);
//     setup_wifi();
//     client.setServer(mqtt_server, 1883);
//     client.setCallback(callback);
//     pinMode(LED_PIN, OUTPUT);
//     strip.begin();
//     strip.clear();
// }

// void loop()
// {
//     if (WiFi.status() != WL_CONNECTED)
//     {
//         Serial.print("Reconnecting WiFi: ");
//         Serial.println(ssid);
//         WiFi.mode(WIFI_STA);
//         WiFi.begin(ssid, password);
//         while (WiFi.status() != WL_CONNECTED)
//         {
//             Serial.print(".");
//             delay(500);
//         }
//         Serial.println("WiFi Connected");
//     }

//     while (WiFi.status() == WL_CONNECTED){

//         if (!client.connected())
//         {
//             reconnect();
//         }
//         client.loop();

//         long now = millis();
//         if (now - lastMsg > 5000){
//             lastMsg = now;
//             int temp= analogRead(36);
//             Serial.println("Phototransistor: "+String(temp));
//             client.publish(MQTT_TOPIC_ADC, String(temp).c_str());
//         }
//     }
// }
// #4 End