// void handleGasSensor() {
//   int gas = analogRead(MQ2_PIN);
//   if (gas > 3000 && !isPlaying) {
//     mySerial.write(arrCommandMp3, sizeof(arrCommandMp3));
//     isPlaying = true;
//   }
// }
void handleGasSensor() {
  static bool gasHigh = false;
  static unsigned long gasStartTime = 0;

  int gas = analogRead(MQ2_PIN);

  if (gas > 3000) {
    if (!gasHigh) {
      gasHigh = true;
      gasStartTime = millis();  
    } else {
      if (millis() - gasStartTime >= 3000 && !isPlaying) {
        mySerial.write(arrCommandMp3, sizeof(arrCommandMp3));
        isPlaying = true;
      }
    }
  } else {

    gasHigh = false;
    gasStartTime = 0;

    if (isPlaying) {
      isPlaying = false;
    }
  }
}
