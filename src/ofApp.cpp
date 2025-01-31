#include "ofApp.h"
#include <iostream>
#include <vector>

// Declare global variables
std::vector<int> randomNumbers; // Vector to store 5 random numbers
ofTrueTypeFont fontArial; // Font object

#pragma region Custom Functions

// Generate 5 random numbers between 10 and 100
static void generateRandomNumbers() {
	randomNumbers.clear(); // Clear the vector before regenerating
	for (int i = 0; i < 5; i++) {
		randomNumbers.push_back(ofRandom(10, 100));
	}
}

// Bubble sort the random numbers
void bubbleSort(std::vector<int>& arr) {
	for (size_t i = 0; i < arr.size(); i++) {
		for (size_t j = 0; j < arr.size() - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

// Insertion sort the numbers
void insertionSort(std::vector<int>& arr) {
	for (size_t i = 1; i < arr.size(); i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

// Merge sort the numbers
void merge(std::vector<int>& arr, int left, int mid, int right) {
	std::vector<int> temp;
	int i = left;
	int j = mid + 1;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp.push_back(arr[i]);
			i++;
		}
		else {
			temp.push_back(arr[j]);
			j++;
		}
	}
	while (i <= mid) {
		temp.push_back(arr[i]);
		i++;
	}
	while (j <= right) {
		temp.push_back(arr[j]);
		j++;
	}
	for (size_t k = 0; k < temp.size(); k++) {
		arr[left + k] = temp[k];
	}
}

void mergeSort(std::vector<int>& arr, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
}

// Quick sort the numbers
int partition(std::vector<int>& arr, int low, int high) {
	int pivot = arr[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
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
	if (key == 'r') { // Random number generation
		generateRandomNumbers();
	}
	if (key == 'b') { // Bubble sort
		bubbleSort(randomNumbers);
	}
	if (key == 'i') { // Insertion sort
		insertionSort(randomNumbers);
	}
	if (key == 'm') { // Merge sort
		mergeSort(randomNumbers, 0, randomNumbers.size() - 1);
	}
	if (key == 'q') { // Quick sort
		quickSort(randomNumbers, 0, randomNumbers.size() - 1);
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
