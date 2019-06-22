
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

String apiKey = "BEHV77Q2JINS3D8V";       //  Enter your Write API key from ThingSpeak
const char *ssid =  "Moto 5";            // replace with your wifi ssid and wpa2 key
const char *pass =  "123456789";
const char *server = "api.thingspeak.com";

char f1,f2,f3,f4,p;
int ir1 = D1;
int ir2 = D2;
int ir3 = D3;
int ir4 = D4;
int motion = D5;

WiFiClient client;
void setup() {
  Serial.begin(9600);
  Serial.begin(115200);
   Serial.println("Connecting to ");
   Serial.println(ssid);
   WiFi.begin(ssid, pass);
       while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print("searching...");
     }
      Serial.println("");
      Serial.println("WiFi connected");
   

  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);  
  pinMode(ir3,INPUT); 
  pinMode(ir4,INPUT);
  pinMode(motion,INPUT);
  f1=0;f2=0;f3=0;f4=0;p=0;
}
void loop() {
  
  f1=0;f2=0;f3=0;f4=0;p=0;

                              if(digitalRead(ir1) == LOW)
                            {
                              Serial.println("IR1 PERSON DETECTED");
                              delay(1000);f1=1;

 if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr +="50";
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                        }

                          
                             }
   
                             
                            else if(digitalRead(ir2)== LOW)
                            {
                              Serial.println("IR2 PERSON DETECTED");
                              delay(1000);f2=1;
                              
                               if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field2=";
                             postStr +="50";
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                        }
                             
                             }
              
                             else if(digitalRead(ir3)== LOW)
                             {
                              Serial.println("IR3 PERSON DETECTED ");
                              delay(1000);f3=1;
                             
                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field3=";
                             postStr +="50";
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                        }
                             }
              
                            else if(digitalRead(ir4)==LOW)
                             {
                              Serial.println("IR4 PERSON DETECTED");
                              delay(1000);f4=1;
                              
                             if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field4=";
                             postStr +="50";
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                        }
                            

                             }
                

               /* //////////////// MOTION DETECTION ///////////////////////////////*/
                         else if(digitalRead(motion) == LOW)
                           {
                           Serial.println(" MOTION IS DETECTED");
                           delay(1000);p=1;
                       if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field5=";
                             postStr +="50";
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                        }
                           }
/* //////////////// NONE DETECTION ///////////////////////////////*/
                      else    //   "184.106.153.149" or api.thingspeak.com
                      {  
                            if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr +="0";
                             postStr +="&field2=";
                             postStr +="0";
                             postStr +="&field3=";
                             postStr +="0";
                             postStr +="&field4=";
                             postStr +="0";
                             postStr +="&field5=";
                             postStr +="0";
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                        }
                        }

           /*//////////  THINGSPEAK DATA TRANSFERING /////////////////////////////*/

     }
   

 
