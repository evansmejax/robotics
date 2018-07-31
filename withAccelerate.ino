/*NOTES
** Computer science robotics project
 * algorithm designed by Evans Kiprotich Kiplagat
 * COM/0025/16
 * Program for a line follower Robot
 * C programming
 * Program Compiled By Evans Kiprotich Kiplagat
 * COM/0025/16
 * All Rights Reserved
 * evanslagat911@gmail.com
 * Whatsapp:: @0792281868...
 * Website :: https://www.programmingempire.tk
**/
#include  <Servo.h>
Servo     servoGrip;
#include  "evansDeclarations.h"
#include  "evansCoolFuncLib.h"

void setup() {
 setUpAllPins(); 
}
void loop(){ 
  clearTheHighWay();
}

void clearTheHighWay(){
  applyFowardGear(3);
  followTheLineExpectingARightTurn();
  makeASharpRightTurn();
  applyFowardGear(2);
  followLineUntilYouFindAload();
  grabLoadAndLiftArmToHeight(&button15cm); 
  carryLoadToDroppingArea();
  liftArmDownToHeight(&button5cm);
  releaseTheObstacleAndLiftArmToHeight(&button10cm);
  applyReverseGear(1);
  makeAReverseLineFollowExpectingRightTurn();
  makeASharpRightTurn();   
  followLineUntilYouFindAload(); 
  grabLoadAndLiftArmToHeight(&button20cm);
  carryLoadToDroppingArea();
  liftArmDownToHeight(&button15cm);
  releaseTheObstacleAndLiftArmToHeight(&button20cm);
  applyReverseGear(2);
  makeAReverseLineFollowExpectingLeftTurn();
  makeASharpLeftTurn();
  solveTennisBallPuzzle();
  startRescue();
} 

void startRescue(){
  makeAReverseLineFollowExpectingLeftTurn();
  makeASharpLeftTurn();
  applyFowardGear(2);
  solvePatientAPuzzle();
  applyFowardGear(2);
  followTheLineExpectingALeftTurn();
  makeASharpLeftTurn();
  applyFowardGear(3);
  followTheLineExpectingARightTurn();
  makeASharpRightTurn();
  applyFowardGear(4);
  followTheLineExpectingARightTurn();
  applyFowardGear(2);
  carryLoadToDroppingArea();
  releaseTheObstacle();              
  applyReverseGear(2);
  makeAReverseLineFollowExpectingRightTurn();
  makeASharpRightTurn();
  followLineUntilYouFindAload();
  grabLoadAndLiftArmToHeight(&button15cm); 
  carryLoadToDroppingArea();
  liftArmDownToHeight(&button10cm);
  releaseTheObstacleAndLiftArmToHeight(&button15cm);
  applyReverseGear(1);
  makeAReverseLineFollowExpectingLeftTurn();
  makeASharpLeftTurn();
  applyFowardGear(2);
  followLineUntilYouFindAload(); 
  liftArmDownToHeight(&button20cm);                     
  servoCloseGrip(servoCloseAngle,defaultOpenDuration);
  applyReverseGear(1);
  makeAReverseLineFollowExpectingRightTurn();
  delay(200);
  makeASharpRightTurn();
  followTheLineExpectingARightTurn();
  makeASharpRightTurn();  
  applyFowardGear(4);
  followTheLineExpectingACoolRightTurn();
  makeASharpRightTurn();
  applyFowardGear(2);
  carryLoadToDroppingArea();
  releaseTheObstacleAndLiftArmToHeight(&button30cm);
  goToParking();
}

void goToParking(){
  makeARotationToTurnBack();
  applyFowardGear(4);
  followTheRoadExpectingACoolLeftTurn();
  makeASpecialLeftTurn();
  finalLap();
  endOfTasks();
}

/*NOTES
** Computer science robotics project
 * algorithm designed by Evans Kiprotich 
 * COM/0025/16
 * Program for a line follower Robot
 * C programming
 * Program Compiled By Evans Kiprotich Kiplagat
 * COM/0025/16
 * All Rights Reserved
 * evanslagat911@gmail.com
 * Whatsapp:: @0792281868...
 * Website :: https://www.github.com/evanMeja
**/
