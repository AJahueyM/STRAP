#include "Toggle.h"


bool Toggle::getState()const{
	return state;
}

void Toggle::setState(bool state){
	this->state = state;
}
