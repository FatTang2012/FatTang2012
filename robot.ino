//cambienvatcan
const int trig = 2;     // chân trig của HC-SR04
const int echo = 3;     // chân echo của HC-SR04
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

void setup()
{
//cambienvatcan
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
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
}

void loop()
                                          {
//cambiendoline
  int line_truoc = analogRead(hongngoai1)+analogRead(hongngoai2);
  int line_sau = analogRead(hongngoai3)+analogRead(hongngoai4);
if (line_truoc >= 1 ){lui();}//đụng line trước thì lùi lại
if (line_sau >=1){dithang();}//đụng line sau thì lùi lại


  //camrbien hc-sr04
    unsigned long duration; // biến đo thời gian
    int distance;           // biến lưu khoảng cách
    
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
