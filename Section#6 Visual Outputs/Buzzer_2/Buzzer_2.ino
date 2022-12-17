const int speakerPin = 9; // connect speaker to pin 9
char noteNames[] = {'C','D','E','F','G','a','b'};
unsigned int frequencies[] = {262,294,330,349,392,440,494};
const byte noteCount = sizeof(noteNames); // number of notes (7 here)
char score[] = "CCGGaaGFFEEDDC GGFFEEDGGFFEED CCGGaaGFFEEDDC "; //space is a rest
byte beats[] = {1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,  1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,2,1,1,1,1,1,1,1,1};
const byte scoreLen = sizeof(score)-1; // the number of notes in the score
void setup(){}
void loop(){
  for (int i = 0; i < scoreLen; i++){
    int duration = 333; // each note lasts for a third of a second
    playNote(score[i], duration*beats[i]); // play the note
  }
  delay(2000); // wait two seconds before repeating the song
}
void playNote(char note, int duration){ //play the tone corresponding to the note
  for (int i = 0; i < noteCount; i++){
    // try and find a match for the noteName to get the index to the note
    if (noteNames[i] == note) // find a matching note name in the array
    tone(speakerPin, frequencies[i], duration); // play the note
  }
  delay(duration); // if there is no match then the note is a rest, so just delay
}
