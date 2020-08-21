#include <Servo.h>
int dataIn = 0; // for incoming serial data
Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;

int servo1Pos, servo2Pos, servo3Pos, servo4Pos, servo5Pos, servo6Pos;
int servo1PPos, servo2PPos, servo3PPos, servo4PPos, servo5PPos, servo6PPos;
int speedDelay = 20;
int m = 0;

void setup() {
Serial.begin(115200);
servo01.attach(5);
servo02.attach(6);
servo03.attach(7);
servo04.attach(8);
servo05.attach(3);
servo06.attach(11);
servo1PPos = 90;
servo01.write(servo1PPos);
servo2PPos = 20;
servo02.write(servo2PPos);
servo3PPos = 50;
servo03.write(servo3PPos);
servo4PPos = 90;
servo04.write(servo4PPos);
servo5PPos = 90;
servo05.write(servo5PPos);
servo6PPos = 0;
servo06.write(servo6PPos);
}


void loop() {
if (Serial.available() > 0) {
dataIn = Serial.read();
Serial.print("I received: ");
Serial.println(dataIn, DEC);
  if (dataIn == 0) {
      m = 0;
    }
    if (dataIn == 16) {
    m = 16;
    }
    if (dataIn == 17) {
    m = 17;
    }
    if (dataIn == 18) {
    m = 18;
    }
    if (dataIn == 19) {
    m = 19;
    }
    if (dataIn == 20) {
    m = 20;
    }
    if (dataIn == 21) {
    m = 21;
    }
    if (dataIn == 22) {
    m = 22;
    }
    if (dataIn == 23) {
    m = 23;
    }
    if (dataIn == 24) {
    m = 24;
    }
    if (dataIn == 25) {
    m = 25;
    }
    if (dataIn == 26) {
    m = 26;
    }
    if (dataIn == 27) {
    m = 27;
    }

    while (m == 16) {
      if (Serial.available() > 0) {
        m = Serial.read();
      }
      servo01.write(servo1PPos);
      servo1PPos++;
      delay(speedDelay);
    }

    while (m == 17) {
      if (Serial.available() > 0) {
        m = Serial.read();
      }
      servo01.write(servo1PPos);
      servo1PPos--;
      delay(speedDelay);
    }

    while (m == 19) {
      if (Serial.available() > 0) {
        m = Serial.read();
      }
      servo02.write(servo2PPos);
      servo2PPos++;
      delay(speedDelay);
    }
    while (m == 18) {
      if (Serial.available() > 0) {
        m = Serial.read();
      }
      servo02.write(servo2PPos);
      servo2PPos--;
      delay(speedDelay);
    }

    while (m == 20) {
      if (Serial.available() > 0) {
        m = Serial.read();
      }
      servo03.write(servo3PPos);
      servo3PPos++;
      delay(speedDelay);
    }
    while (m == 21) {
      if (Serial.available() > 0) {
        m = Serial.read();
      }
      servo03.write(servo3PPos);
      servo3PPos--;
      delay(speedDelay);
    }

    while (m == 23) {
      if (Serial.available() > 0) {
        m = Serial.read();
      }
      servo04.write(servo4PPos);
      servo4PPos++;
      delay(speedDelay);
    }
    while (m == 22) {
      if (Serial.available() > 0) {
        m = Serial.read();
      }
      servo04.write(servo4PPos);
      servo4PPos--;
      delay(speedDelay);
    }

    while (m == 25) {
      if (Serial.available() > 0) {
        m = Serial.read();
      }
      servo05.write(servo5PPos);
      servo5PPos++;
      delay(speedDelay);
    }
    while (m == 24) {
      if (Serial.available() > 0) {
        m = Serial.read();
      }
      servo05.write(servo5PPos);
      servo5PPos--;
      delay(speedDelay);
    }

    while (m == 26) {
      if (Serial.available() > 0) {
        m = Serial.read();
      }
      servo06.write(servo6PPos);
      servo6PPos++;
      delay(speedDelay);
    }
    while (m == 27) {
      if (Serial.available() > 0) {
        m = Serial.read();
      }
      servo06.write(servo6PPos);
      servo6PPos--;
      delay(speedDelay);
    }

}
}
