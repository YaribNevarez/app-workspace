/*
 * espi.h
 *
 *  Created on: Sep 13, 2017
 *      Author: Yarib Nevárez
 */

#ifndef ESPI_HW_H_
#define ESPI_HW_H_

// Enhanced SPI driver

#define ACCESS_REGISTER(base, index)		(*((volatile uint32_t *)((base)+4*(index))))
#define REGISTER_GET(reg, mask, shift)		(((mask) & (reg)) >> (shift))
#define REGISTER_SET(reg, mask, shift, val)	((reg) = (~mask & (reg)) | ((mask) & ((val)<<(shift))))


#define SPI_BASEADDR					XPAR_ESPI_0_0 //_AXI_BASEADDR !!

#define SPI_CONTROL_REGISTER_INDEX		0
#define SPI_CONTROL_REGISTER			ACCESS_REGISTER(SPI_BASEADDR, SPI_CONTROL_REGISTER_INDEX)
#define SPI_DATA_REGISTER_INDEX			1
#define SPI_DATA						ACCESS_REGISTER(SPI_BASEADDR, SPI_DATA_REGISTER_INDEX)

#define SPI_BAUD_RATE_DIVIDER_MASK		0x000000FFu
#define SPI_BAUD_RATE_DIVIDER_SHIFT		0
#define SET_SPI_BAUD_RATE_DIVIDER(val)	REGISTER_SET(SPI_CONTROL_REGISTER,	     \
													 	 SPI_BAUD_RATE_DIVIDER_MASK, \
														 SPI_BAUD_RATE_DIVIDER_SHIFT,\
														 val)
#define GET_SPI_BAUD_RATE_DIVIDER		REGISTER_GET(SPI_CONTROL_REGISTER,	     \
														 SPI_BAUD_RATE_DIVIDER_MASK, \
														 SPI_BAUD_RATE_DIVIDER_SHIFT)


#define SPI_CLOCK_PHASE_MASK			0x00000100u
#define SPI_CLOCK_PHASE_SHIFT			8
#define SET_SPI_CLOCK_PHASE(val)		REGISTER_SET(SPI_CONTROL_REGISTER, \
													 	 SPI_CLOCK_PHASE_MASK, \
														 SPI_CLOCK_PHASE_SHIFT,\
														 val)
#define GET_SPI_CLOCK_PHASE				REGISTER_GET(SPI_CONTROL_REGISTER, \
														 SPI_CLOCK_PHASE_MASK, \
														 SPI_CLOCK_PHASE_SHIFT)


#define SPI_CLOCK_POLARITY_MASK			0x00000200u
#define SPI_CLOCK_POLARITY_SHIFT		9
#define SET_SPI_CLOCK_POLARITY(val)		REGISTER_SET(SPI_CONTROL_REGISTER,	  \
													 	 SPI_CLOCK_POLARITY_MASK, \
														 SPI_CLOCK_POLARITY_SHIFT,\
														 val)
#define GET_SPI_CLOCK_POLARITY			REGISTER_GET(SPI_CONTROL_REGISTER,	  \
														 SPI_CLOCK_POLARITY_MASK, \
														 SPI_CLOCK_POLARITY_SHIFT)

#define SPI_DATA_LENGTH_8_BITS          0
#define SPI_DATA_LENGTH_16_BITS         1
#define SPI_DATA_LENGTH_24_BITS         2
#define SPI_DATA_LENGTH_32_BITS         3

#define SPI_DATA_LENGTH_MASK			0x00000C00u
#define SPI_DATA_LENGTH_SHIFT			10
#define SET_SPI_DATA_LENGTH(val)		REGISTER_SET(SPI_CONTROL_REGISTER, \
													 	 SPI_DATA_LENGTH_MASK, \
														 SPI_DATA_LENGTH_SHIFT,\
														 val)
#define GET_SPI_DATA_LENGTH				REGISTER_GET(SPI_CONTROL_REGISTER, \
														 SPI_DATA_LENGTH_MASK, \
														 SPI_DATA_LENGTH_SHIFT)


#define SPI_CS_FORCE_MASK				    0x00001000u
#define SPI_CS_FORCE_SHIFT				    12
#define SET_SPI_CS_FORCE(val)			    REGISTER_SET(SPI_CONTROL_REGISTER, \
													 	 SPI_CS_FORCE_MASK,        \
														 SPI_CS_FORCE_SHIFT,       \
														 val)
#define GET_SPI_CS_FORCE				    REGISTER_GET(SPI_CONTROL_REGISTER, \
														 SPI_CS_FORCE_MASK,        \
														 SPI_CS_FORCE_SHIFT)


#define SPI_SETTLE_TIME_MASK			0x00006000u
#define SPI_SETTLE_TIME_SHIFT			13
#define SET_SPI_SETTLE_TIME(val)		REGISTER_SET(SPI_CONTROL_REGISTER, \
													 	 SPI_SETTLE_TIME_MASK, \
														 SPI_SETTLE_TIME_SHIFT,\
														 val)
#define GET_SPI_SETTLE_TIME				REGISTER_GET(SPI_CONTROL_REGISTER, \
														 SPI_SETTLE_TIME_MASK, \
														 SPI_SETTLE_TIME_SHIFT)


#define SPI_TRANSMISSION_DONE_MASK			0x00008000u
#define SPI_TRANSMISSION_DONE_SHIFT			15
#define GET_SPI_TRANSMISSION_DONE			REGISTER_GET(SPI_CONTROL_REGISTER,   \
														 SPI_TRANSMISSION_DONE_MASK, \
														 SPI_TRANSMISSION_DONE_SHIFT)


#define SPI_SLAVE_SELECT_MASK			0x00030000u
#define SPI_SLAVE_SELECT_SHIFT			16
#define SET_SPI_SLAVE_SELECT(val)		REGISTER_SET(SPI_CONTROL_REGISTER, \
													 	 SPI_SLAVE_SELECT_MASK, \
														 SPI_SLAVE_SELECT_SHIFT,\
														 val)
#define GET_SPI_SLAVE_SELECT				REGISTER_GET(SPI_CONTROL_REGISTER, \
														 SPI_SLAVE_SELECT_MASK, \
														 SPI_SLAVE_SELECT_SHIFT)


#endif /* ESPI_H_ */
