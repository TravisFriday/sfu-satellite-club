#include <Arduino.h>    //assuming inclusion of string.h
#include "Module.h"
#include <SFE_BMP180.h>
#include <Wire.h>

//on Due, attach SDA to 20, SCL to 21 

class Barometer: public Module { 
	SFE_BMP180 *baromImpl;
        double temperature, pressure;

	char toWrite[200];             //max buffer size may have to change depending on data

public:
	Barometer();
	void begin();
	void tick();
	int enable();
	void disable();

	const char* dataToPersist();
	const char* getModuleName();

        float getPressure();
};
