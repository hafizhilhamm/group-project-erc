#include <DHT.h>
#define DHTPIN 2 
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);
const int trigPin = 7;    
const int echoPin = 4;    
const int capacity = 336; 
int distance;            
int percent;              
const int buzzerPin = 12; 
int buzzerState = LOW; 
const int led = 10;


void setup()
{
  Serial.begin(9600);    
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led, OUTPUT);
  dht.begin();
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  distance = pulseIn(echoPin, HIGH)/58;
  
  // Membaca suhu dan kelembaban dari sensor DHT22
  float suhu = dht.readTemperature();
  float kelembaban = dht.readHumidity();


  if (kelembaban > 50) {
    digitalWrite(buzzerPin,HIGH);
  } else {
    digitalWrite(buzzerPin,LOW);   
  }
  // Menampilkan hasil bacaan suhu dan kelembaban pada Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" °C - Kelembaban: ");
  Serial.print(kelembaban);
  Serial.println(" %");

  percent = 100 - (100*distance/15);
  Serial.println(distance);
  Serial.print(percent);
  Serial.println("%");

  if (percent > 30) {
    digitalWrite(led,HIGH);
  } else {
    digitalWrite(led,LOW);   
  }

  delay(500);
}
