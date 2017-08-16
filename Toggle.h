#pragma once
class Toggle
{

private:
	bool state;
public:
	virtual void enable() = 0;
	virtual void disable() = 0;
	bool getState();
	void setState(bool state);
};

