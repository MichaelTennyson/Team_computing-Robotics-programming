#pragma config(StandardModel, "EV3_REMBOT")

/*------------------------------------------------------------------------------------------------
This program makes the robot go forward for 5 seconds,  turn 180degrees and travel back to the exactsame location it started it.


------------------------------------------------------------------------------------------------*/

task main()
{
	// Move forward at half power for 5 seconds
	setMotorSpeed(leftMotor, 50);	//Set the leftMotor (motor1) to half power forward (50)
	setMotorSpeed(rightMotor, 50); 	//Set the rightMotor (motor6) to half power forward (50)
	sleep(5000);			//Wait for 5 seconds before continuing on in the program.

		// Turn left at full power for 0.75 seconds
	setMotorSpeed(leftMotor, 100);	//Set the leftMotor (motor1) to full power forward (100)
	setMotorSpeed(rightMotor, -100);//Set the rightMotor (motor6) to full power reverse (-100)
	sleep(750);			//Wait for .75 second before continuing on in the program.

	// Move reverse at half power for 5 seconds
	setMotorSpeed(leftMotor, -50);	//Set the leftMotor (motor1) to half power reverse (50)
	setMotorSpeed(rightMotor, -50);	//Set the rightMotor (motor6) to half power reverse (50)
	sleep(5000);			//Wait for 5 seconds before continuing on in the program.


}
