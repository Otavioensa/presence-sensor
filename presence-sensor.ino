
int pirSensor = 9;
int led = 8;

const int detectedPresence = 1;
const int baudRate = 9600;
const int delayTime = 3000;

void setup() {
  Serial.begin(baudRate);
  pinMode(pirSensor,INPUT);
  pinMode(led,OUTPUT);  
}

void loop() { 
  if (getPirSensorValue() == detectedPresence) {
    notifyApplication();
  }  
}

int getPirSensorValue() {
  int pirSensorValue = digitalRead(pirSensor);
  return pirSensorValue;
}

void notifyApplication() {
  digitalWrite(led,HIGH);
  Serial.println("Detected presence!");
  delay(delayTime);
  digitalWrite(led,LOW);   
}
