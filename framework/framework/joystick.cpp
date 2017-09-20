/*
 * joystick.cpp
 *
 *  Created on: Sep 19, 2017
 *      Author: root
 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <linux/joystick.h>
#include "joystick.hpp"


Joystick::Joystick(const char * file_name):
file_name(file_name),
file_descriptor(-1),
joystick_name(""),
number_of_axis(0),
number_of_buttons(0),
axis(NULL),
buttons(NULL)
{
}

Joystick::~Joystick(void)
{
	close_device();
}

bool Joystick::open_device(void)
{
	if (!is_open())
	{
		file_descriptor = open((const char *)file_name.c_str(), O_RDONLY);
		update_info();
	}
	return is_open();
}

void Joystick::update_info(void)
{
	if (is_open())
	{
		char name[128];
		fcntl(file_descriptor, F_SETFL, O_NONBLOCK);
		ioctl(file_descriptor, JSIOCGNAME(128), &name);
		ioctl(file_descriptor, JSIOCGAXES, &number_of_axis);
		ioctl(file_descriptor, JSIOCGBUTTONS, &number_of_buttons);

		joystick_name = name;

		if (0 < number_of_axis)
		{
			axis = new int[number_of_axis];
			memset(axis, 0x0, sizeof(int) * number_of_axis);
		}

		if (0 < number_of_buttons)
		{
			buttons = new int[number_of_buttons];
			memset(buttons, 0x0, sizeof(int) * number_of_buttons);
		}
	}
}

bool Joystick::is_open(void)
{
	return file_descriptor != -1;
}

void Joystick::close_device(void)
{
	if (is_open())
	{
		close(file_descriptor);
		number_of_axis = 0;
		number_of_buttons = 0;

		if (axis != NULL)
		{
			delete [] axis;
			axis = NULL;
		}

		if (buttons != NULL)
		{
			delete [] buttons;
			buttons = NULL;
		}

		file_descriptor = -1;
	}
}

std::string Joystick::get_name(void)
{
	return joystick_name;
}

unsigned Joystick::get_number_of_axis(void)
{
	return number_of_axis;
}

unsigned Joystick::get_number_of_buttons(void)
{
	return number_of_buttons;
}

void Joystick::poll_events(void)
{
	struct js_event js;
	struct js_event js_diff;

	if (is_open())
	{
		do
		{
			memcpy(&js_diff, &js, sizeof(struct js_event));
			read(file_descriptor, &js, sizeof(struct js_event));

			switch (js.type & ~JS_EVENT_INIT)
			{
				case JS_EVENT_AXIS:
					axis[js.number] = js.value;
					break;
				case JS_EVENT_BUTTON:
					buttons[js.number] = js.value;
					break;
			}
		}
		while (memcmp(&js, & js_diff, sizeof(struct js_event)) != 0);
	}
}

int Joystick::get_axis_value(int a)
{
	int value = 0;
	poll_events();
	if ((a < number_of_axis) && (axis != NULL))
	{
		value = axis[a];
	}
	return value;
}


int Joystick::get_button_value(int b)
{
	int value = 0;
	poll_events();
	if ((b < number_of_buttons) && (buttons != NULL))
	{
		value = buttons[b];
	}
	return value;
}