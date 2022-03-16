#pragma config(Sensor, S1,     touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     Gyro,           sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color)
#pragma config(Sensor, S4,     sonar,          sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorB,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
/*
The robot is starting at the point (1,4) and moves to the
point (4,1)
*/
//int DEGREESTOSQUARES = (360/18*SQUARE);
#define SQUARE 16
#define DEGREESTOSQUARES (360/18*SQUARE)
//10 cm per square

//mororB - leftMotor
//motorC - rightMotor
//Gyro - gyro sensor

//global variables
//initial coordinates
int myX = 1;
int myY = 4;
//orientation: 0:North(^), 1:East(>), 2:South(v), 3:West(<)
int myOrientation = 1;

//turn right function
void turnRight()
{
	//reset sensor
    wait1Msec(1000);
    resetGyro(Gyro);
    //allow sensor to settle
    wait1Msec(2000);

    //turn 90 degrees right
    motor(leftMotor) = 10;
    motor(rightMotor) = -10;
    waitUntil(abs(getGyroDegrees(Gyro)) > 27);
    motor(leftMotor) = 0;
    motor(rightMotor) = 0;

    // Allow sensor to settle
    wait1Msec(1000);
}

//Turn left  time function
void turnLeft()
{
	//reset sensor
    wait1Msec(1000);
    resetGyro(Gyro);
    //allow sensor to settle
    wait1Msec(2000);

    //turn 90 degrees right
    motor(leftMotor) = -10;
    motor(rightMotor) = 10;
    waitUntil(abs(getGyroDegrees(Gyro)) > 27);
    motor(leftMotor) = 0;
    motor(rightMotor) = 0;

    // Allow sensor to settle
    wait1Msec(1000);
}


//Turn to desired orientation based on current orientation
void turnDirection(int curOrient, int desOrient)
{
    int turnAdd = 0;
    int i;

    //is additional turn required?
    if (curOrient > desOrient)
    {
        turnAdd = 1;
    }

    //turn required times
    for (i = 0; i < (desOrient + 4 * turnAdd - curOrient); i++)
    {
        turnLeft();
    }

    myOrientation = desOrient;
}

//Move one square and update coordinates according to orientation
void moveSquare(int toMove)
{
    //change in coordinates
    int dx = 0;
    int dy = 0;

    //variables
    int i;

    //Change coordinates based on myOrientation
    switch (myOrientation)
    {
        case 0: dy = -1; break;
        case 1: dx = 1; break;
        case 2: dy = 1; break;
        case 3: dx = -1; break;
    }
		//for loop
    for (i = 0; i < (toMove); i++)
    {
        //move one square
        setMotorSyncEncoder(leftMotor, rightMotor, 0, DEGREESTOSQUARES,10);
        waitUntilMotorStop(leftMotor);
        myX = myX + dx;
        myY = myY + dy;
        wait1Msec(300);
        //show coordinates and wait
        displayCenteredBigTextLine(1, "X=%d; Y=%d", myX, myY);
        wait1Msec(1000);
    }
}



task main()
{
    //wait for Enter button to start
    while (getButtonPress(buttonEnter) == 0)
    {
        displayCenteredBigTextLine(1,"Press Enter");
        wait1Msec(300);
    }

    //show initial coordinates:
    displayCenteredBigTextLine(1, "X=%d; Y=%d", myX, myY);
    wait1Msec(1000);


    //destination coordinates
    int destX = 4;
    int destY = 1;

    //variables
    int reqOrientation;
    int toMove;

    //Move first in X coordinate
    if (destX == myX)
    {
        //do nothing
        reqOrientation = myOrientation;
        toMove = 0;
    }
    else if (destX > myX)
    {
        //turn required direction (>)
        reqOrientation = 1;
        //How many squares to move
        toMove = destX - myX;
    }
    else
    {
        //turn to required direction (<)
        reqOrientation = 3;
        //How many squares to move
        toMove = myX - destX;
    }

    //turn required direction
    turnDirection(myOrientation, reqOrientation);
    //move required distance
    moveSquare(toMove);

    //Turn required direction and move Y
    if (destY == myY)
    {
        //do nothing
        reqOrientation = myOrientation;
        toMove = 0;
    }
    else if (destY > myY)
    {
        //turn required direction (v)
        reqOrientation = 3;
        //move required distance
        toMove = destY - myY;
    }
    else
    {
        //turn required direction (^)
        reqOrientation = 0;
        //move required distance
        toMove = myY - destY;
    }

    //turn required direction
    turnDirection(myOrientation, reqOrientation);
    //move required distance
    moveSquare(toMove);

}//end taskmain()
