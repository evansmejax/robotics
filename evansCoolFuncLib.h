void initialiseDefaultVariables(){
liftSpeedUp                   = 170;
liftSpeedDown                 = 140;

leastStopSpeed                = 0;
servoCloseAngle               = 5;
servoOpenAngle                = 60;

fowardSpeed                   = 100;
turn360Speed                  = 140;
straightHighSpeed             = 135;
straightLowSpeed              = 52;

high90degTurnSpeed            = 182;
low90degTurnSpeed             = 65;

reverseHighSpeed              = 113;
reverseLowSpeed               = 103;
reverseMoveSpeed              = 140;
reverseTurnMoveSpeed          = 120;
reverseMoveCorrectionSpeed    = 81;

patientALowSpeed              = 10;
patientAHighSpeed             = 120;

maxSenseObstacleDistance      = 15;
currentSenseDistance          = 100;

defaultOpenDuration           = 2000;
threshold                     = 500;
reverseSlowSpeed              = 103;
fowardDelay                   = 0;
droppingDelay                 = 0; 
currentServorAngle            = 40;
servoDelayTime                = 40;
}
void readSensors(){          
  analogReference(EXTERNAL);
  rsc   =analogRead(IR_SENSOR_RIGHT_CENTER);
  lsc   =analogRead(IR_SENSOR_LEFT_CENTER);
  rsa   =analogRead(IR_SENSOR_RIGHT_A);
  rsb   =analogRead(IR_SENSOR_RIGHT_B);
  lsa   =analogRead(IR_SENSOR_LEFT_A);
  lsb   =analogRead(IR_SENSOR_LEFT_B);
  fcl   =analogRead(IR_SENSOR_LEFT_FAR);
  fcr   =analogRead(IR_SENSOR_RIGHT_FAR);
}

void setNewFowardSpeed(int fowardSpd,int high,int low){
fowardSpeed=fowardSpd;
straightHighSpeed=high;
straightLowSpeed=low;
}

void readButtons(){
  button0cm          = digitalRead(BUTTON_0_CM);
  button5cm          = digitalRead(BUTTON_5_CM);
  button10cm         = digitalRead(BUTTON_10_CM);
  button15cm         = digitalRead(BUTTON_15_CM);
  button20cm         = digitalRead(BUTTON_20_CM);
  button30cm         = digitalRead(BUTTON_30_CM);
}


//detailed function to sets arm parameters
void setArmVals(unsigned char upMotorReading,unsigned char downMotorReading,int enableSpeed){               
    digitalWrite(UPWARD_MOTOR_MOVE, upMotorReading);
    digitalWrite(DOWN_MOTOR_MOVE, downMotorReading);
    analogWrite(ENABLE_LIFT ,enableSpeed);
    readButtons();
}

void setReverseSpeed(int reverseSpeed,int highSpeed,int lowSpeed){
reverseMoveSpeed = reverseSpeed;
reverseHighSpeed = highSpeed;
reverseLowSpeed  = lowSpeed;
}

void prepareRobot();
void setUpAllPins(){
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IR_SENSOR_RIGHT_CENTER, INPUT);
  pinMode(IR_SENSOR_RIGHT_A, INPUT);
  pinMode(IR_SENSOR_RIGHT_B, INPUT);
  pinMode(IR_SENSOR_LEFT_CENTER, INPUT);
  pinMode(IR_SENSOR_LEFT_A, INPUT);
  pinMode(IR_SENSOR_LEFT_B, INPUT);
  pinMode(IR_SENSOR_LEFT_FAR, INPUT);
  pinMode(IR_SENSOR_RIGHT_FAR, INPUT);
  pinMode(IR_SENSOR_OBSTACLE, INPUT);
  pinMode(UPWARD_MOTOR_MOVE, OUTPUT);
  pinMode(DOWN_MOTOR_MOVE, OUTPUT);
  pinMode(ENABLE_LIFT, OUTPUT);
  pinMode(BUTTON_0_CM, INPUT_PULLUP);
  pinMode(BUTTON_5_CM, INPUT_PULLUP); 
  pinMode(BUTTON_10_CM, INPUT_PULLUP);
  pinMode(BUTTON_15_CM, INPUT_PULLUP);
  pinMode(BUTTON_20_CM, INPUT_PULLUP); 
  pinMode(BUTTON_30_CM, INPUT_PULLUP); 
  prepareRobot();
  Serial.begin (9600); 
}

