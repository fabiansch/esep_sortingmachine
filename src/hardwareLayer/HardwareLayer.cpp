/*
 * HardwareAbstractionLayer.cpp
 *
 *  Created on: 16.10.2017
 *      Author: abj240
 */

#include "HardwareLayer.h"
#include "Header.h"

#include <csignal>
#include <sys/neutrino.h>
#include <hw/inout.h>

namespace hardwareLayer {

void signalHandler( int signum );

HardwareLayer::HardwareLayer() :
serial(signalGenerator),
_motor(actuators::Motor::instance(signalGenerator)),
_switchPoint(actuators::SwitchPoint::instance()),
_trafficLight(mmi::TrafficLight::instance()),
_heightSensor(sensors::HeightSensor::instance()),
_ButtonLEDs(mmi::ButtonLEDs::instance())
{
	LOG_SCOPE;

	signal(SIGINT,  signalHandler);
	signal(SIGTERM, signalHandler);

	startUpRoutine();
}

HardwareLayer::~HardwareLayer() {
	LOG_SCOPE;

	shutDownRoutine();
}

void HardwareLayer::motorStart() {
	_motor.start();
}

void HardwareLayer::motorStop() {
	_motor.stop();
}

void HardwareLayer::motorSlow() {
	_motor.setSlow();
}

void HardwareLayer::motorFast() {
	_motor.clearSlow();
}

void HardwareLayer::motorLock(bool lock) {
	_motor.lock(lock);
}

void HardwareLayer::motorRotateClockwise() {
	_motor.setClockwiseRotation();
}

void HardwareLayer::motorRotateCounterclockwise() {
	_motor.setCounterclockwiseRotation();
}

void HardwareLayer::switchPointOpen(){
	_switchPoint.open();
}

void HardwareLayer::switchPointClose(){
	_switchPoint.close();
}

void HardwareLayer::greenLightOn(){
	_trafficLight.greenLightOn();
}

void HardwareLayer::greenLightOff(){
	_trafficLight.greenLightOff();
}

void HardwareLayer::greenLightLock(bool lock) {
	_trafficLight.lockGreen(lock);
}


void HardwareLayer::yellowLightOn(){
	_trafficLight.yellowLightOn();
}

void HardwareLayer::yellowLightOff(){
	_trafficLight.yellowLightOff();
}

void HardwareLayer::redLightOn(){
	_trafficLight.redLightOn();
}

void HardwareLayer::redLightOff(){
	_trafficLight.redLightOff();
}

void HardwareLayer::blinkGreen(Speed speed) {
	_trafficLight.blinkGreen(speed);
}

void HardwareLayer::blinkYellow(Speed speed) {
	_trafficLight.blinkYellow(speed);
}

void HardwareLayer::blinkRed(Speed speed) {
	_trafficLight.blinkRed(speed);
}

void HardwareLayer::StartLEDOn(){
	_ButtonLEDs.LEDStartOn();
}

void HardwareLayer::StartLEDOff(){
	_ButtonLEDs.LEDStartOff();
}

void HardwareLayer::ResetLEDOn(){
	_ButtonLEDs.LEDResetOn();
}

void HardwareLayer::ResetLEDOff(){
	_ButtonLEDs.LEDResetOff();
}

void HardwareLayer::Q1LEDOn(){
	_ButtonLEDs.LEDQ1On();
}

void HardwareLayer::Q1LEDOff(){
	_ButtonLEDs.LEDQ1Off();
}

void HardwareLayer::Q2LEDOn(){
	_ButtonLEDs.LEDQ2On();
}
void HardwareLayer::Q2LEDOff(){
	_ButtonLEDs.LEDQ2Off();
}

Signal HardwareLayer::getSignal() {
	return signalGenerator.nextSignal();
}

void HardwareLayer::clearSignalBuffer() {
	signalGenerator.clearSignalBuffer();
}

void HardwareLayer::clearItemBuffer(){
	serial.getReceiver().getItemBuffer().reset();
}

void HardwareLayer::sendSerial(Signal signal) {
	serial.send(signal);
}

void HardwareLayer::sendItemViaSerial(logicLayer::Item* item) {
	serial.send(item);
}

logicLayer::Item HardwareLayer::getPassedItem() {
	return serial.getReceiver().getItemBuffer().pullItem();
}

int HardwareLayer::getItemBufferSize(){
	return serial.getReceiver().getItemBuffer().size();
}

uint16_t HardwareLayer::getHeight() {
	return _heightSensor.getHeight();
}

io::SignalGenerator& HardwareLayer::getSignalGenerator(){
	return this->signalGenerator;
}

void HardwareLayer::startUpRoutine() {
	redLightOff();
	yellowLightOff();
	greenLightOff();
	switchPointClose();
	motorStop();
	motorFast();
	motorRotateClockwise();

	switchPointOpen();
	greenLightOn();		WAIT(250);
	yellowLightOn();	WAIT(250);
	redLightOn(); 		WAIT(250);
	greenLightOff();	WAIT(250);
	yellowLightOff();	WAIT(250);
	redLightOff();		WAIT(250);

	switchPointClose();
	greenLightOn();		WAIT(250);
	yellowLightOn();	WAIT(250);
	redLightOn(); 		WAIT(250);
	greenLightOff();	WAIT(250);
	yellowLightOff();	WAIT(250);
	redLightOff();		WAIT(250);

}

void HardwareLayer::shutDownRoutine() {
	redLightOff();
	yellowLightOff();
	greenLightOff();
	switchPointClose();
	motorStop();
	motorFast();
	motorRotateClockwise();

	redLightOn(); 		WAIT(250);
	yellowLightOn();	WAIT(250);
	greenLightOn();		WAIT(250);
	redLightOff();		WAIT(250);
	yellowLightOff();	WAIT(250);
	greenLightOff();	WAIT(250);

	redLightOn(); 		WAIT(250);
	yellowLightOn();	WAIT(250);
	greenLightOn();		WAIT(250);
	redLightOff();		WAIT(250);
	yellowLightOff();	WAIT(250);
	greenLightOff();	WAIT(250);
}

void signalHandler( int signum ) {
   cout << "Interrupt signal (" << signum << ") received."<<endl;
   cout << "Begin stopping system in a safely manner.." << endl;
   LOG_ERROR << "Interrupt signal (" << signum << ") received."<<endl;

   out8(0x300, 0b00001000); // stop motor, close switch point, turn off lights
   out8(0x302, 0); // turn off led's

   cout << "Finish stopping system in a safely manner." << endl;
   cout << "Good bye." << endl;

   _Exit(signum);
}

} /* hardwareLayer */
