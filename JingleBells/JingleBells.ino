/*
  Jingle bells
*/
//--------------------------------------------------
#include "pitches.h"
//--------------------------------------------------
const int audioPin = 10;
//--------------------------------------------------
int verse[] =
{
  NOTE_D3, NOTE_B3, NOTE_A3, NOTE_G3,
  NOTE_D3, NOTE_D3, NOTE_D3,
  NOTE_D3, NOTE_B3, NOTE_A3, NOTE_G3,
  NOTE_E3, 0,
  NOTE_E3, NOTE_C4, NOTE_B3, NOTE_A3,
  NOTE_FS3, 0,
  NOTE_D4, NOTE_D4, NOTE_C4, NOTE_A3,
  NOTE_B3, 0,
  NOTE_D3, NOTE_B3, NOTE_A3, NOTE_G3,
  NOTE_D3, 0,
  NOTE_D3, NOTE_B3, NOTE_A3, NOTE_G3,
  NOTE_E3, NOTE_E3,
  NOTE_E3, NOTE_C4, NOTE_B3, NOTE_A3,
  NOTE_D4,  NOTE_D4, NOTE_D4,  NOTE_D4,
  NOTE_E4, NOTE_D4, NOTE_C4, NOTE_A3,
  NOTE_G3, 0, -1
};

//--------------------------------------------------
int verseRhythm[] =
{
  4, 4, 4, 4,
  2, 8, 8,
  4, 4, 4, 4,
  2, 4,
  4, 4, 4, 4,
  2, 2,
  4, 4, 4, 4,
  2,4,
  4, 4, 4, 4,
  2, 2,
  4, 4, 4, 4,
  2, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  1
};
//--------------------------------------------------
int chorus[]
{
  NOTE_B3, NOTE_B3,  NOTE_B3,
  NOTE_B3,  NOTE_B3,  NOTE_B3,
  NOTE_B3, NOTE_D4, NOTE_G3, NOTE_A3,
  NOTE_B3, 0,
  NOTE_C4,  NOTE_C4, NOTE_C4,  NOTE_C4,
  NOTE_C4, NOTE_B3,  NOTE_B3,  NOTE_B3,  NOTE_B3,
  NOTE_B3, NOTE_A3, NOTE_A3, NOTE_B3,
  NOTE_A3, NOTE_D4,
  NOTE_B3, NOTE_B3,  NOTE_B3,
  NOTE_B3,  NOTE_B3,  NOTE_B3,
  NOTE_B3, NOTE_D4, NOTE_G3, NOTE_A3,
  NOTE_B3, 0,
  NOTE_C4,  NOTE_C4, NOTE_C4,  NOTE_C4,
  NOTE_C4, NOTE_B3,  NOTE_B3,  NOTE_B3,  NOTE_B3,
  NOTE_D4, NOTE_D4,  NOTE_C4,  NOTE_A3,
  NOTE_G3, -1
};
//--------------------------------------------------
int chorusRhythm[] =
{
  4, 4, 2,
  4, 4, 2,
  4, 4, 3, 8,
  2, 4,
  4, 4, 3, 8,
  4, 4, 4, 8, 8,
  4, 4, 4, 4,
  2, 2, //
  4, 4, 2,
  4, 4, 2,
  4, 4, 3, 8,
  2, 4,
  4, 4, 3, 8,
  4, 4, 4, 8, 8,
  4, 4, 4, 4,
  2, 2
};
int chorusRhythm2[] =
{
  4, 4, 2,
  4, 4, 2,
  4, 4, 3, 8,
  2, 4,
  4, 4, 3, 8,
  4, 4, 4, 8, 8,
  4, 4, 4, 4,
  2, 2, //
  4, 4, 2,
  4, 4, 2,
  4, 4, 3, 8,
  2, 4,
  4, 4, 3, 8,
  4, 4, 4, 8, 8,
  4, 4, 4, 4,
  2, 2
};
//--------------------------------------------------
void setup()
{
  pinMode(audioPin, OUTPUT);
  playMelody(verse, verseRhythm);
  playMelody(chorus, chorusRhythm);
}
//--------------------------------------------------
void loop() {}
//--------------------------------------------------
int getDur(int dur)
{
  return  700u / dur;
}
//--------------------------------------------------
void playMelody(int melody[], int rhythm[])
{
  for (int i = 0; melody[i] != -1; ++i)
  {
    tone(audioPin, melody[i], getDur(rhythm[i]));
    int pauseBetweenNotes =  (getDur(rhythm[i]) * 4) / 3;
    delay(pauseBetweenNotes);
  }
}
