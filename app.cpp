
// Define o pino 5 como buzzer
#define buz 5

// Pinos do sensor ultrassônico 
int echo = 12;
int trig = 13;


int distancia;
int dt;
int tempo;

void setup(){
  pinMode(4, OUTPUT);

// Define os pinos do sensor: echo como entrada e trig como saída
  pinMode(buz, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(trig, OUTPUT);
  Serial.begin(9600);
}

void loop(){

// Envia um pulso para o sensor
  digitalWrite(trig, HIGH);
  delay(dt);
  digitalWrite(trig, LOW);

// Mede o tempo que leva para o eco voltar
  tempo = pulseIn(echo, HIGH);  

// Calcula a distância
  distancia = tempo / 58 - 1;
  delay(25);

// Imprime a distância no Serial Monitor
  Serial.print("Distância: ");
  Serial.print(distancia);
  Serial.println(" cm");

// Se a distância for menor que 350, ativa o buzzer e o led
  if(distancia < 350){
    tone(5, 1000); 
    digitalWrite(4, HIGH);
  }

// Se a distância for maior que 350, desativa o buzzer e o led
  else if(distancia >= 350 ){
    noTone(5);
    digitalWrite(4, LOW);
  }
}