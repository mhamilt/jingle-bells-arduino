/*
  Jingle bells
*/
//--------------------------------------------------
#include "pitches.h"
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
int verseRhythm[] =
{
  4, 4, 4, 4,
  2, 8, 8,
  4, 4, 4, 4,
  2, 4,
  4, 4, 4, 4,
  2, 4,
  4, 4, 4, 4,
  1,
  4, 4, 4, 4,
  2, 8, 8,
  4, 4, 4, 4,
  2, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  4, 4, 4, 4,
  1
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
//--------------------------------------------------
void setup()
{
  for (int i = 0; verse[i] != -1; ++i)
  {
    tone(10, verse[i], getDur(verseRhythm[i]));
    int pauseBetweenNotes =  (getDur(verseRhythm[i]) * 4) / 3;;
    delay(pauseBetweenNotes);
  }
  for (int i = 0; chorus[i] != -1; ++i)
  {
    tone(10, chorus[i], getDur(chorusRhythm[i]));
    int pauseBetweenNotes = (getDur(chorusRhythm[i]) * 4) / 3;
    delay(pauseBetweenNotes);
    noTone(10);
  }
}
//--------------------------------------------------
void loop() {}
//--------------------------------------------------
int getDur(int dur)
{
  return  800u / dur;
}
//--------------------------------------------------
