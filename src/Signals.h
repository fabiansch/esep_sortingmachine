/*
 * Signals.h
 *
 *  Created on: 18.10.2017
 *      Author: abj240
 */

#ifndef SIGNALS_H_
#define SIGNALS_H_

constexpr int cb_1 = 0b001;
constexpr int cb_2 = 0b010;
constexpr int cb_3 = 0b100;

enum class Speed {fast, slow};

enum class Signalname {
	//OTHERS
	CALIBRATION_START,
	CALIBRATION_STOP,
	//Button
	BUTTON_START_PUSHED,
	BUTTON_STOP_PUSHED,
	BUTTON_RESET_PUSHED,
	BUTTON_E_STOP_PUSHED,
	BUTTON_E_STOP_PULLED,
	//Light_barrier
	LIGHT_BARRIER_INPUT_INTERRUPTED,
	LIGHT_BARRIER_INPUT_NOT_INTERRUPTED,
	LIGHT_BARRIER_HEIGHT_INTERRUPTED,
	LIGHT_BARRIER_HEIGHT_NOT_INTERRUPTED,
	LIGHT_BARRIER_SWITCH_INTERRUPTED,
	LIGHT_BARRIER_SWITCH_NOT_INTERRUPTED,
	LIGHT_BARRIER_SLIDE_INTERRUPTED,
	LIGHT_BARRIER_SLIDE_NOT_INTERRUPTED,
	LIGHT_BARRIER_OUTPUT_INTERRUPTED,
	LIGHT_BARRIER_OUTPUT_NOT_INTERRUPTED,
	//Sensor
	SENSOR_HEIGHT_MATCH,
	SENSOR_HEIGHT_NOT_MATCH,
	SENSOR_METAL_MATCH,
	SENSOR_METAL_NOT_MATCH,
	SENSOR_SWITCH_IS_OPEN,
	SENSOR_SWITCH_IS_CLOSED,
	//Motor
	MOTOR_FORWARD,
	MOTOR_FORWARD_RUN,
	MOTOR_FORWARD_SLOW,
	MOTOR_FORWARD_FAST,
	MOTOR_FORWARD_RUN_SLOW,
	MOTOR_FORWARD_RUN_FAST,
	MOTOR_BACKWARD,
	MOTOR_BACKWARD_RUN,
	MOTOR_BACKWARD_SLOW,
	MOTOR_BACKWARD_FAST,
	MOTOR_BACKWARD_RUN_SLOW,
	MOTOR_BACKWARD_RUN_FAST,
	MOTOR_STOP,
	//LED
	LED_START_ON,
	LED_START_OFF,
	LED_RESET_ON,
	LED_RESET_OFF,
	LED_Q1_ON,
	LED_Q1_OFF,
	LED_Q2_ON,
	LED_Q2_OFF,
	//Signal_light
	SIGNAL_LIGHT_GREEN_ON,
	SIGNAL_LIGHT_GREEN_OFF,
	SIGNAL_LIGHT_YELLOW_ON,
	SIGNAL_LIGHT_YELLOW_OFF,
	SIGNAL_LIGHT_RED_ON,
	SIGNAL_LIGHT_RED_OFF,
	//Switch
	SWITCH_OPEN,
	SWITCH_CLOSE,
	//Measure
	MEASURE_REACHING_LB_HEIGHT_START,
	MEASURE_REACHING_LB_HEIGHT_STOP,
	MEASURE_REACHING_LB_SWITCH_START,
	MEASURE_REACHING_LB_SWITCH_STOP,
	MEASURE_REACHING_LB_SLIDE_START,
	MEASURE_REACHING_LB_SLIDE_STOP,
	MEASURE_REACHING_LB_OUTPUT_START,
	MEASURE_REACHING_LB_OUTPUT_STOP,
	MEASURE_VELOCITY_FAST_START,
	MEASURE_VELOCITY_FAST_STOP,
	MEASURE_VELOCITY_SLOW_START,
	MEASURE_VELOCITY_SLOW_STOP,
};

struct Signal {
	Signal(char sender, char receiver, Signalname signalname) :
	sender(sender),
	receiver(receiver),
	signalname(signalname){

	}
	char sender;
	char receiver;
	Signalname signalname;
};


#endif /* SIGNALS_H_ */
