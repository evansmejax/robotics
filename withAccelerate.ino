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
 * Whatsapp:: +254740664839...
 * Website :: https://www.tuzowe.co.ke
**/
#include  <Servo.h>
Servo     servoGrip;
#include  "evansDeclarations.h"
#include  "evansCoolFuncLib.h"

void setup() {
 setUpAllPins(); 
}
void loop(){ 
  startRobotRescueMission();           //Robot rescue entry point
}

void startRobotRescueMission(){
  clearTheHighWay();                   //Task 1
  startRescue();                       //Task 2
  goToParking();                       //Task 3
}

void clearTheHighWay(){                       //general functions on clearing the highways and heading to disaster management zone
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
} 

void startRescue(){                           //collection of functions to rush the victims of fire outbreak to disaster management zone
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
}

void goToParking(){                              // The robot has completed all assigned task and goes to sleeping mode
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
 * Whatsapp:: +254740664839...
 * Website :: https://www.tuzowe.co.ke
 * Website :: https://www.github.com/evanMeja
**/
