#ifndef H_INVERSE
#define H_INVERSE

#define PI 3.14159265359
#define HALF_PI 1.5707963268
#define DOUBLE_PI 6.28318530718
#define DEGREE_STEP 0.01745329251

#define FREE_ANGLE 999.9

class Link {
public:
	Link();
	
	void init(float length, float angle_low_limit, float angle_high_limit);
	
	bool inRange(float angle);
	float getLength();
	float getAngle();
	void setAngle(float angle);
	
private:
	float _length;
	float _angleLow;
	float _angleHigh;
	float _angle;
};

class _Inverse {
public:
	_Inverse();
	
	void attach(Link shoulder, Link upperarm, Link forearm, Link hand);
	
	bool solve(float x, float y, float z, float& base, float& shoulder, float& elbow, float& wrist, float phi = FREE_ANGLE);
	
private:
	Link _L0; // Link 0: Shoulder
	Link _L1; // Link 1: Upperarm
	Link _L2; // Link 2: Forearm
	Link _L3; // Link 3: Hand
	
	float _currentPhi;
	
	bool _cosrule(float opposite, float adjacent1, float adjacent2, float& angle);
	
	bool _solve(float x, float y, float phi, float& shoulder, float& elbow, float& wrist);
	
	bool _solve(float x, float y, float& shoulder, float& elbow, float& wrist);
};

extern _Inverse InverseK;

#endif //H_INVERSE