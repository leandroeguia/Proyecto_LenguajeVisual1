//Declaracion de pines//
const int ledPIN = 7;
const int ledPIN2 = 8;
const int botonSuma = 3;
const int botonResta = 2;
const int ledAdver=6;


//Definicion de variables

int stateres=LOW;
char buf[10];
char buf2[10];
int velocidad[8]={10,50,100,250,400,600,800,1000};
int i=7;
String StrUno = "Velocidad en milisegundos: ";





void setup() {
  Serial.begin(9600);        //iniciar puerto serie
  pinMode(ledPIN , OUTPUT);  //define pin como salida
  pinMode(ledPIN2 , OUTPUT);  //define pin como salida
  pinMode(ledAdver , OUTPUT);  //define pin como salida
  pinMode(botonSuma , INPUT);   //define pulsador como entrada
  pinMode(botonResta , INPUT);   //define pulsador como entrada
  attachInterrupt(digitalPinToInterrupt(botonSuma), SumISR, FALLING);
  attachInterrupt(digitalPinToInterrupt(botonResta), ResISR, FALLING);

}

void loop() {


    Serial.println((String)"velocidad: "+ velocidad[i]);  
  digitalWrite(ledPIN,HIGH);
  digitalWrite(ledPIN2,HIGH);
  delay(velocidad[i]);
  digitalWrite(ledPIN,LOW);
  digitalWrite(ledPIN2,LOW);
  delay(velocidad[i]);
  
  if(stateres==HIGH){
   
    stateres=LOW;
    delay(800);
    digitalWrite(ledAdver,LOW);
    }  
 }

void SumISR(){
  static unsigned long last_interrupt_time = 0;
 unsigned long interrupt_time = millis();
 // If interrupts come faster than 200ms, assume it's a bounce and ignore
 if (interrupt_time - last_interrupt_time > 200)
 {
   if(i>0)
     i--;
 }
 last_interrupt_time = interrupt_time;
}

void ResISR(){

 static unsigned long last_interrupt_time2 = 0;
 unsigned long interrupt_time2 = millis();
 // If interrupts come faster than 200ms, assume it's a bounce and ignore
 if (interrupt_time2 - last_interrupt_time2 > 200)
 {
   stateres=HIGH;
   if(i<7)
      i++;
   digitalWrite(ledAdver,HIGH);
  
 }
 last_interrupt_time2 = interrupt_time2;
 

 
 
}
