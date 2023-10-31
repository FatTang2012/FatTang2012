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




//cambienvatcantrai
const int trig_trai = 2;     // chân trig của HC-SR04
const int echo_trai = 3;     // chân echo của HC-SR04

//cambienvatcangiua
const int trig_giua = 4;     // chân trig của HC-SR04
const int echo_giua = 5;     // chân echo của HC-SR04

//cambienvatcanphai
const int trig_phai = 6;     // chân trig của HC-SR04
const int echo_phai = 7;     // chân echo của HC-SR04


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

//cambienvatcantrai
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig_trai,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo_trai,INPUT);    // chân echo sẽ nhận tín hiệu

    //cambienvatcangiua
    Serial.begin(9600);     
    pinMode(trig_giua,OUTPUT);   
    pinMode(echo_giua,INPUT);    

    //cambienvatcanphai
    Serial.begin(9600);    
    pinMode(trig_phai,OUTPUT);   
    pinMode(echo_phai,INPUT);    
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
    if(cambientrai() < 5)
    {
     void xichphai();
    }
    

    
    
    


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
      analogWrite(ENA, 120);
      digitalWrite(inA1,HIGH);
      digitalWrite(inA2,LOW);
      digitalWrite(inB1,HIGH);
      digitalWrite(inB2,LOW);
}
void xichphai(){ 
      digitalWrite(inA1,HIGH);
      digitalWrite(inA2,LOW);
      analogWrite(ENB, 120);
      digitalWrite(inB1,HIGH);
      digitalWrite(inB2,LOW);
}

//camrbien hc-sr04
float cambientrai(){
    unsigned long duration; // biến đo thời gian
    int distance1; 
    /* Phát xung từ chân trig */
    digitalWrite(trig_trai,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig_trai,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig_trai,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo_trai,HIGH);  
    // Tính khoảng cách đến vật.
    distance1 = int(duration/2/29.412);
    /* In kết quả ra Serial Monitor */
    Serial.print(distance1);
    Serial.println("cm");
    delay(200);
    return distance1;
}

float cambiengiua(){
    unsigned long duration; // biến đo thời gian
    int distance2; 
    /* Phát xung từ chân trig */
    digitalWrite(trig_giua,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig_giua,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig_giua,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo_giua,HIGH);  
    // Tính khoảng cách đến vật.
    distance2 = int(duration/2/29.412);
    /* In kết quả ra Serial Monitor */
    Serial.print(distance2);
    Serial.println("cm");
    delay(200);
    return distance2;
}

float cambienphai(){
    unsigned long duration; // biến đo thời gian
    int distance3; 
    /* Phát xung từ chân trig */
    digitalWrite(trig_phai,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig_phai,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig_phai,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo_giua,HIGH);  
    // Tính khoảng cách đến vật.
    distance3 = int(duration/2/29.412);
    /* In kết quả ra Serial Monitor */
    Serial.print(distance3);
    Serial.println("cm");
    delay(200);
    return distance3;
}
