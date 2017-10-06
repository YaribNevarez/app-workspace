/*
 * joystick.hpp
 *
 *  Created on: Sep 19, 2017
 *      Author: Yarib Nevárez <yarib_007@hotmail.com>
 */

#ifndef JOYSTICK_HPP_
#define JOYSTICK_HPP_
#include <string>

class Joystick
{
public:
	Joystick(const char *);
	virtual ~Joystick(void);

	bool open_device(void);
	bool is_open(void);
	void close_device(void);

	std::string get_name(void);
	unsigned get_number_of_axis(void);
	unsigned get_number_of_buttons(void);
	int get_axis_value(int);
	int get_button_value(int);

protected:
	void update_info(void);
	void poll_events(void);

	std::string	file_name;
	int   file_descriptor;

	std::string joystick_name;
	int   number_of_axis;
	int   number_of_buttons;
	int * axis;
	int * buttons;
};


#endif /* JOYSTICK_HPP_ */
