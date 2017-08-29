/*
 * perftool.hpp
 *
 *  Created on: Aug 27, 2017
 *      Author: root
 */

#ifndef PERFTOOL_HPP_
#define PERFTOOL_HPP_

#include "ctrlapp/src/systembox.hpp"

class PerformanceTool: protected SystemFeature
{
public:
	PerformanceTool();
	~PerformanceTool();

	virtual int run(void);

protected:

	virtual int server(void);
};



#endif /* PERFTOOL_HPP_ */
