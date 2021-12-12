#include "../include/main.h"
#include  "../include/autonomous.h"



void leftBtn(){

}
void centerBtn(){

}
void rightBtn(){

}
void initialize() {
	pros::lcd::initialize();
	pros::lcd::register_btn0_cb(leftBtn);
	pros::lcd::register_btn1_cb(centerBtn);
	pros::lcd::register_btn2_cb(rightBtn);
	inertial.tare();
	FrontLeft.set_brake_mode(MOTOR_BRAKE_COAST);
	FrontRight.set_brake_mode(MOTOR_BRAKE_COAST);
	BackRight.set_brake_mode(MOTOR_BRAKE_COAST);
	BackLeft.set_brake_mode(MOTOR_BRAKE_COAST);
	delay(2000);
  autonSelector();
}

void disabled() {
	control.clear();
	delay(200);
}

void competition_initialize() {}

void autonomous() {
  switch(selected){
     case 0:
		 break;
     case 1:
		 break;
     case 2:
		 break;
     case 3:
		 break;
     case 4:
		 break;
     case 5:
		 break;
     case 6:
		 break;
     case 7:
		 break;
		 case 8:
		 break;
   }
	return;
}



void my_task_fn(void* param) {
	std::string t =std::to_string( (FrontLeft.get_temperature()+FrontRight.get_temperature() + BackLeft.get_temperature()+ BackRight.get_temperature()+Clamp.get_temperature()+FBarR.get_temperature()+ FBarL.get_temperature())/7);
	control.print(1, 1,t.c_str());
		delay(200);
}



void opcontrol() {

	master.clear();
  int goalHeight = 0;
	double prevr = 0;
	double prevl = 0;
	double multiplier = 2;
  while (true){
	  Task my_task(my_task_fn);
		//Task climbmode_(climbmode);
		double power = control.get_analog(ANALOG_LEFT_Y);
		double turn = control.get_analog(ANALOG_LEFT_X);
		driverControl(multiplier*power+turn, multiplier*power - turn);
		if (control.get_digital(E_CONTROLLER_DIGITAL_RIGHT)){

		}
		if (control.get_digital(E_CONTROLLER_DIGITAL_LEFT)){

		}
		if (control.get_digital(E_CONTROLLER_DIGITAL_X)){

		}
		else if (control.get_digital(E_CONTROLLER_DIGITAL_B)){

		}
		else{

		}
    if (control.get_digital(E_CONTROLLER_DIGITAL_R1)) {

    } else if (control.get_digital(E_CONTROLLER_DIGITAL_R2)) {

    }
		if (control.get_digital(E_CONTROLLER_DIGITAL_L1)) {


    } else if (control.get_digital(E_CONTROLLER_DIGITAL_L2)) {

    } else {

		}
		if (control.get_digital(E_CONTROLLER_DIGITAL_DOWN)){

		}
		if(control.get_digital(E_CONTROLLER_DIGITAL_Y)){

		}
    pros::delay(20);
  }
}
