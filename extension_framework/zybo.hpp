/*
 * zybo.hpp
 *
 *  Created on: Aug 31, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef ZYBO_HPP_
#define ZYBO_HPP_

#include "m_device.hpp"

namespace ZYBO_PLATFORM
{
	namespace DRIVER
	{
		const char * const PWM0    = "/proc/pwm_0";
		const char * const PWM1    = "/proc/pwm_1";
		const char * const CTRL    = "/proc/controller";
		const char * const ADC     = "/proc/adc";
		const char * const ZYBO    = "/proc/zybo";
		const char * const SERIAL0 = "/dev/ttyPS1";
	}

	namespace HANDLER
	{
		DeviceHandler PWM0(DRIVER::PWM0);
		DeviceHandler PWM1(DRIVER::PWM1);
		DeviceHandler CONTROLLER(DRIVER::CTRL);
		DeviceHandler ADC(DRIVER::ADC);
		DeviceHandler ZYBO(DRIVER::ZYBO);
		DeviceHandler SERIAL0(DRIVER::SERIAL0);
	}
}

#endif /* ZYBO_HPP_ */
