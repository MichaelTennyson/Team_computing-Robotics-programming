#pragma config(StandardModel, "EV3_REMBOT")
//
// Test program as part of LAB2
//

void turn90degreesleft()
{
	setMotorSpeed(leftMotor, 25);
	setMotorSpeed(rightMotor, 50);
	sleep(2000);
}
void turn90degreesright()
{
	setMotorSpeed (rightMotor, 50);
	setMotorSpeed (leftMotor, 25);
	sleep(2000);
}
void goForward1second()
{
	setMotorSpeed (leftMotor, 50);
	setMotorSpeed (rightMotor, 50);
	sleep(1000);
}
void swingRight90degrees()
{
	setMotorSpeed (leftMotor, 50);
	setMotorSpeed (rightMotor, -50);
	sleep(1000);
}
void swingLeft90degrees()
{
	setMotorSpeed (leftMotor, -50);
	setMotorSpeed (rightMotor, 50);
	sleep(1000);
}
void reverse1second()
{
	setMotorSpeed (leftMotor, -50);
	setMotorSpeed (rightMotor, -50);
	sleep(1000);
}
task main()
{
	turn90degreesleft();
	turn90degreesright();
	goForward1second();
	swingRight90degrees();
	swingLeft90degrees();
	reverse1second();
}
