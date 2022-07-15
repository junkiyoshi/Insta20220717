#include "ofApp.h"	
//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(255);
	ofSetColor(0);
	ofNoFill();
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);
	ofRotateY(90);

	float radius = 200;

	vector<glm::vec3> vertices_1;
	vector<glm::vec3> vertices_2;

	for (int z = -500; z <= 500; z += 10) {

		auto deg = (z + 500) + ofGetFrameNum();

		auto location_1 = glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), z);
		auto location_2 = glm::vec3(radius * cos((deg + 180) * DEG_TO_RAD), radius * sin((deg + 180) * DEG_TO_RAD), z);

		vertices_1.push_back(location_1);
		vertices_2.push_back(location_2);

		ofDrawLine(location_1, location_2);
		ofDrawSphere(location_1, 2);
		ofDrawSphere(location_2, 2);
	}

	ofBeginShape();
	ofVertices(vertices_1);
	ofEndShape();

	ofBeginShape();
	ofVertices(vertices_2);
	ofEndShape();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}