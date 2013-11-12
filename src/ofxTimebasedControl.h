#pragma once

//
//  ofxTimebasedControl.h
//  life_2013
//
//  Created by FURUDATE Ken on 10/11/13.
//
//

#include "ofMain.h"

class ofxTimebasedControl{
public:
	float current, target, duration;
	ofEvent<void> timelineDone;
	ofxTimebasedControl(float defaultVal = 0);
	void start(float target_, float duration_);
	void stop();

	void set(float val);
	float get();
	bool isRunning();
	
private:
	void update(ofEventArgs &e);

	unsigned long startTime;
	float currentOriginal;
	bool bRunning;
};