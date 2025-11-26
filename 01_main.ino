#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 8
#define LED_PIN 2
Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

#define NUM_SPOTS 2
#define NUM_ENTRYS 1

// int trigSpots[NUM_SPOTS] = {22, 33, 26};
// int echoSpots[NUM_SPOTS] = {23, 32, 25};


// int trigEntry[NUM_ENTRYS] = {12, 21};
// int echoEntry[NUM_ENTRYS] = {13, 19};

int trigSpots[NUM_SPOTS] = {21, 25};
int echoSpots[NUM_SPOTS] = {19, 26};

int trigEntry[NUM_ENTRYS] = {33};
int echoEntry[NUM_ENTRYS] = {32};


#define MQ2_PIN 27
HardwareSerial mySerial(2);
byte arrCommandMp3[] = {0x7E, 0xFF, 0x06, 0x03, 0x00, 0x00, 0x01, 0xEF};
bool isPlaying = false;

unsigned long redStartTime = 0;
bool redActive = false;
bool greenActive = false;

void setup() {
  Serial.begin(115200);
  startHttpServer();

  mySerial.begin(9600, SERIAL_8N1, 16, 17);
  Serial.begin(115200);

  for (int i = 0; i < NUM_SPOTS; i++) {
    pinMode(trigSpots[i], OUTPUT);
    pinMode(echoSpots[i], INPUT);
  }
  for (int i = 0; i < NUM_ENTRYS; i++) {
    pinMode(trigEntry[i], OUTPUT);
    pinMode(echoEntry[i], INPUT);
  }

  strip.begin();
  strip.show();
}

void loop() {
  handleClient();

  updateParkingLeds();
  handleEntrySensors();
  updateLastLed();
  handleGasSensor();
  strip.show();
}
