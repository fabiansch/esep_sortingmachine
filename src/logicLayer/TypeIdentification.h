/*
 * TypeIdentification.h
 *
 *  Created on: 15.11.2017
 *      Author: abx724
 */

#ifndef TYPEIDENTIFICATION_H_
#define TYPEIDENTIFICATION_H_

#include "SignalReceiver.h"


namespace hardwareLayer{
	class HardwareLayer;
}

enum class ProfileState {EDGE, SPACE, CENTER, FINAL};
enum class Profile {HOLED, FLAT, NORMAL};

struct ItemType{
	Profile profile = Profile::FLAT;
	bool metal = false;
	int code = -1;
	bool inDetection = true;
	float height_cb_1 = 0;
	float height_cb_2 = 0;
};

namespace logicLayer {


class TypeIdentification: public SignalReceiver {
public:
	TypeIdentification(hardwareLayer::HardwareLayer*);
	virtual ~TypeIdentification();
	void operator()();
	static Profile heightMapping( int );

	static ItemType* createScan();
	static vector<ItemType> typeScans;

	/**
	 *  @brief allowed tolerance
	 */
	static int delta;

	/**
	 *  @brief reference value that holds expected height value of valid item
	 *  !!!needs to be set via calibration - value of each cb differs very strong
	 */
	static int normalLevel;

	/**
	 * @brief ground level
	 */
	static int groundLevel;

	/**
	 * @brief measure cycle
	 */
	static void measureProfil(bool*, hardwareLayer::HardwareLayer*);

	/**
	 *
	 */
	static int mapToBinary(int);

	/**
	 *	@brief shows if typeId is in measurement or not
	 *	default false
	 */
	static float mmPerUnit;

	/**
	 *	@brief
	 */
	static float holeLevel;

	static void setUnitToMm();
	static void setHoleLevel();

	/**
	 * @brief convert sensor units to mm
	 */
	static float toMm( int );

private:
	hardwareLayer::HardwareLayer* hal_;




	/**
	 *	@brief shows if typeId is in measurement or not
	 *	default false
	 */
	bool inMeasurement;
};

} /* namespace logicLayer */
#endif /* TYPEIDENTIFICATION_H_ */
