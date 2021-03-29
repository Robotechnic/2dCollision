#ifndef CIRCLE_H
#define CIRCLE_H

#include <ofGraphics.h>
#include <ofMath.h>
#include <ofVec2f.h>
#include <ofUtils.h>
#include <ofAppRunner.h>
#include <vector>

using namespace std;

class Circle
{
public:
    Circle(int x, int y, int radius,int mass);

    bool wallsCollision(ofVec2f &futurePos);
    bool circleCollision(vector<Circle> &other, ofVec2f &futurePos);

    void draw();
    void update(vector<Circle> &other);

    int getMass(){return this->mass;};
    ofVec2f getVelocity(){return this->velocity;};

    void setVelocity(ofVec2f velocity){this->velocity = velocity;};
private:
    ofVec2f position, velocity;
    int radius, mass;
    float lastEvolve;
};

#endif // CIRCLE_H