//detailed function to sets motor parameters
void  setVals(unsigned char fowardLeft,unsigned char backwardLeft,unsigned char fowardRight,unsigned char backwardRight,int ENASpeed,int enBSpeed ){  
    readSensors();
    digitalWrite(IN1,fowardLeft);
    digitalWrite(IN2,backwardLeft);
    digitalWrite(IN3,fowardRight);
    digitalWrite(IN4,backwardRight);
    analogWrite(ENA,ENASpeed);
    analogWrite(ENB,enBSpeed);
}

//functions to set robot analogues values and speeds

void moveFowardSP() {  setVals(HIGH,LOW,HIGH,LOW,90,leastStopSpeed);}

void turnLeft90() {  setVals(LOW,HIGH,HIGH,LOW,low90degTurnSpeed,high90degTurnSpeed);}

void turnRight90(){  setVals(HIGH,LOW,LOW,HIGH,high90degTurnSpeed,low90degTurnSpeed);}

void turn360()    {  setVals(LOW,HIGH,HIGH,LOW,turn360Speed,turn360Speed);}

void reverseRight(){   setVals(LOW,HIGH,LOW,HIGH,reverseLowSpeed,reverseHighSpeed);}

void reverseLeft(){ setVals(LOW,HIGH,LOW,HIGH,reverseHighSpeed,reverseLowSpeed);}

void moveReverse(){ setVals(LOW,HIGH,LOW,HIGH,reverseMoveSpeed,reverseMoveSpeed);}

//functions to set the arm movement values accordingly
void armMoveUp()  {  setArmVals(HIGH,LOW,liftSpeedUp);                                 }
void armMoveDown(){  setArmVals(LOW,HIGH,liftSpeedDown);                               }
void armStopMove(){  setArmVals(LOW,LOW ,leastStopSpeed);                              }

void servoOpenGrip(int openServoAngleLimit,int openingDurationInMilliSeconds){ 
     servoDelayTime=(openingDurationInMilliSeconds/openServoAngleLimit);
     while(currentServorAngle<=openServoAngleLimit){
     servoGrip.write(currentServorAngle);    
     delay(servoDelayTime);
     currentServorAngle++;
     }
}

//closes the robot's arms in the specified duration in milliseconds and angle in degrees
void servoCloseGrip(int closeServoAngleLimit,int closingDurationInMilliSeconds){
     servoDelayTime=(closingDurationInMilliSeconds/currentServorAngle);
     while(currentServorAngle>closeServoAngleLimit){
     servoGrip.write(currentServorAngle);    
     delay(servoDelayTime);
     currentServorAngle--;
     }
    
}



//functions that make use of the arm: lift up and lift down arm
void liftArmDownToHeight(int *btnPtr){
    while(*btnPtr == 1){
          armMoveDown();
    }
    armStopMove();
}

void liftTheArmUpToHeight(int *btnPtr){
    while (*btnPtr == 1)
          {
            armMoveUp();
          }
    armStopMove();
}

void grabLoadAndLiftArmToHeight(int *btnPtr){
     liftArmDownToHeight(&button0cm);
     servoCloseGrip(servoCloseAngle,2000);
     liftTheArmUpToHeight(btnPtr);
}

void prepareRobot(){
  initialiseDefaultVariables();
  readButtons();
  readSensors();
  servoCloseGrip(servoCloseAngle,500);
  servoOpenGrip(servoOpenAngle,500);
  //liftArmDownToHeight(&button0cm);
  //liftTheArmUpToHeight(&button5cm);
}

//boolean function to define when to turnleft, right of move the robot foward
boolean canTurnLeft(){return
((lsb<=threshold && lsa<=threshold && lsc<=threshold  && rsc> threshold   && rsa > threshold  && rsb > threshold) || 
 (lsb> threshold && lsa<=threshold && lsc<=threshold  && rsc<=threshold   && rsa > threshold  && rsb > threshold) ||
 (lsb> threshold && lsa<=threshold && lsc<=threshold  && rsc> threshold   && rsa > threshold  && rsb > threshold) ||
 (lsb<=threshold && lsa<=threshold && lsc> threshold  && rsc> threshold   && rsa > threshold  && rsb > threshold) ||
 (lsb<=threshold && lsa> threshold && lsc> threshold  && rsc> threshold   && rsa > threshold  && rsb > threshold) ||
 (lsb> threshold && lsa<=threshold && lsc> threshold  && rsc> threshold   && rsa > threshold  && rsb > threshold) ||
 (lsb> threshold && lsa>threshold  && lsc<=threshold  && rsc> threshold   && rsa > threshold  && rsb > threshold));
}

