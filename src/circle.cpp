#include "circle.h"

Circle::Circle(int x, int y, int radius, int mass)
{
    this->position.x = x;
    this->position.y = y;

    this->radius = radius;
    this->mass = mass;

    this->velocity.x = ofRandom(-100,100);
    this->velocity.y = ofRandom(-100,100);

    lastEvolve = ofGetElapsedTimeMillis();
}

void Circle::draw() {
    ofDrawCircle(this->position.x,this->position.y,this->radius);
}

bool Circle::wallsCollision(ofVec2f &futurePos){
    bool changes = false;
    if (futurePos.x < this->radius/2 ){
        futurePos.x = this->radius/2;
        this->velocity.x *= -1;
        changes = true;
    }
    if (futurePos.y < this->radius/2){
        futurePos.y = this->radius/2;
        this->velocity.y *= -1;
        changes = true;
    }

    if (futurePos.x > ofGetWidth() - this->radius/2){
        futurePos.x = ofGetWidth() - this->radius/2;
        this->velocity.x *= -1;
        changes = true;
    }

    if (futurePos.y > ofGetHeight() - this->radius/2){
        futurePos.y = ofGetHeight() - this->radius/2;
        this->velocity.y *= -1;
        changes = true;
    }

    return changes;
}

bool Circle::circleCollision(vector<Circle> &other, ofVec2f &futurePos){
   for (Circle c : other){
       if (this->position != c.position)
           if (futurePos.distance(c.position) < this->radius + c.radius){
               this->velocity = ((2*c.getMass()*c.getVelocity())+(this->mass-c.getMass())*this->velocity)/(this->mass+c.mass);

               return true;
           }
   }

   return false;
}

void Circle::update(vector<Circle> &other) {
    ofVec2f futurePos = this->position + this->velocity * (ofGetElapsedTimeMillis() - lastEvolve)/1000;

    this->wallsCollision(futurePos);

    if (!this->circleCollision(other,futurePos)){
        this->position = futurePos;
    }

    lastEvolve = ofGetElapsedTimeMillis();
}
