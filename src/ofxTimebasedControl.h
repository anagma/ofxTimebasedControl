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

	ofEvent<void> timelineDone;
	ofxTimebasedControl(float defaultVal = 0);
	~ofxTimebasedControl();
	void start(float target_, float duration_);
	void stop();

	void set(float val);
	float get();
	
	bool isRunning();
	
	void pause();
	void resume();
	bool isPaused();
	
private:
	void update(ofEventArgs &e);

	float current, target, duration;

	unsigned long startTime;
	float currentOriginal;
	bool bRunning;
	bool bPaused;
	float pausedRestDuration;
};