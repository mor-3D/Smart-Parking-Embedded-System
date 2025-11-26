bool allTaken = true;

void handleEntrySensors() {
  bool entry1 = ultrasonic_distance(trigEntry[0], echoEntry[0]) < 15;
  bool entry2 = ultrasonic_distance(trigEntry[1], echoEntry[1]) < 15;
  
  unsigned long currentMillis = millis();

  if (entry1 && !greenActive && !redActive) {
    if (isPlateAuthorized()) {
      if (!allTaken) {
        greenActive = true;
        delay(1000);

      } else {
        redActive = true;
        redStartTime = currentMillis;
      }
    }
  }

  if (entry2 && !entry1 && !greenActive && !redActive) {
    greenActive = true;
    delay(1000);
  }
}

bool isPlateAuthorized() {
  return true; // פונקציה מדומה – נניח תמיד מורשה
}
