//dongcocauH
#include <Stepper.h>
#define stepsPerRevolution 200

const int stepPins1[] = {8, 9, 10, 11};
const int stepPins2[] = {4, 5, 6, 7};

Stepper myStepper1(stepsPerRevolution, stepPins1[0], stepPins1[1], stepPins1[2], stepPins1[3]);
Stepper myStepper2(stepsPerRevolution, stepPins2[0], stepPins2[1], stepPins2[2], stepPins2[3]);

//cambiendoline
#define inA1 2 
#define inA2 3 
#define inB1 4
#define inB2 5 
#define hongngoai1 6
#define hongngoai2 7
#define hongngoai3 8
#define hongngoai4 9
#define ENA 10
#define ENB 11

//cambienvatcan
const int trig = 2;     // chân trig của HC-SR04
const int echo = 3;     // chân echo của HC-SR04

void setup()
{

//dongcocauH
  myStepper1.setSpeed(100);
  myStepper2.setSpeed(100);
  Serial.begin(9600);

//cambiendoline
pinMode(inA1, OUTPUT);
pinMode(inA2, OUTPUT);
pinMode(inB1, OUTPUT);
pinMode(inB2, OUTPUT);
pinMode(hongngoai1, INPUT);
pinMode(hongngoai2, INPUT);
pinMode(hongngoai3, INPUT);
pinMode(hongngoai4, INPUT);
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
Serial.begin(9600);
analogWrite(ENA, 120);
analogWrite(ENB, 120);//đi chậm cho khỏi trượt Line

//cambienvatcan
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
}

void loop()
                                          {
//dongcocauH        
Serial.println("Quay theo chiều kim đồng hồ cho động cơ 1");
  myStepper1.step(250); // Số bước mỗi lần quay
  delay(500);


  Serial.println("Quay ngược chiều kim đồng hồ cho động cơ 2");
  myStepper2.step(-250); 
  delay(500);
//cambiendoline
  int line_truoc = analogRead(hongngoai1)+analogRead(hongngoai2);
  int line_sau = analogRead(hongngoai3)+analogRead(hongngoai4);
if (line_truoc >= 1 ){lui();}//đụng line trước thì lùi lại
if (line_sau >=1){dithang();}//đụng line sau thì lùi lại
          //neu tung cam bien cham vach den rieng thi quay trai,phai enable

  //camrbien hc-sr04
  //cambientrai  
     cambien()
    if(distance < 5)
    {
     void xichphai();
    }
    

    
    
    /* In kết quả ra Serial Monitor */
    Serial.print(distance);
    Serial.println("cm");
    delay(200);


                                          }
void dithang(){
           digitalWrite(inA1,HIGH);
           digitalWrite(inA2,LOW);
           digitalWrite(inB1,HIGH);
           digitalWrite(inB2,LOW);
   
}
void lui(){
           digitalWrite(inA1,LOW);
           digitalWrite(inA2,HIGH);
           digitalWrite(inB1,LOW);
           digitalWrite(inB2,HIGH);
}
void quaytrai(){
           digitalWrite(inA1,LOW);
           digitalWrite(inA2,LOW);
           digitalWrite(inB1,HIGH);
           digitalWrite(inB2,LOW);
}
void quayphai(){
           digitalWrite(inA1,HIGH);
           digitalWrite(inA2,LOW);
           digitalWrite(inB1,LOW);
           digitalWrite(inB2,LOW);
}
void xichtrai(){
      analogWrite(ENA, OUTPUT);
      digitalWrite(inA1,HIGH);
      digitalWrite(inA2,LOW);
      digitalWrite(inB1,HIGH);
      digitalWrite(inB2,LOW);
}
void xichphai(){ 
      digitalWrite(inA1,HIGH);
      digitalWrite(inA2,LOW);
      analogWrite(ENB, OUTPUT);
      digitalWrite(inB1,HIGH);
      digitalWrite(inB2,LOW);
}
//camrbien hc-sr04
int cambien(){
    unsigned long duration; // biến đo thời gian
    int distance; 
    /* Phát xung từ chân trig */
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    distance = int(duration/2/29.412);
}

