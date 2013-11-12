//
//  ofxTimebasedControl.cpp
//  life_2013_refact
//
//  Created by FURUDATE Ken on 10/27/13.
//
//

#include "ofxTimebasedControl.h"

ofxTimebasedControl::ofxTimebasedControl(float defaultVal){
	current = target = defaultVal;
	duration = startTime = 0;
	bRunning = false;
};

void ofxTimebasedControl::start(float target_, float duration_){
	
	stop();
	currentOriginal = current;
	target = target_;
	duration = duration_;
	startTime = ofGetElapsedTimeMillis();
	
	if(duration < 0){
		duration = 0;
		current = target;
		bRunning = false;
	}else{
		bRunning = true;
		ofAddListener(ofEvents().update, this, &ofxTimebasedControl::update);
	}
};
void ofxTimebasedControl::stop(){
	bRunning = false;
	ofRemoveListener(ofEvents().update, this, &ofxTimebasedControl::update);
};
void ofxTimebasedControl::update(ofEventArgs &e){
	// update current value;
	float pct = (ofGetElapsedTimeMillis()-startTime)/duration;
	if(pct >= 1){
		ofLogVerbose() << "time line reached... notify it";
		// current arrived to target
		current = target;
		stop();
		ofNotifyEvent(timelineDone, this);
	}else{
		current = currentOriginal + (target-currentOriginal)*pct;
	}
};

void ofxTimebasedControl::set(float val){
	stop();
	current = val;
};
float ofxTimebasedControl::get(){
	return current;
};
bool ofxTimebasedControl::isRunning(){
	return bRunning;
};
