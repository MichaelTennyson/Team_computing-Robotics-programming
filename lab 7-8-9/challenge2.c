#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,           ,             tmotorEV3_Large, openLoop)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


void drive(long nMotorRatio, long dist, long power)
{
	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, 1000, power);
	sleep(1000);

}
//Drive
void driveForward()
{
	for(int i=1; i<=10;i++)
	{
		setLEDColor(ledGreenFlash);
		setMotorSyncEncoder(leftMotor,rightMotor,0,1000,10);
		waitUntilMotorStop(motorB);
		sleep(500);
	}//end for
}
void turnright()
{
	wait1Msec(1000);

	resetGyro(gyroSensor);

	wait1Msec(2000);

	motor(motorB)=10;
	motor(motorC)=-10;
	//waits until gyrosensor>86
	waitUntil(abs(getGyroDegrees(gyroSensor))>86);

	motor(motorB) = 0;
	motor(motorC) = 0;

	wait1Msec(1000);


}
// Pause Robot
void pause (long nMotorRatio, long dist, long power)
{
	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, dist, power);
	sleep(1000);
}

task main()
{

	long nMotorRatio=0;
	long dist=100000;
	long power=100;
	int threshold =50;

	repeatUntil(getTouchValue(S1)==1)
	{
		driveForward();
	}//end repeat

	dist=60;
	drive(nMotorRatio, dist, -power);
	pause(0,0,0);
  turnright();
	pause(0,0,0);
	while(true)
  {
		if(getColorAmbient(S3) < threshold)
		{
			driveForward();
		}//end if
		else
		{
		pause(0,0,0);
		}//end else
		pause(0,0,0);
	}//end while
}//end main()
