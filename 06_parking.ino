void updateParkingLeds() {
  allTaken = true;
  for (int i = 0; i < NUM_SPOTS; i++) {
    long d = ultrasonic_distance(trigSpots[i], echoSpots[i]);

    if (d >= 10) {
      strip.setPixelColor(i, strip.Color(0, 100, 0));  
      allTaken = false;
    } else {
      strip.setPixelColor(i, strip.Color(100, 0, 0)); 
    }
  }
}