boolean canTurnRight(){return
((lsb > threshold && lsa > threshold && lsc<=threshold  && rsc<=threshold  && rsa<=threshold  && rsb> threshold)  ||
 (lsb > threshold && lsa > threshold && lsc> threshold  && rsc<=threshold  && rsa<=threshold  && rsb<=threshold)  ||
 (lsb > threshold && lsa > threshold && lsc> threshold  && rsc> threshold  && rsa<=threshold  && rsb<=threshold)  ||
 (lsb > threshold && lsa > threshold && lsc> threshold  && rsc<=threshold  && rsa<=threshold  && rsb> threshold)  ||
 (lsb > threshold && lsa > threshold && lsc> threshold  && rsc> threshold  && rsa> threshold  && rsb<=threshold)  ||
 (lsb > threshold && lsa > threshold && lsc> threshold  && rsc<=threshold  && rsa> threshold  && rsb> threshold)  ||
 (lsb > threshold && lsa > threshold && lsc> threshold  && rsc> threshold  && rsa<=threshold  && rsb> threshold)) ;
}

boolean canMaintainStraightLine(){return
((lsa>threshold  && lsc<=threshold && rsc<=threshold && rsa>threshold)||
 (lsa<=threshold && lsc<=threshold && rsc<=threshold && rsa<=threshold));
}

boolean allSensorsAreBlack(){return
((fcl>threshold && fcr>threshold && lsb>threshold && lsa>threshold &&
  lsc>threshold && rsc>threshold && rsa>threshold && rsb>threshold));
}

boolean allMiddleAreSensorsAreBlack(){return
((lsb>threshold && lsa>threshold && lsc>threshold &&
  rsc>threshold && rsa>threshold && rsb>threshold));
}

boolean aMiddleSensorsIsWhite(){return
((lsb<=threshold || lsa<=threshold ||lsc<=threshold ||
  rsc<=threshold || rsa<=threshold || rsb<=threshold));
}

boolean allMiddleSensorsAreWhite(){return
((lsb<=threshold && lsa<=threshold && lsc<=threshold && 
  rsc<=threshold && rsa<=threshold && rsb<=threshold));
}

boolean canContinueMakingSharpTurn(){return
  (fcl<=threshold ||  lsb<=threshold || rsb<=threshold || fcr<=threshold);
}



void moveFoward           ()   {  setVals(HIGH,LOW,HIGH,LOW,fowardSpeed,fowardSpeed);                              }
void turnLeft             ()   {  setVals(HIGH,LOW,HIGH,LOW,straightLowSpeed,straightHighSpeed);                   }
void turnRight            ()   {  setVals(HIGH,LOW,HIGH,LOW,straightHighSpeed,straightLowSpeed);                   }
void moveReverseCorrection()   {  setVals(LOW,HIGH,LOW,HIGH,reverseMoveCorrectionSpeed,reverseMoveCorrectionSpeed);}

//logic to allow robot to maintain a straight line while moving foward
void followLine(){
if     (canMaintainStraightLine())  { moveFoward();                     }
else if(canTurnLeft())              { turnLeft();  delay(fowardDelay) ; }
else if(canTurnRight())             { turnRight(); delay(fowardDelay) ; }
else if(allMiddleAreSensorsAreBlack()){ moveReverseCorrection(); delay(20);}
else                                { moveFoward();delay(5);                }
}

double mapDouble(double x, double in_min, double in_max, double out_min, double out_max)  {  
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;  
} 

double getSharpSensorReading()  {  
  int noSamples=100;  
  uint32_t sumOfSamples=0;  
  uint32_t senseValue=0;  
  double senseDistance=0;  
  for (int i=0; i<noSamples; i++)  {   
     senseValue=analogRead(IR_SENSOR_OBSTACLE);                                                                     //Perform analogRead  to obtain detection currentSenseDistance 
     sumOfSamples+=senseValue;                                                                                      //combining present value above with previous results
 }  
  senseValue=sumOfSamples/noSamples;                                                                                //Calculate mean sample of the sense value currentSenseDistance
  senseDistance=senseValue;                                                                                         //Convert sense value to double   
  senseDistance=mapDouble(senseDistance,0.0,1023.0,0.0,5.0);                                                        //Convert analog pin reading to voltage  
  senseDistance = 8.075*pow(senseDistance,4) - 68.44*pow(senseDistance,3) + 210.4*pow(senseDistance,2) -  
        285.2*(senseDistance) + 161.3;  
  return senseDistance;  
}

