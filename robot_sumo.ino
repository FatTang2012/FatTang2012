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

//cambienvatcangiua
const int trig_giua = 4;     // chân trig của HC-SR04
const int echo_giua = 5;     // chân echo của HC-SR04


void setup() {
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

void loop()                 {
  //cambiendoline
  if(cambiengiua()>77)
  {
    quaytrai();


  }
  if(cambiengiua() > 1 && cambiengiua() < 77)
  {
    dithang();
  }


  int line_truoc = analogRead(hongngoai1)+analogRead(hongngoai2);
  int line_sau = analogRead(hongngoai3)+analogRead(hongngoai4);
  if (line_truoc >= 1 ){lui();}//đụng line trước thì lùi lại
  if (line_sau >= 1 ){dithang();}//đụng line sau thì lùi lại
          //neu tung cam bien cham vach den rieng thi quay trai,phai enable

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
           delay(5000);
}

void quaytrai(){
           digitalWrite(inA1,LOW);
           digitalWrite(inA2,LOW);
           digitalWrite(inB1,HIGH);
           digitalWrite(inB2,LOW);
           //tuy thuoc vo banh chinh thoi gian delay
           delay(5000);
}

void quayphai(){
           digitalWrite(inA1,HIGH);
           digitalWrite(inA2,LOW);
           digitalWrite(inB1,LOW);
           digitalWrite(inB2,LOW);
           //tuy thuoc vo banh chinh thoi gian delay
           delay(5000);
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
