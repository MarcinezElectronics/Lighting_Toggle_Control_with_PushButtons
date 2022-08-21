#define MENETBEN          A0
#define BAL_FELOL_SZABAD  A1
#define JOBB_FELOL_SZABAD A2
#define VESZTEGLES        A3
#define ZOLD_JOBB_ALSO    2  //+Jobb felöl szabad LED
#define ZOLD_JOBB_FELSO   3
#define ZOLD_BAL_ALSO     4  //+Bal felol szabad LED
#define ZOLD_BAL_FELSO    5
#define PIROS_JOBB        6
#define PIROS_BAL         7
#define FEHER             8
#define MENETBEN_LED      9
#define VESZTEGLES_LED    10

bool menetbenOld;
bool menetbenNew = HIGH;
bool veszteglesOld;
bool veszteglesNew = HIGH;
bool balOld;
bool balNew = HIGH;
bool jobbOld;
bool jobbNew = HIGH;
unsigned char allapot = 0;

void setup() {

  pinMode(ZOLD_JOBB_ALSO,   OUTPUT);
  pinMode(ZOLD_JOBB_FELSO,  OUTPUT);
  pinMode(ZOLD_BAL_ALSO,    OUTPUT);
  pinMode(ZOLD_BAL_FELSO,   OUTPUT);
  pinMode(PIROS_JOBB,       OUTPUT);
  pinMode(PIROS_BAL,        OUTPUT);
  pinMode(FEHER,            OUTPUT);
  pinMode(MENETBEN_LED,     OUTPUT);
  pinMode(VESZTEGLES_LED,   OUTPUT);

  pinMode(MENETBEN,         INPUT);
  pinMode(VESZTEGLES,       INPUT);
  pinMode(BAL_FELOL_SZABAD, INPUT);
  pinMode(JOBB_FELOL_SZABAD,INPUT);
}

void loop() {

  menetbenNew   = digitalRead(MENETBEN);
  veszteglesNew = digitalRead(VESZTEGLES);
  jobbNew       = digitalRead(JOBB_FELOL_SZABAD);
  balNew        = digitalRead(BAL_FELOL_SZABAD);

if (menetbenOld == 0 && menetbenNew == HIGH){
    if (allapot == 0 || allapot == 2 || allapot == 3 || allapot == 4){
      allapot = 1;
      }
      else{
        allapot = 0;
      }
  }
  menetbenOld = menetbenNew;

  if (veszteglesOld == 0 && veszteglesNew == HIGH){
    if ((allapot == 0 || allapot == 1 || allapot == 3 || allapot == 4)){
      allapot = 2;
      }
      else{
        allapot = 0;
      }
  }
  veszteglesOld = veszteglesNew;

  if (jobbOld == 0 && jobbNew == HIGH){
    if ((allapot == 0 || allapot == 1 || allapot == 2 || allapot == 4)){
      allapot = 3;
      }
      else{
        allapot = 0;
      }
  }
  jobbOld = jobbNew;

  if (balOld == 0 && balNew == HIGH){
    if ((allapot == 0 || allapot == 1 || allapot == 2 || allapot == 3)){
      allapot = 4;
      }
      else{
        allapot = 0;
      }
  }
  balOld = balNew;

  switch(allapot){
    case 0: offLamps();
    break;
    case 1: menetbenL();
    break;
    case 2: veszteglesL();
    break;
    case 3: jobbrolSzabad();
    break;
    case 4: balrolSzabad();
    break;
    default:
    break;
  }
  delay(20);  
}

void offLamps(){
  
    digitalWrite(ZOLD_JOBB_ALSO,  LOW);
    digitalWrite(ZOLD_JOBB_FELSO, LOW);
    digitalWrite(ZOLD_BAL_ALSO,   LOW);
    digitalWrite(ZOLD_BAL_FELSO,  LOW);
    digitalWrite(PIROS_JOBB,      LOW);
    digitalWrite(PIROS_BAL,       LOW);
    digitalWrite(FEHER,           LOW);
    digitalWrite(MENETBEN_LED,    LOW);
    digitalWrite(VESZTEGLES_LED,  LOW);
    digitalWrite(ZOLD_JOBB_ALSO,  LOW);  
}

void menetbenL(){
  
    digitalWrite(ZOLD_JOBB_ALSO,  LOW);
    digitalWrite(ZOLD_JOBB_FELSO, HIGH);
    digitalWrite(ZOLD_BAL_ALSO,   LOW);
    digitalWrite(ZOLD_BAL_FELSO,  LOW);
    digitalWrite(PIROS_JOBB,      HIGH);
    digitalWrite(PIROS_BAL,       LOW);
    digitalWrite(FEHER,           HIGH);
    digitalWrite(MENETBEN_LED,    LOW);
    digitalWrite(VESZTEGLES_LED,  LOW);
    digitalWrite(ZOLD_JOBB_ALSO,  LOW);  
}

void veszteglesL(){
  
    digitalWrite(ZOLD_JOBB_ALSO,  LOW);
    digitalWrite(ZOLD_JOBB_FELSO, LOW);
    digitalWrite(ZOLD_BAL_ALSO,   LOW);
    digitalWrite(ZOLD_BAL_FELSO,  LOW);
    digitalWrite(PIROS_JOBB,      LOW);
    digitalWrite(PIROS_BAL,       LOW);
    digitalWrite(FEHER,           HIGH);
    digitalWrite(MENETBEN_LED,    LOW);
    digitalWrite(VESZTEGLES_LED,  LOW);
    digitalWrite(ZOLD_JOBB_ALSO,  LOW);  
}

void jobbrolSzabad(){
  
    digitalWrite(ZOLD_JOBB_ALSO,  HIGH);
    digitalWrite(ZOLD_JOBB_FELSO, HIGH);
    digitalWrite(ZOLD_BAL_ALSO,   LOW);
    digitalWrite(ZOLD_BAL_FELSO,  LOW);
    digitalWrite(PIROS_JOBB,      LOW);
    digitalWrite(PIROS_BAL,       HIGH);
    digitalWrite(FEHER,           HIGH);
    digitalWrite(MENETBEN_LED,    LOW);
    digitalWrite(VESZTEGLES_LED,  LOW);
    digitalWrite(ZOLD_JOBB_ALSO,  LOW);  
}

void balrolSzabad(){
  
    digitalWrite(ZOLD_JOBB_ALSO,  LOW);
    digitalWrite(ZOLD_JOBB_FELSO, LOW);
    digitalWrite(ZOLD_BAL_ALSO,   HIGH);
    digitalWrite(ZOLD_BAL_FELSO,  HIGH);
    digitalWrite(PIROS_JOBB,      LOW);
    digitalWrite(PIROS_BAL,       HIGH);
    digitalWrite(FEHER,           HIGH);
    digitalWrite(MENETBEN_LED,    LOW);
    digitalWrite(VESZTEGLES_LED,  LOW);
    digitalWrite(ZOLD_JOBB_ALSO,  LOW);  
}

 /*
  if (buttonOld == 0 && buttonbenNew == HIGH){
    if (LEDstate == LOW){
      LEDisOn();
      LEDstate = HIGH;
      }
      else{
        LEDisOff();
        LEDstate = LOW;
      }
  }
  buttonOld = buttonNew;
  delay(20);
