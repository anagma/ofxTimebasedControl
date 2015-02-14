#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	frameRate = 60;
	
	ofBackground(0, 0, 0);
	ofSetVerticalSync(false);
	ofSetFrameRate(frameRate);
	ofSetLogLevel(OF_LOG_NOTICE);
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofNoFill();
	ofEnableBlendMode(OF_BLENDMODE_ADD);
	
	degreeInFrame = 0;
	
	// initialize timebased control to 0
	degreeInTime.set(0);
	// to 360, in 30 sec
	degreeInTime.start(360, 30000);
	ofAddListener(degreeInTime.timelineDone, this, &ofApp::repeat); // when time is done, repeat it.

}
//--------------------------------------------------------------
void ofApp::repeat(){
	// repeat it
	degreeInTime.set(0);
	degreeInTime.start(360, 30000); // 30 sec
	ofLogNotice() << "timeline done, repeat it";
}
//--------------------------------------------------------------
void ofApp::update(){
	// if the frame rate is 60 strictly, it must be 360 in 30 sec.
	degreeInFrame += 0.2;
	if (degreeInFrame > 360) {
		degreeInFrame -= 360;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	// in frame
	glPushMatrix();
	glTranslated(ofGetWidth()/3, ofGetHeight()/2, 0);
	ofSetColor(255, 128);
	for(int i=0; i<20; i++){
		glRotated(degreeInFrame, 0, 0, 1);
		ofRect(0, 0, (20-i)*10, (20-i)*10);
	}
	glPopMatrix();
	
	// in time
	glPushMatrix();
	glTranslated(ofGetWidth()/3*2, ofGetHeight()/2, 0);
	ofSetColor(255, 128);
	for(int i=0; i<20; i++){
		glRotated(degreeInTime.get(), 0, 0, 1);
		ofRect(0, 0, (20-i)*10, (20-i)*10);
	}
	glPopMatrix();
	
	// status
	ofSetColor(255);
	ofDrawBitmapString("in frame", ofGetWidth()/3-100, ofGetHeight()/4);
	ofDrawBitmapString("in time", ofGetWidth()/3*2-100, ofGetHeight()/4);
	
	ofDrawBitmapString("frame rate: "+ofToString(ofGetFrameRate()), 20, 20);
	ofDrawBitmapString("elapsed time: "+ofToString(ofGetElapsedTimeMillis()), 20, 40);
	ofDrawBitmapString("press left to decrease frame rate, right to increse frame rate", 20, 60);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if(key == OF_KEY_LEFT){
		frameRate-=10;
		if(frameRate < 10){
			frameRate = 10;
		}
		ofSetFrameRate(frameRate);
	}else if(key == OF_KEY_RIGHT){
		frameRate+=10;
		if(frameRate > 60){
			frameRate = 60;
		}
		ofSetFrameRate(frameRate);
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
