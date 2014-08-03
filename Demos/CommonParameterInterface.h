
#ifndef PARAM_INTERFACE_H
#define PARAM_INTERFACE_H

#pragma once

typedef void (*SliderParamChangedCallback) (float newVal);
#include "LinearMath/btScalar.h"

struct SliderParams
{
	const char* m_name;
	float m_minVal;
	float m_maxVal;
	SliderParamChangedCallback m_callback;
	btScalar* m_paramValuePointer;
	void* m_userPointer;
	bool m_clampToNotches;

	SliderParams(const char* name, btScalar* targetValuePointer)
	:m_name(name),
	m_minVal(-100),
	m_maxVal(100),
	m_callback(0),
	m_paramValuePointer(targetValuePointer),
	m_userPointer(0),
	m_clampToNotches(false)
	{
	}

};


struct CommonParameterInterface
{
	virtual void registerSliderFloatParameter(SliderParams& params)=0;
	virtual void syncParameters()=0;
	virtual void removeAllParameters()=0;
};
	
#endif //PARAM_INTERFACE_H