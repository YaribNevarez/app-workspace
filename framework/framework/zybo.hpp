/*
 * zybo.hpp
 *
 *  Created on: Aug 31, 2017
 *      Author: Yarib Nevárez (yarib_007@hotmail.com) - root
 */

#ifndef ZYBO_HPP_
#define ZYBO_HPP_


#include "devicehandler.hpp"

namespace ZYBO
{
	namespace DRIVER
	{
//		const char * const BTN  = "/proc/zynq_btn";
//		const char * const LED  = "/proc/zynq_led";
//		const char * const SW   = "/proc/zynq_sw";
		const char * const CTRL = "/proc/controller";
		const char * const ADC = "/proc/adc";
	}

	namespace HANDLER
	{
//		DeviceHandler BUTTONS(DRIVER::BTN);
//		DeviceHandler LEDS(DRIVER::LED);
//		DeviceHandler SWITCHES(DRIVER::SW);
		DeviceHandler CTRL(DRIVER::CTRL);
		DeviceHandler ADC(DRIVER::ADC);
	}
}

#endif /* ZYBO_HPP_ */
