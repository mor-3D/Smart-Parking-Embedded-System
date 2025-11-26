void updateLastLed() {
  unsigned long currentMillis = millis();

  if (redActive) {
    if (currentMillis - redStartTime < 3000) {
      strip.setPixelColor(NUM_LEDS - 1, strip.Color(100, 0, 0));  
    } else {
      redActive = false;
      strip.setPixelColor(NUM_LEDS - 1, 0); 
    }
  } else if (greenActive) {
    strip.setPixelColor(NUM_LEDS - 1, strip.Color(0, 100, 0));  
    bool entry1Clear = ultrasonic_distance(trigEntry[0], echoEntry[0]) >= 10;
    bool entry2Clear = ultrasonic_distance(trigEntry[1], echoEntry[1]) >= 10;
    if (entry1Clear && entry2Clear) {
      greenActive = false;
      strip.setPixelColor(NUM_LEDS - 1, 0); 
    }
  }
}

long ultrasonic_distance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return 999;
  return duration / 58;
}
