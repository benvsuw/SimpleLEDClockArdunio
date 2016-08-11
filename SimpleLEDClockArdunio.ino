int ledStart = 35;
int ledEnd = 52;

unsigned long previousMillis = 0;       
int currMin = 0;
int currHour = 0;

const long interval = 1000;        

void setup() {
  pinMode(13, OUTPUT);
  for(int i=ledStart; i < ledEnd + 1; i++) {
    pinMode(i, OUTPUT);    
  }
  
  digitalWrite(13, LOW); 
}

void loop()
{
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis >= interval) {
    // save the last time you blinked the LED 
    previousMillis = currentMillis;   
    currMin += 1;
    if(currMin >=60) {
      currMin -= 60;
      currHour += 1;
    }
    if (currHour >= 13)
      currHour -= 12;
    if (currHour == 0) 
      currHour = 12;
    
    // set hour
    for(int i=ledStart; i < ledEnd + 1; i++) {
      digitalWrite(i, LOW);    
    }
    
    switch(currHour) {
      case 1: 
        digitalWrite(46, HIGH);
        break;
      case 2: 
        digitalWrite(46, HIGH);
        digitalWrite(44, HIGH);
        break;
      case 3: 
        digitalWrite(46, HIGH);
        digitalWrite(44, HIGH);
        digitalWrite(42, HIGH);
        break;
      case 4: 
        digitalWrite(48, HIGH);
        digitalWrite(51, HIGH);
        break;
      case 5: 
        digitalWrite(48, HIGH);
        break;
      case 6: 
        digitalWrite(48, HIGH);
        digitalWrite(46, HIGH);
        break;
      case 7: 
        digitalWrite(48, HIGH);
        digitalWrite(46, HIGH);
        digitalWrite(44, HIGH);
        break;
      case 8: 
        digitalWrite(48, HIGH);
        digitalWrite(46, HIGH);
        digitalWrite(44, HIGH);
        digitalWrite(42, HIGH);
        break;
      case 9: 
        digitalWrite(42, HIGH);
        digitalWrite(40, HIGH);
        break;
      case 10:
        digitalWrite(40, HIGH);
        break; 
      case 11:
        digitalWrite(40, HIGH);
        digitalWrite(38, HIGH);
        break; 
      case 12:
        digitalWrite(40, HIGH);
        digitalWrite(36, HIGH);
        break; 
    }
      
    switch(currMin % 10) {
      case 1:
        digitalWrite(41, HIGH);
        break; 
      case 2:
        digitalWrite(41, HIGH);
        digitalWrite(39, HIGH);
        break;
      case 3:
        digitalWrite(41, HIGH);
        digitalWrite(39, HIGH);
        digitalWrite(37, HIGH);
        break;
      case 4:
        digitalWrite(45, HIGH);
        digitalWrite(43, HIGH);
        break;
      case 5:
        digitalWrite(43, HIGH);
        break;  
      case 6:
        digitalWrite(43, HIGH);
        digitalWrite(41, HIGH);
        break;
      case 7:
        digitalWrite(43, HIGH);
        digitalWrite(41, HIGH);
        digitalWrite(39, HIGH);
        break;
      case 8:
        digitalWrite(43, HIGH);
        digitalWrite(41, HIGH);
        digitalWrite(39, HIGH);
        digitalWrite(37, HIGH);
        break;
      case 9:
        digitalWrite(37, HIGH);
        digitalWrite(35, HIGH);
        break;  
    }
    
    if(10 <= currMin && currMin < 50)
      digitalWrite(49, HIGH);
    if(20 <= currMin && currMin < 40) 
      digitalWrite(50, HIGH);
    if(30 <= currMin && currMin < 40) 
      digitalWrite(52, HIGH);
    if(40 <= currMin && currMin < 60)
      digitalWrite(47, HIGH);
  }
}
