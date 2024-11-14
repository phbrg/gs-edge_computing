int sensor = 12;
int led = 11;
long duracao, cm;

void setup()
{
  pinMode(sensor, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int LDR = analogRead(A0);
  Serial.println(LDR);
  
  pinMode(sensor, OUTPUT);
  digitalWrite(sensor, LOW);
  delayMicroseconds(2);
  digitalWrite(sensor, HIGH);
  delayMicroseconds(5);
  digitalWrite(sensor, LOW);
  
  pinMode(sensor, INPUT);
  duracao = pulseIn(sensor, HIGH);
  
  cm = duracao / 29 / 2;
  
  if(LDR <= 930 && cm <= 100){
  	digitalWrite(led, HIGH);
  }
  
  delay(5000);
  digitalWrite(led, LOW);
}
