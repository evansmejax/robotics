/*defining all the pins*/
#define    IR_SENSOR_LEFT_FAR       A1
#define    IR_SENSOR_LEFT_B         A7
#define    IR_SENSOR_LEFT_A         A9
#define    IR_SENSOR_LEFT_CENTER    A12
#define    IR_SENSOR_RIGHT_CENTER   A8
#define    IR_SENSOR_RIGHT_A        A6
#define    IR_SENSOR_RIGHT_B        A11
#define    IR_SENSOR_RIGHT_FAR      A2
#define    IR_SENSOR_OBSTACLE       A0
#define    BUTTON_0_CM              28
#define    BUTTON_5_CM              29
#define    BUTTON_10_CM             30
#define    BUTTON_15_CM             31
#define    BUTTON_20_CM             32
#define    BUTTON_30_CM             33
#define    UPWARD_MOTOR_MOVE        26
#define    DOWN_MOTOR_MOVE          27
#define    ENABLE_LIFT              4
#define    ENA                       2        
#define    ENB                      3         
#define    IN1                      22        
#define    IN2                      23        
#define    IN3                      24        
#define    IN4                      25       

//Variables for the sensor reading 
int rsc,rsa,rsb,lsc,lsa,lsb,fcl,fcr;

float volts;

//variables to store button readings
int button0cm,button5cm,button10cm,button15cm,button20cm,button30cm;

/*DECLARING AND INITIALIZING USEFUL DYNAMIC VARIABLES
default speeds
*/
int   liftSpeedUp,liftSpeedDown;
int   servoCloseAngle,servoOpenAngle,defaultOpenDuration,servoAngle,currentServorAngle ;
int   fowardSpeed,straightHighSpeed,straightLowSpeed,leastStopSpeed,turn360Speed;
int   high90degTurnSpeed,low90degTurnSpeed;
int   reverseHighSpeed,reverseLowSpeed,reverseMoveCorrectionSpeed;
int   reverseMoveSpeed,reverseSlowSpeed,reverseTurnMoveSpeed;
int   patientALowSpeed,patientAHighSpeed;
int   maxSenseObstacleDistance,currentSenseDistance;
int   threshold;
int   fowardDelay,droppingDelay,servoDelayTime;
