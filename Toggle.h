#pragma once
class Toggle
{

private:
	bool state;
public:
	virtual void enable() = 0;
	virtual double minPulseRateMs() const = 0;
	virtual void enablePulse(double rate) = 0;
	virtual void disable() = 0;
	virtual bool getState() const;
	virtual void setState(bool state);
};

