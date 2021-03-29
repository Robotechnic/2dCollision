#include "ofApp.h"
#define MASSMIN 5
#define MASSMAX 25


//--------------------------------------------------------------
void ofApp::setup(){
    int radius = 45;
    for (int x = radius; x<ofGetWidth()-radius; x+=radius*2)
        for (int y = radius; y<ofGetHeight()-radius;y+=radius*2){
            circles.push_back(Circle(x,y,radius,20));
        }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i<(int)circles.size(); i++){
        circles[i].update(circles);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i<(int)circles.size(); i++){
        ofSetColor(ofMap(circles[i].getMass(),MASSMIN,MASSMAX,0,255),ofMap(circles[i].getMass(),MASSMAX,MASSMIN,0,255),0);
        circles[i].draw();
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    Circle c(x,y,ofRandom(10,30),ofRandom(MASSMIN,MASSMAX));
    ofVec2f pos(x,y);
    if (!c.circleCollision(circles,pos)){
        circles.push_back(c);
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
