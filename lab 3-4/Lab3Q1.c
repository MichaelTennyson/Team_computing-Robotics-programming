#pragma config(Sensor, S1,     touch,          sensorEV3_Touch)
#pragma config(Sensor, S2,     color,          sensorEV3_Color)
#pragma config(Sensor, S3,     ultrasonic,     sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void drive(long nMotorRatio, long dist, long power)
{
	setMotorSyncEncoder(leftMotor,rightMotor, nMotorRatio, dist,power);
	sleep(1000);
}

//unction that makes robot turn right
void turn90(long nMotorRatio, long dist, long power)
{
	setMotorSyncEncoder(leftMotor,rightMotor, nMotorRatio, dist,power);
	sleep(1000);
}

task main()
{
	drive(0,1000,50);
	turn90(40,0,50);
}
