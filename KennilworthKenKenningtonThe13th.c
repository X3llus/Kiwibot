#pragma config(Sensor, port4,  bBack,          sensorVexIQ_Touch)
#pragma config(Sensor, port5,  bLeft,          sensorVexIQ_Touch)
#pragma config(Sensor, port6,  bRight,         sensorVexIQ_Touch)
#pragma config(Motor,  motor1,          mFront,        tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor2,          mLeft,         tmotorVexIQ, PIDControl, encoder)
#pragma config(Motor,  motor3,          mRight,        tmotorVexIQ, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*

Robot Name: Kennilworth Ken Kennington The 13th
Group: Braden, Jess, Paula, Emma

*/

//sine function for front motor speed
int sineFront(int x) {
	int y = 100 * sinDegrees(x);
	return y;
}

//sine function for left motor speed
int sineLeft(int x) {
	int y = -100 * sinDegrees(x + 60);
	return y;
}

//sine function for right motor speed
int sineRight(int x) {
	int y = -100 * sinDegrees(x - 60);
	return y;
}

//determines the direction to travel and assigns motor speeds
void motorMath() {
	float dir = 0;
	dir = rand() % 360;
	displayTextLine(4, "direction is %d", dir);

	setMotorSpeed(mFront, sineFront(dir));
	setMotorSpeed(mLeft, sineLeft(dir));
	setMotorSpeed(mRight, sineRight(dir));

}

//checks all the bumpers to see if they are being pressed
bool checkBumpers() {
	if (getBumperValue(bBack) == 1 || getBumperValue(bRight) == 1 || getBumperValue(bLeft) == 1) {
		return true;
		} else {
		return false;
	}
}

//main function
task main()
{
	//seeds the random function and sets starting direction and motor speeds
	srand(nSysTime);
	motorMath();

	while (true) {
		//checks for bumpers to be pressed
		if (checkBumpers()) {
			//assignes new speeds to the motors if there is a pressed bumper
			motorMath();
		}
	}
}
