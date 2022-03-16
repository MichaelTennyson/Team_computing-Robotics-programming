#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,           ,             tmotorEV3_Large, openLoop)
#pragma config(Motor,  motorB,          rightMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          leftMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)


void drive(long nMotorRatio, long dist, long power)
{
	setMotorSyncEncoder(leftMotor, rightMotor, nMotorRatio, dist, power);
	sleep(2500);
	waitUntilMotorStop(rightMotor);
	waitUntilMotorStop(leftMotor);
}

task main()
{
	int random1 = random(100);


	while (getButtonPress(buttonEnter) == 0)
		{
			int dist;

			displayCenteredTextLine(1, "up = 10cm");
			displayCenteredTextLine(2, "down = 40cm");
			displayCenteredTextLine(3, "left = 60cm");
			displayCenteredTextLine(4, "right = 80cm");


			if (getButtonPress(buttonUp))
			{
				dist = 10;
				displayCenteredBigTextLine(4, "Dist is %d cm",dist);
				drive(0, 200, random1);

			}
			else if (getButtonPress(buttonDown))
			{
				dist = 40;
				displayCenteredBigTextLine(4, "Dist is %d cm",dist);
				drive(0, 800, random1);

			}
			else if (getButtonPress(buttonLeft)){
				dist = 60;
				displayCenteredBigTextLine(4, "Dist is %d cm",dist);
				drive(0, 1200, random1);

			}
			else if (getButtonPress(buttonRight)){

				dist = 80;
				displayCenteredBigTextLine(4, "Dist is %d cm",dist);
				drive(0, 1600, random1);

			}

		}

}
