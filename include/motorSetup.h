#include "main.h"
#include "pid.h"
#include "driveTrain.h"


using namespace pros;

const double ticksPerDeg = 900/360;
const double robotSpeed = 200;
const double rotationSpeed = 200;

extern pros::Motor FrontLeft;
extern pros::Motor FrontRight;
extern pros::Motor BackLeft;
extern pros::Motor BackRight;


//Ports
const int FLPort = 3;
const int FRPort = 7;
const int BLPort = 11;
const int BRPort = 5;
const int PBPort = 10;
const int FBRPort = 8;
const int FBLPort = 9;
const int CPort = 12;
const int IMUPort = 13;


pros::Controller control (pros::E_CONTROLLER_MASTER);

ControllerButton RUp(ControllerDigital::R1);
ControllerButton RDown(ControllerDigital::R2);
ControllerButton A(ControllerDigital::A);
ControllerButton B(ControllerDigital::B);
ControllerButton X(ControllerDigital::X);
ControllerButton Y(ControllerDigital::Y);
ControllerButton left(ControllerDigital::left);
ControllerButton right(ControllerDigital::right);
ControllerButton up(ControllerDigital::up);
ControllerButton down(ControllerDigital::down);

pros::Motor Clamp(CPort, E_MOTOR_GEARSET_36, false);
pros::Motor FrontLeft(FLPort, true);
pros::Motor FrontRight(FRPort, false);
pros::Motor BackLeft(BLPort, true);
pros::Motor BackRight(BRPort, false);
pros::Motor FBarR(FBRPort, false);
pros::Motor FBarL(FBLPort, true);
pros::Imu inertial(IMUPort);

pros::ADIDigitalOut piston ('A',true);

driveTrain drive = driveTrain(3.25, 11.5);
pidController autonlinear = pidController(0, 0.002, 0, 0.0001);
pidController autonrotation = pidController(0, 0.001, 0, 0.0001);

void calibrateSensors(){
  lcd::print(1, "Calibrating");
  inertial.reset();

  int timeInit = millis();

  inertial.reset();
  while(inertial.is_calibrating()){
    lcd::print(1, "Calibrating");
    delay(10);
  }
  delay(2000);
  lcd::print(1, "Calibration took %f", millis() - timeInit);

  autonlinear.tolerance = 0.2;
}