void updateObstacleSensor(){
     currentSenseDistance = (float)getSharpSensorReading(); 
}

void stopRobot()  {  setVals(LOW,LOW,LOW,LOW,leastStopSpeed,leastStopSpeed);        }

void followLineUntilYouFindAload(){
do{
    updateObstacleSensor();
    followLine();
}while(currentSenseDistance>maxSenseObstacleDistance);
    stopRobot();
}


void applyFowardGear(int gear){
switch(gear){
case 1:
setNewFowardSpeed(90,straightHighSpeed,straightLowSpeed);
break;
case 2:
setNewFowardSpeed(100,straightHighSpeed,straightLowSpeed);         
break;
case 3:
setNewFowardSpeed(120,straightHighSpeed,straightLowSpeed);           //defaultGear
break;
case 4:
setNewFowardSpeed(125,straightHighSpeed,straightLowSpeed);
break;
case 5:
setNewFowardSpeed(140,straightHighSpeed,straightLowSpeed);
break;
}
}

void releaseTheObstacleAndLiftArmToHeight(int *btnPtr){
servoOpenGrip(servoOpenAngle,defaultOpenDuration);
   while (*btnPtr == 1)
          {
            armMoveUp();
          }
    armStopMove();
}

void solvePatientAPuzzle(){
maxSenseObstacleDistance  = 16;
followLineUntilYouFindAload();
applyFowardGear(5);
followLine();
delay(300);
grabLoadAndLiftArmToHeight(&button30cm);
maxSenseObstacleDistance  = 15;
}

void applyReverseGear(int gear){
switch(gear){ 
case 1:
setReverseSpeed(reverseTurnMoveSpeed,113,reverseSlowSpeed);     
break;
case 2:
setReverseSpeed(reverseTurnMoveSpeed,114,reverseSlowSpeed);    
break;
}
}


void releaseTheObstacle(){
servoOpenGrip(servoOpenAngle,defaultOpenDuration); 
}

void makeASharpLeftTurn(){
do{
  turnLeft90();
  }while(canContinueMakingSharpTurn());
}

void makeASharpRightTurn(){
do{
turnRight90();
}while(canContinueMakingSharpTurn());
}


void followTheLineExpectingARightTurn(){
do{
  followLine();
  }while((fcr>threshold));
}

void followTheLineExpectingACoolRightTurn(){
do{
  followLine();
  if(fcr<=threshold){
  applyFowardGear(1);
   }
  }while((fcl>threshold));
}

void followLineExpectingALeftTurn(){
do{
followLine();
}while((fcl>threshold));
}



//functions to make reverse line follow
void makeAReverseLineFollowExpectingRightTurn(){
    do{
      reverseRight();
      }while(fcr>threshold);
}

void makeAReverseLineFollowExpectingLeftTurn(){
    do{
       reverseLeft();
      }while(fcl>threshold);
}

//functions to follow the line in different circumstances


void followTheLineExpectingALeftTurn(){
do{
  followLine();
  }while((fcl>threshold));
}


void carryLoadToDroppingArea(){
    do{
    updateObstacleSensor();
    followLine();
    }while(currentSenseDistance>maxSenseObstacleDistance);
    delay(droppingDelay);
    stopRobot();
}

void makeASpecialLeftTurn(){
  do{
    turnLeft90();
  }while(!(aMiddleSensorsIsWhite()));
}

void solveTennisBallPuzzle(){
  fowardDelay=15;
  droppingDelay=50;
  followLineUntilYouFindAload();
  grabLoadAndLiftArmToHeight(&button30cm);
  carryLoadToDroppingArea();
  releaseTheObstacle();
  fowardDelay=0;
  droppingDelay=0;
}

void makeARotationToTurnBack(){
moveReverse();
delay(500);
do{
turn360();  
}while(!(allMiddleAreSensorsAreBlack()));

do{
  turn360();
  }while(!(aMiddleSensorsIsWhite()));
}


void followTheRoadExpectingACoolLeftTurn(){        
   do{
    followLine();
    }while(!(allSensorsAreBlack())); 
}

void finalLap(){
do{  
followLine();  
}while(!(allMiddleSensorsAreWhite()));
delay(1500);
}

void endOfTasks(){
  stopRobot();
  while(1);
}
