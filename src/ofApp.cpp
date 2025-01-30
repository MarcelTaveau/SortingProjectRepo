#include "ofApp.h"
#include <iostream>
#include <vector>

// Declare global variables
std::vector<int> randomNumbers; // Vector to store 5 random numbers
ofTrueTypeFont fontArial; // Font object

#pragma region Custom Functions

// Generate 5 random numbers between 10 and 100
static void generateRandomNumbers() {
	for (int i = 0; i < 5; i++) {
		randomNumbers.push_back(ofRandom(10, 100));
	}
}

// Bubble sort the random numbers
void bubbleSort() {

}

// Draw 5 circles with random numbers
static void drawCirclesWithText() {
	for (int i = 0; i < 5; i++) {
		std::string text = std::to_string(randomNumbers[i]);
		int fontSize = randomNumbers[i];
		fontArial.load("arial", fontSize);
		ofRectangle bounds = fontArial.getStringBoundingBox(text, 0, 0);

		int boundsWidth = bounds.getWidth();
		int boundsHeight = bounds.getHeight();
		int centerX = 100 + i * 200;
		int centerY = 200;

		// Circles
		ofSetColor(50, 200, 50);
		ofDrawCircle(centerX, centerY, randomNumbers[i]);

		// Text
		ofSetColor(255, 255, 255);
		fontArial.drawString(text, centerX - boundsWidth / 2, centerY + boundsHeight / 2);
	}
}

#pragma endregion

//--------------------------------------------------------------
void ofApp::setup() {
	generateRandomNumbers();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	drawCirclesWithText();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'r') {
		generateRandomNumbers();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
