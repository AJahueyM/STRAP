#pragma once
class Toggle
{

private:
	bool state;
public:
	Toggle();
	virtual ~Toggle();
	virtual void enable() = 0;
	virtual void disable() = 0;
	virtual bool getState();
	virtual void setState(bool state);
};

