#include <M5Atom.h>

bool random_seed_done = false;

void draw_face(int8_t number, CRGB color)
{
  M5.dis.clear();
  
  // center dot: 1,3,5
  if ( number == 1 or number == 3 or number == 5 )
    M5.dis.drawpix(2,2,color);
  
  // top right/bottom left: 2,3,4,5,6
  if ( number == 2 or number == 3 or number == 4 or number == 5 or number == 6) {
    M5.dis.drawpix(3,1,color);
    M5.dis.drawpix(1,3,color);
  }

  // top left/bottom right: 4,5,6
  if ( number == 4 or number == 5 or number == 6 ) {
    M5.dis.drawpix(1,1,color);
    M5.dis.drawpix(3,3,color);
  }
  
  // middle left/middle right: 6
  if ( number == 6 ) {
    M5.dis.drawpix(1,2,color);
    M5.dis.drawpix(3,2,color);
  }
}


void setup() {
  M5.begin(true, false, true);
  M5.dis.setBrightness(20);
}

void loop() {
  static int8_t current_color;
  CRGB face_color[3] = { CRGB::Red, CRGB::Green, CRGB::Blue };

  M5.Btn.read();
  if(M5.Btn.wasReleased()) {
    if(!random_seed_done) {
      randomSeed(millis());
      random_seed_done = true;
    }
    draw_face(random(1,7),face_color[current_color++]);
    current_color %= 3;
  }
}
