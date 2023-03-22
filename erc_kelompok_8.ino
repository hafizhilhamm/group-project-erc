#include <DHT.h>
#define DHTPIN 2 
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);
const int trigPin = 7;    // pin output trigger sensor ultrasonik
const int echoPin = 4;    // pin input echo sensor ultrasonik
const int capacity = 336; // kapasitas kotak dalam cm
int distance;             // jarak terukur dari sensor ke benda
int percent;              // persentase kapasitas kotak


void setup()
{
  Serial.begin(9600);    
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
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

  // Menampilkan hasil bacaan suhu dan kelembaban pada Serial Monitor
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" °C - Kelembaban: ");
  Serial.print(kelembaban);
  Serial.println(" %");

  percent = 100 - (100*distance/15);
  Serial.println(distance);
  Serial.println(percent);

  delay(500);
}