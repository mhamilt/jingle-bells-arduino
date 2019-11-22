/*
  Jingle bells Wiuth Structs!
*/
//--------------------------------------------------
#include "pitches.h"
#include "tune.h"
//--------------------------------------------------
const int audioPin = 11;
const int bpm = 180;
//--------------------------------------------------
struct Tune
{
  int *melody;
  int *rhythm;
  int length;
  void play()
  {
    for (int i = 0; i < length; ++i)
    {
      tone(audioPin,  melody[i], getDur( rhythm[i]));
      int pauseBetweenNotes =  (getDur( rhythm[i]) * 4) / 3;
      delay(pauseBetweenNotes);
    }
  }
  int getDur(int dur)
  {
    constexpr int durationCoef = (60l * 1000l * 4l * 3l) / (4 * bpm);
    return  durationCoef / dur ;
  }
};
//--------------------------------------------------
template<class T, size_t N> constexpr Tune makeTune(T (&melody)[N], T (&rhythm)[N])
{
  return {melody, rhythm, N};
}
//--------------------------------------------------
Tune verse = makeTune(verseMelody, verseRhythm);
Tune chorus = makeTune(chorusMelody, chorusRhythm);
//--------------------------------------------------
void setup()
{
  verse.play();
  chorus.play();
}
//--------------------------------------------------
void loop() {}
