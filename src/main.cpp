#include <Arduino.h>

// #include <ST7789V.h>

// #include <board/board.h>

// #include <block_data/block_data.h>

// ST7789V lcd = ST7789V();
// Board board = Board();

// Block block = {5, 3, 0, 0};

#define BUTTONS_WIDTH 2
#define BUTTONS_HEIGHT 2

#define INPUT_BUTTON_OFFSET 8
#define OUTPUT_BUTTON_OFFSET 10

bool test[BUTTONS_HEIGHT][BUTTONS_WIDTH];

void setup() {
  Serial.begin(9600);

  // lcd.Init();
  // lcd.fill();

  // board.add_block(block);
  // board.draw(lcd);

  for (int ib = 0; ib < BUTTONS_WIDTH; ib++) {
    pinMode(ib + INPUT_BUTTON_OFFSET, INPUT_PULLUP);
    for (int jb = 0; jb < BUTTONS_HEIGHT; jb++) {
      pinMode(jb + OUTPUT_BUTTON_OFFSET, OUTPUT);
      test[jb][ib] = true;
    }
  }
}

void loop() {
  for (int i = 0; i < BUTTONS_WIDTH; i++) {
    digitalWrite(i + INPUT_BUTTON_OFFSET, HIGH);
    for (int ip = 1; ip < BUTTONS_WIDTH; ip++) {
      digitalWrite(((i + ip) % BUTTONS_WIDTH) + INPUT_BUTTON_OFFSET, LOW);
    }

    for (int j = 0; j < BUTTONS_HEIGHT; j++) {
      digitalWrite(j + OUTPUT_BUTTON_OFFSET, LOW);
      for (int jp = 1; jp < BUTTONS_HEIGHT; jp++) {
        digitalWrite(((j + jp) % BUTTONS_HEIGHT) + OUTPUT_BUTTON_OFFSET, HIGH);
      }
      
      if (digitalRead(i + INPUT_BUTTON_OFFSET) == LOW && test[j][i]) {
        test[j][i] = false;
      } else if (digitalRead(i + INPUT_BUTTON_OFFSET) != LOW && !test[j][i]) {
        test[j][i] = true;
        Serial.print(j);
        Serial.print(' ');
        Serial.println(i);
      }
      delayMicroseconds(30);
    }
  }
}
