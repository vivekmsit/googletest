#pragma once

typedef struct {
	int a;
	bool flag;
} testStruct;


class testClass {
public:
	testClass(int a):local(a){}
	virtual ~testClass(){}
	void setValue(int a) { local = a;}
	int getValue() { return local; }
private:
	int local;
};
