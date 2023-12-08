#include "CubeControl.h"

CubeControl cube(12, 11, 8, 7, 6, 5, 4);

void setup() {
  Serial.begin(115200);
  cube.begin();
}

void rain(int num){ //number of rain drops
  int drops[num][3]; // (x, y)
  for(int i = 0; i < num;i++){
      drops[i][0] = (int) random(0,4); // x
      drops[i][1] = (int) random(0,4); // y
      drops[i][2] = (int) random(0,4); // z
  }

  while(true){
    for(int i = 0; i < num; i++ ){
      activateLED(drops[i][0], drops[i][1], drops[i][2]) 
      drops[i][2]--;
      if(drops[i][2] < 0){ // check if the rain drop has a negative position
        drops[i][0] = (int) random(0,4); 
        drops[i][1] = (int) random(0,4); 
        drops[i][2] = 3; //goes back to top
      }
    }
  }
}

void loop() {
  for (int l = 0; l < 4; l++) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        cube.activate(x, y, l);
        delay(100);
      }
    }
  }

  for (int l = 0; l < 4; l++) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        cube.activate(y, x, l);
        delay(100);
      }
    }
  }

  for (int l = 0; l < 4; l++) {
    for (int y = 0; y < 4; y++) {
      for (int x = 0; x < 4; x++) {
        cube.activate(l, y, x);
        delay(100);
      }
    }
  }
}
