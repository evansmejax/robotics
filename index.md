## Robotics

You can use the [editor on GitHub](https://github.com/evansMeja/arduino-uno-robotics/edit/gh-pages/index.md) to maintain and preview the content for your website in Markdown files.

Whenever you commit to this repository, GitHub Pages will run [Jekyll](https://jekyllrb.com/) to rebuild the pages in your site, from the content in your Markdown files.

### Markdown

Markdown is a lightweight and easy-to-use syntax for styling your writing. It includes conventions for


Syntax highlighted code block

# Header 1

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

- Bulleted
- List

1. Numbered
2. List

**Bold** and _Italic_ and `Code` text

[Link](url) and ![Image](src)


For more details see [GitHub Flavored Markdown](https://guides.github.com/features/mastering-markdown/).

### Jekyll Themes

Your Pages site will use the layout and styles from the Jekyll theme you have selected in your [repository settings](https://github.com/evansMeja/arduino-uno-robotics/settings/pages). The name of this theme is saved in the Jekyll `_config.yml` configuration file.

### Support or Contact

Having trouble with Pages? Check out our [documentation](https://docs.github.com/categories/github-pages-basics/) or [contact support](https://support.github.com/contact) and we’ll help you sort it out.
