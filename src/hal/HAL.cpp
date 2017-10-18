/*
 * HardwareAbstractionLayer.cpp
 *
 *  Created on: 16.10.2017
 *      Author: abj240
 */

#include "HAL.h"
#include "GPIO.h"

namespace hal {

HAL::HAL() {
	LOG_SCOPE;
	_motor = actuators::Motor::instance();
	_switchPoint = actuators::SwitchPoint::instance();
	_trafficLight = mmi::TrafficLight::instance();
}

HAL::~HAL() {
	LOG_SCOPE;
	delete _motor;
	delete _switchPoint;
	delete _trafficLight;
	delete io::GPIO::instance();
}

void HAL::motorStart() {
	_motor->start();
}

void HAL::motorStop() {
	_motor->stop();
}

void HAL::motorSlow() {
	_motor->setSlow();
}

void HAL::motorFast() {
	_motor->clearSlow();
}

void HAL::motorRotateClockwise() {
	_motor->setClockwiseRotation();
}

void HAL::motorRotateCounterclockwise() {
	_motor->setCounterclockwiseRotation();
}

void HAL::switchPointOpen(){
	_switchPoint->open();
}

void HAL::switchPointClose(){
	_switchPoint->close();
}

void HAL::greenLightOn(){
	_trafficLight->greenLightOn();
}

void HAL::greenLightOff(){
	_trafficLight->greenLightOff();
}

void HAL::yellowLightOn(){
	_trafficLight->yellowLightOn();
}

void HAL::yellowLightOff(){
	_trafficLight->yellowLightOff();
}

void HAL::redLightOn(){
	_trafficLight->redLightOn();
}

void HAL::redLightOff(){
	_trafficLight->redLightOff();
}

void HAL::blinkGreen(Speed speed) {
	_trafficLight->blinkGreen(speed);
}

void HAL::blinkYellow(Speed speed) {
	_trafficLight->blinkYellow(speed);
}

void HAL::blinkRed(Speed speed) {
	_trafficLight->blinkRed(speed);
}


} /* hal */