#ifndef __ZUNO_DEFINES___
#define __ZUNO_DEFINES___

#define ZUNO_CORES_SW_VERSION_MAJOR 		2
#define ZUNO_CORES_SW_VERSION_MINOR 		08


#define ZUNO_PIN_STATE_HIGH 				1
#define ZUNO_PIN_STATE_LOW 	 				0
#define ZUNO_SWITCHED_ON 					0xFF
#define ZUNO_SWITCHED_OFF 					0

#define HIGH 								ZUNO_PIN_STATE_HIGH
#define LOW 								ZUNO_PIN_STATE_LOW

#define A0 									0
#define A1 									1
#define A2 									2
#define A3 									3

#define PWM1 									0
#define PWM2 									1
#define PWM3 									2
#define PWM4 									3

#define CTRL_GROUP_1 							1
#define CTRL_GROUP_2 							2
#define CTRL_GROUP_3 							3
#define CTRL_GROUP_4 							4
#define CTRL_GROUP_5 							5


#define ZUNO_STACK_SIZE 		50
#define ZUNO_STACK_ADDRESS 		9001  //must be more the 0x2000 (XDATA_UPPER)
#define ZUNO_STACK_TOP_ADDRESS 	9000  //must be more the 0x2000 (XDATA_UPPER)
#define ZUNO_DELAY_SAFE_STACK_ADDRESS 	(ZUNO_STACK_SIZE + ZUNO_STACK_ADDRESS + 1)  //must be more the 0x2000 (XDATA_UPPER)
#define ZUNO_DELAY_USER_STACK_DELTA_ADDRESS 		(ZUNO_DELAY_SAFE_STACK_ADDRESS + 1)

#define ZUNO_DELAY_USER_STACK_POINTER_ADDRESS 		0x6E
#define ZUNO_CHANNEL_SETUP_ARRAY_ADDRESS 			(0x8020)

#define ZUNO_PIN_MODE_OUTPUT 				0
#define ZUNO_PIN_MODE_INPUT  				1
#define ZUNO_PIN_MODE_INPUT_WITH_PULLUP  	2
#define OUTPUT 								ZUNO_PIN_MODE_OUTPUT
#define INPUT 								ZUNO_PIN_MODE_INPUT
#define INPUT_PULLUP 						ZUNO_PIN_MODE_INPUT_WITH_PULLUP
#define LED_BUILTIN 						13
#define NULL 								0


#define DEBUG_ON 								1
#define DEBUG_OFF 								0

#define MAX(A,B)  (A > B ? A : B)
#define MIN(A,B)  (A < B ? A : B)

	
enum {
	ZUNO_FUNC_PIN_MODE,
	ZUNO_FUNC_DIGITAL_WRITE,
	ZUNO_FUNC_DIGITAL_READ,
	ZUNO_FUNC_ANALOG_READ,
	ZUNO_FUNC_ANALOG_WRITE,
	ZUNO_FUNC_UNSOLICITED_REPORT,
	ZUNO_FUNC_ASSOCIATION_SEND,
	ZUNO_FUNC_DELAY_MS,
	ZUNO_FUNC_SERIAL_USB_BEGIN,
	ZUNO_FUNC_SERIAL_USB_END,
	ZUNO_FUNC_SERIAL_USB_AVAILABLE,
	ZUNO_FUNC_SERIAL_USB_READ,
	ZUNO_FUNC_SERIAL_USB_WRITE,
	ZUNO_FUNC_SERIAL1_BEGIN,
	ZUNO_FUNC_SERIAL1_END,
	ZUNO_FUNC_SERIAL1_AVAILABLE,
	ZUNO_FUNC_SERIAL1_READ,
	ZUNO_FUNC_SERIAL1_WRITE,
	ZUNO_FUNC_SERIAL0_BEGIN,
	ZUNO_FUNC_SERIAL0_END,
	ZUNO_FUNC_SERIAL0_AVAILABLE,
	ZUNO_FUNC_SERIAL0_READ,
	ZUNO_FUNC_SERIAL0_WRITE,
	ZUNO_FUNC_GO_SLEEP,
	ZUNO_FUNC_GET_WAKE_UP_REASON,
	ZUNO_FUNC_MILLIS,
	ZUNO_FUNC_SPI0_INIT,
	ZUNO_FUNC_SPI0_ENABLE,
	ZUNO_FUNC_SPI0_TRANSFER,
	ZUNO_FUNC_EEPROM_READ,
	ZUNO_FUNC_EEPROM_WRITE,
	ZUNO_FUNC_NZRAM_READ,
	ZUNO_FUNC_NZRAM_WRITE,
	ZUNO_FUNC_KS_WU_SETUP,
	ZUNO_FUNC_IR_SETUP,
	ZUNO_FUNC_IR_LEARN_RESET,
	ZUNO_FUNC_IR_IO,
	ZUNO_FUNC_IR_STATUS,
	ZUNO_FUNC_RADIO_POLL,
	ZUNO_FUNC_SETUP_FWUPGRADE,

	ZUNO_FUNC_TEST = 0xFE
};
enum 
{
	ZUNO_CFG_BYTE_ADC_RES,
	ZUNO_CFG_BYTE_ADC_REF,
	ZUNO_CFG_BYTE_ADC_ADV,
	ZUNO_CFG_BYTE_PWM_RES

};

enum {
	ZUNO_SENSOR_BINARY_GETTER,
	ZUNO_SENSOR_MULTILEVEL_GETTER,
	ZUNO_SWITCH_BINARY_GETTER,
	ZUNO_SWITCH_BINARY_SETTER,
	ZUNO_SWITCH_MULTILEVEL_GETTER,
	ZUNO_SWITCH_MULTILEVEL_SETTER,
	ZUNO_METER_GETTER,
};

enum {
	ZUNO_JUMP_TABLE_SETUP, 			//0
	ZUNO_JUMP_TABLE_LOOP, 			//1
	ZUNO_JUMP_TABLE_CALLBACK,		//2
	ZUNO_GET_CHANNELS_ADDRESS, 		//3
	ZUNO_GET_ASSOCIATIONS_ADDRESS,  //4
	ZUNO_GET_SLEEPING_MODE, 		//5
	ZUNO_GET_DEBUG_MODE_PARAM, 		//6
};

enum {
	ZUNO_SWITCH_BINARY_CHANNEL_NUMBER = 1, 			//0x01
	ZUNO_SWITCH_MULTILEVEL_CHANNEL_NUMBER, 			//0x02
	ZUNO_SENSOR_BINARY_CHANNEL_NUMBER, 				//0x03
	ZUNO_SENSOR_MULTILEVEL_CHANNEL_NUMBER, 			//0x04
	ZUNO_METER_CHANNEL_NUMBER, 						//0x05
	
	ZUNO_END_OF_SUPPORTED_CC_NUM,
};

enum
{
	ZUNO_FWUPGRADE_AUTHRADIO_LOCKED = 0,
	ZUNO_FWUPGRADE_AUTHRADIO_ANY	= 0xFFFFFFFF

};

enum
{
	ZUNO_ISR_INT0,
	ZUNO_ISR_INT1,
	ZUNO_ISR_ZEROX,
	ZUNO_ISR_GPTIMER,
	ZUNO_ISR_10MSTIMER,

	ZUNO_ISR_MAX  = 0x08	
};


#define ZUNO_EXT_INT0 	0
#define ZUNO_EXT_INT1 	1
#define ZUNO_EXT_ZEROX 	2


#define ZUNO_EXT_TRIGGER_DISABLED 		0
#define ZUNO_EXT_TRIGGER_FALLING_EDGE 	1
#define ZUNO_EXT_TRIGGER_RISING_EDGE 	2
#define ZUNO_EXT_TRIGGER_LOW_LEVEL		3
#define ZUNO_EXT_TRIGGER_HIGH_LEVEL		4



#define ZUNO_ISR_TABLE_ADDR 0x8020

#define ZUNO_SETUP_ISR_INT0(FUNCTION_NAME)   	__code __at (ZUNO_ISR_TABLE_ADDR) 		ZUNO_ISR_DESCRIPTION ISR_VEC_INT0 =  { 0x02, FUNCTION_NAME}
#define ZUNO_SETUP_ISR_INT0_DEFAULT()   	 	__code __at (ZUNO_ISR_TABLE_ADDR) 		ZUNO_ISR_DESCRIPTION ISR_VEC_INT0 =  { 0x22, 0x0000}
#define ZUNO_SETUP_ISR_INT1(FUNCTION_NAME)   	__code __at (ZUNO_ISR_TABLE_ADDR + 3) 	ZUNO_ISR_DESCRIPTION ISR_VEC_INT1 =  { 0x02, FUNCTION_NAME}
#define ZUNO_SETUP_ISR_INT1_DEFAULT()   	 	__code __at (ZUNO_ISR_TABLE_ADDR + 3) 	ZUNO_ISR_DESCRIPTION ISR_VEC_INT1 =  { 0x22, 0x0000}
#define ZUNO_SETUP_ISR_ZEROX(FUNCTION_NAME)  	__code __at (ZUNO_ISR_TABLE_ADDR + 6) 	ZUNO_ISR_DESCRIPTION ISR_VEC_ZERX =  { 0x02, FUNCTION_NAME}
#define ZUNO_SETUP_ISR_ZEROX_DEFAULT()   	 	__code __at (ZUNO_ISR_TABLE_ADDR + 6) 	ZUNO_ISR_DESCRIPTION ISR_VEC_ZERX =  { 0x22, 0x0000}
#define ZUNO_SETUP_ISR_GPTIMER(FUNCTION_NAME)  	__code __at (ZUNO_ISR_TABLE_ADDR + 9) 	ZUNO_ISR_DESCRIPTION ISR_VEC_GPTM =  { 0x02, FUNCTION_NAME}
#define ZUNO_SETUP_ISR_GPTIMER_DEFAULT()   	 	__code __at (ZUNO_ISR_TABLE_ADDR + 9) 	ZUNO_ISR_DESCRIPTION ISR_VEC_GPTM =  { 0x22, 0x0000}
#define ZUNO_SETUP_ISR_10MSTIMER(FUNCTION_NAME) __code __at (ZUNO_ISR_TABLE_ADDR + 12) 	ZUNO_ISR_DESCRIPTION ISR_VEC_10TM =  { 0x02, FUNCTION_NAME}
#define ZUNO_SETUP_ISR_10MSTIMER_DEFAULT()   	__code __at (ZUNO_ISR_TABLE_ADDR + 12) 	ZUNO_ISR_DESCRIPTION ISR_VEC_10TM =  { 0x22, 0x0000}


//Sensor Binary types
#define ZUNO_SENSOR_BINARY_TYPE_GENERAL_PURPOSE 		0x01
#define ZUNO_SENSOR_BINARY_TYPE_SMOKE 					0x02
#define ZUNO_SENSOR_BINARY_TYPE_CO 						0x03
#define ZUNO_SENSOR_BINARY_TYPE_CO2 					0x04
#define ZUNO_SENSOR_BINARY_TYPE_HEAT 					0x05
#define ZUNO_SENSOR_BINARY_TYPE_WATER 					0x06
#define ZUNO_SENSOR_BINARY_TYPE_FREEZE 					0x07
#define ZUNO_SENSOR_BINARY_TYPE_TAMPER 					0x08
#define ZUNO_SENSOR_BINARY_TYPE_AUX 					0x09
#define ZUNO_SENSOR_BINARY_TYPE_DOOR_WINDOW 			0x0a
#define ZUNO_SENSOR_BINARY_TYPE_TILT 					0x0b
#define ZUNO_SENSOR_BINARY_TYPE_MOTION 					0x0c
#define ZUNO_SENSOR_BINARY_TYPE_GLASSBREAK 				0x0d

// Meter
#define ZUNO_METER_TYPE_ELECTRIC	                    0x01
#define ZUNO_METER_TYPE_GAS		                        0x02
#define ZUNO_METER_TYPE_WATER		                    0x03

#define ZUNO_METER_RESETABLE		                    0x80


#define ZUNO_METER_ELECTRIC_SCALE_KWH	                 0x00
#define ZUNO_METER_ELECTRIC_SCALE_KVAH		             0x01
#define ZUNO_METER_ELECTRIC_SCALE_WATTS		             0x02
#define ZUNO_METER_ELECTRIC_SCALE_PULSECOUNT		     0x03
#define ZUNO_METER_ELECTRIC_SCALE_VOLTS		     		 0x04
#define ZUNO_METER_ELECTRIC_SCALE_AMPS		     		 0x05
#define ZUNO_METER_ELECTRIC_SCALE_POWERFACTOR		     0x06
#define ZUNO_METER_ELECTRIC_SCALE_MST		  			 0x07

#define ZUNO_METER_GAS_SCALE_METERS3	                 0x00
#define ZUNO_METER_GAS_SCALE_FEET3		             	 0x01
#define ZUNO_METER_GAS_SCALE_PULSECOUNT		    		 0x03

#define ZUNO_METER_WATER_SCALE_METERS3	                 0x00
#define ZUNO_METER_WATER_SCALE_FEET3		             0x01
#define ZUNO_METER_WATER_SCALE_GALLONS		             0x02
#define ZUNO_METER_WATER_SCALE_PULSECOUNT		    	 0x03
#define ZUNO_METER_WATER_SCALE_MST		    	 		 0x07

//Sensor Multilevel scales,sizes,precisions
#define METER_PRECISION_ZERO_DECIMALS 					0x00
#define METER_PRECISION_ONE_DECIMAL 					0x01
#define METER_PRECISION_TWO_DECIMALS 					0x02
#define METER_PRECISION_THREE_DECIMALS 					0x03

#define METER_RESET_ENABLE 												0x01
#define METER_RESET_DISABLE 												0x00


#define METER_SIZE_ONE_BYTE 											0x01
#define METER_SIZE_TWO_BYTES 											0x02
#define METER_SIZE_FOUR_BYTES 											0x04

#define METER_PROPERTIES_COMBINER(SCALE,SIZE,PRECISION) \
			(((SIZE-1) & 0x03) << 6)| \
			((SCALE & 0x07)) | \
			((PRECISION & 0x07) << 3)

#define METER_EMPTY_RESETTER							
#define ZUNO_METER(TYPE, RESETABLE,  SCALE, SIZE, PRECISION, GETTER, RESETTER) 		{ZUNO_METER_CHANNEL_NUMBER, TYPE | ((RESETABLE&0x01) << 7), METER_PROPERTIES_COMBINER(SCALE, SIZE, PRECISION), GETTER, RESETTER}






// Sensor Multilevel types
#define ZUNO_SENSOR_MULTILEVEL_TYPE_TEMPERATURE		                                   	0x01
#define ZUNO_SENSOR_MULTILEVEL_TYPE_GENERAL_PURPOSE_VALUE		                        0x02
#define ZUNO_SENSOR_MULTILEVEL_TYPE_LUMINANCE		                                    0x03
#define ZUNO_SENSOR_MULTILEVEL_TYPE_POWER		                                        0x04
#define ZUNO_SENSOR_MULTILEVEL_TYPE_RELATIVE_HUMIDITY		                            0x05
#define ZUNO_SENSOR_MULTILEVEL_TYPE_VELOCITY		                                    0x06
#define ZUNO_SENSOR_MULTILEVEL_TYPE_DIRECTION		                                    0x07
#define ZUNO_SENSOR_MULTILEVEL_TYPE_ATMOSPHERIC_PRESSURE		                        0x08
#define ZUNO_SENSOR_MULTILEVEL_TYPE_BAROMETRIC_PRESSURE		                           	0x09
#define ZUNO_SENSOR_MULTILEVEL_TYPE_SOLAR_RADIATION		                               	0x0A
#define ZUNO_SENSOR_MULTILEVEL_TYPE_DEW_POINT		                                    0x0B
#define ZUNO_SENSOR_MULTILEVEL_TYPE_RAIN_RATE		                                    0x0C
#define ZUNO_SENSOR_MULTILEVEL_TYPE_TIDE_LEVEL		                                    0x0D
#define ZUNO_SENSOR_MULTILEVEL_TYPE_WEIGHT		                                        0x0E
#define ZUNO_SENSOR_MULTILEVEL_TYPE_VOLTAGE		                                       	0x0F
#define ZUNO_SENSOR_MULTILEVEL_TYPE_CURRENT		                                       	0x10
#define ZUNO_SENSOR_MULTILEVEL_TYPE_CO2_LEVEL		                                    0x11
#define ZUNO_SENSOR_MULTILEVEL_TYPE_AIR_FLOW		                                    0x12
#define ZUNO_SENSOR_MULTILEVEL_TYPE_TANK_CAPACITY		                                0x13
#define ZUNO_SENSOR_MULTILEVEL_TYPE_DISTANCE		                                    0x14
#define ZUNO_SENSOR_MULTILEVEL_TYPE_ANGLE_POSITION		                                0x15
#define ZUNO_SENSOR_MULTILEVEL_TYPE_ROTATION                                            0x16
#define ZUNO_SENSOR_MULTILEVEL_TYPE_WATER_TEMPERATURE                                   0x17
#define ZUNO_SENSOR_MULTILEVEL_TYPE_SOIL_TEMPERATURE                                    0x18
#define ZUNO_SENSOR_MULTILEVEL_TYPE_SEISMIC_INTENSITY                                   0x19
#define ZUNO_SENSOR_MULTILEVEL_TYPE_SEISMIC_MAGNITUDE                                   0x1A
#define ZUNO_SENSOR_MULTILEVEL_TYPE_ULTRAVIOLET                                         0x1B
#define ZUNO_SENSOR_MULTILEVEL_TYPE_ELECTRICAL_RESISTIVITY                              0x1C
#define ZUNO_SENSOR_MULTILEVEL_TYPE_ELECTRICAL_CONDUCTIVITY                             0x1D
#define ZUNO_SENSOR_MULTILEVEL_TYPE_LOUDNESS                                            0x1E
#define ZUNO_SENSOR_MULTILEVEL_TYPE_MOISTURE                                            0x1F
#define ZUNO_SENSOR_MULTILEVEL_TYPE_FREQUENCY                                           0x20
#define ZUNO_SENSOR_MULTILEVEL_TYPE_TIME                                                0x21


//Sensor Multilevel scales,sizes,precisions
#define SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS 									0x00
#define SENSOR_MULTILEVEL_PRECISION_ONE_DECIMAL 									0x01
#define SENSOR_MULTILEVEL_PRECISION_TWO_DECIMALS 									0x02

#define SENSOR_MULTILEVEL_SIZE_ONE_BYTE 											0x01
#define SENSOR_MULTILEVEL_SIZE_TWO_BYTES 											0x02
#define SENSOR_MULTILEVEL_SIZE_FOUR_BYTES 											0x04

// Air temperature
#define SENSOR_MULTILEVEL_SCALE_CELSIUS 											0x00 

//General purpose
#define SENSOR_MULTILEVEL_SCALE_PERCENTAGE_VALUE									0x00 

//Luminance
#define SENSOR_MULTILEVEL_SCALE_LUX													0x01

//Power
#define SENSOR_MULTILEVEL_SCALE_WATT												0x00
#define SENSOR_MULTILEVEL_SCALE_BTU_PER_HOUR										0x01

//Humidity
#define SENSOR_MULTILEVEL_SCALE_PERCENTAGE_VALUE									0x00 


//Moisture
#define SENSOR_MULTILEVEL_SCALE_PERCENTAGE_VALUE									0x00

//Velocity
#define SENSOR_MULTILEVEL_SCALE_METERS_PER_SECOND	 								0x00

//Athmospheric pressure
#define SENSOR_MULTILEVEL_SCALE_KILO_PASCAL 										0x00

//Barometric pressure
#define SENSOR_MULTILEVEL_SCALE_KILOPASCAL										0x00

//Solar radiation
#define SENSOR_MULTILEVEL_SCALE_WAVELENGTH_PER_SQUARE_METER								0x00

//Dew point
#define SENSOR_MULTILEVEL_SCALE_CELSIUS											0x00

//Rain rate
#define SENSOR_MULTILEVEL_SCALE_MILLIMETERS_PER_HOUR									0x00

//Tide level
#define SENSOR_MULTILEVEL_SCALE_METER											0x00

//Weight
#define SENSOR_MULTILEVEL_SCALE_KILOGRAM										0x00

//Voltage
#define SENSOR_MULTILEVEL_SCALE_VOLT											0x00

//Current
#define SENSOR_MULTILEVEL_SCALE_AMPERE											0x00

//CO2 level
#define SENSOR_MULTILEVEL_SCALE_PARTS_PER_MILLION										0x00

//Air flow
#define SENSOR_MULTILEVEL_SCALE_CUBIC_METER_PER_HOUR									0x00

//Tank capacity
#define SENSOR_MULTILEVEL_SCALE_LITER											0x00

//Distance
#define SENSOR_MULTILEVEL_SCALE_METER											0x00

//Angle position
#define SENSOR_MULTILEVEL_SCALE_PERCENTAGE_VALUE								0x00

//Rotation
#define SENSOR_MULTILEVEL_SCALE_REVOLUTION_PER_MINUTE  							0x00

//Water temperature
#define SENSOR_MULTILEVEL_SCALE_CELSIUS											0x00

//Soil temperature
#define SENSOR_MULTILEVEL_SCALE_CELSIUS											0x00

//Seismic intensity 
#define SENSOR_MULTILEVEL_SCALE_MERCALLI										0x00

//Seismic magnitude 
#define SENSOR_MULTILEVEL_SCALE_LOCAL											0x00

//Ultraviolet
#define SENSOR_MULTILEVEL_SCALE_ULTRAVIOLET_INDEX								0x00

//Electrical conductivity 
#define SENSOR_MULTILEVEL_SCALE_SIEMENS_PER_METER								0x00

//Electrical resistivity 
#define SENSOR_MULTILEVEL_SCALE_OHM_METER										0x00

//Loudness
#define SENSOR_MULTILEVEL_SCALE_DECIBELS										0x00

//Frequency
#define SENSOR_MULTILEVEL_SCALE_HERTZ											0x00

//Time
#define SENSOR_MULTILEVEL_SCALE_SECOND											0x00

//Target temperature
#define SENSOR_MULTILEVEL_SCALE_CELSIUS											0x00

//Sensor Multilevel Properties
#define SENSOR_MULTILEVEL_PROPERTIES_SIZE_MASK                                      0x07
#define SENSOR_MULTILEVEL_PROPERTIES_SCALE_SHIFT                                    0x03
#define SENSOR_MULTILEVEL_PROPERTIES_SCALE_MASK                                     0x18
#define SENSOR_MULTILEVEL_PROPERTIES_PRECISION_SHIFT                                0x05
#define SENSOR_MULTILEVEL_PROPERTIES_PRECISION_MASK                                 0xE0
#define SENSOR_MULTILEVEL_PROPERTIES_COMBINER(SCALE,SIZE,PRECISION) \
			(SIZE & SENSOR_MULTILEVEL_PROPERTIES_SIZE_MASK) | \
			((SCALE << SENSOR_MULTILEVEL_PROPERTIES_SCALE_SHIFT) & SENSOR_MULTILEVEL_PROPERTIES_SCALE_MASK) | \
			((PRECISION << SENSOR_MULTILEVEL_PROPERTIES_PRECISION_SHIFT) & SENSOR_MULTILEVEL_PROPERTIES_PRECISION_MASK)

#define MACRO_CAST_POINTER_TO_VOID(FUNCTION) 										((VOID_FUNC_POINTER_VOID) FUNCTION)

// Sensor Binary also has a Notification CC, binded to it
#define ZUNO_NOTIFICATION_TURNED_ON 												0xFF

//
#define ZUNO_NO_CHANNEL 													{0, 0, 0, 0, 0}
#define ZUNO_SWITCH_BINARY(GETTER, SETTER)   								{ZUNO_SWITCH_BINARY_CHANNEL_NUMBER, 0, 0, GETTER, SETTER}
#define ZUNO_SWITCH_MULTILEVEL(GETTER, SETTER) 								{ZUNO_SWITCH_MULTILEVEL_CHANNEL_NUMBER, 0, 0, GETTER, SETTER}
#define ZUNO_SENSOR_BINARY(TYPE, GETTER) 									{ZUNO_SENSOR_BINARY_CHANNEL_NUMBER, TYPE, ZUNO_NOTIFICATION_TURNED_ON, GETTER, MACRO_CAST_POINTER_TO_VOID(0)}
#define ZUNO_SENSOR_MULTILEVEL(TYPE, SCALE, SIZE, PRECISION, GETTER) 		{ZUNO_SENSOR_MULTILEVEL_CHANNEL_NUMBER, TYPE, SENSOR_MULTILEVEL_PROPERTIES_COMBINER(SCALE, SIZE, PRECISION), GETTER, MACRO_CAST_POINTER_TO_VOID(0)}


#define ZUNO_SENSOR_BINARY_GENERAL_PURPOSE(GETTER)							ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_GENERAL_PURPOSE, GETTER)
#define ZUNO_SENSOR_BINARY_SMOKE(GETTER)									ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_SMOKE, GETTER)
#define ZUNO_SENSOR_BINARY_CO(GETTER)										ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_CO, GETTER)
#define ZUNO_SENSOR_BINARY_CO2(GETTER)										ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_CO2, GETTER)
#define ZUNO_SENSOR_BINARY_HEAT(GETTER)										ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_HEAT, GETTER)
#define ZUNO_SENSOR_BINARY_WATER(GETTER)									ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_WATER, GETTER)
#define ZUNO_SENSOR_BINARY_FREEZE(GETTER)									ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_FREEZE, GETTER)
#define ZUNO_SENSOR_BINARY_TAMPER(GETTER)									ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_TAMPER, GETTER)
#define ZUNO_SENSOR_BINARY_AUX(GETTER)										ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_AUX, GETTER)
#define ZUNO_SENSOR_BINARY_DOOR_WINDOW(GETTER)								ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_DOOR_WINDOW, GETTER)
#define ZUNO_SENSOR_BINARY_TILT(GETTER)										ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_TILT, GETTER)
#define ZUNO_SENSOR_BINARY_MOTION(GETTER)									ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_MOTION, GETTER)
#define ZUNO_SENSOR_BINARY_GLASSBREAK(GETTER)								ZUNO_SENSOR_BINARY(ZUNO_SENSOR_BINARY_TYPE_GLASSBREAK, GETTER)


#define ZUNO_SENSOR_MULTILEVEL_TEMPERATURE(GETTER) 							ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_TEMPERATURE, SENSOR_MULTILEVEL_SCALE_CELSIUS, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)	
#define ZUNO_SENSOR_MULTILEVEL_GENERAL_PURPOSE(GETTER) 						ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_GENERAL_PURPOSE_VALUE, SENSOR_MULTILEVEL_SCALE_PERCENTAGE_VALUE, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_LUMINANCE(GETTER) 							ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_LUMINANCE, SENSOR_MULTILEVEL_SCALE_LUX, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_POWER(GETTER) 								ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_POWER, SENSOR_MULTILEVEL_SCALE_WATT, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_HUMIDITY(GETTER) 							ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_RELATIVE_HUMIDITY, SENSOR_MULTILEVEL_SCALE_PERCENTAGE_VALUE, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_VELOCITY(GETTER)								ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_VELOCITY, SENSOR_MULTILEVEL_SCALE_METERS_PER_SECOND, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
//#define ZUNO_SENSOR_MULTILEVEL_DIRECTION(GETTER)
#define ZUNO_SENSOR_MULTILEVEL_ATHMOSPHERIC_PRESSURE(GETTER)				ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_ATMOSPHERIC_PRESSURE, SENSOR_MULTILEVEL_SCALE_KILO_PASCAL, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_BAROMETRIC_PRESSURE(GETTER)					ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_BAROMETRIC_PRESSURE, SENSOR_MULTILEVEL_SCALE_KILO_PASCAL, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_SOLAR_RADIATION(GETTER)						ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_SOLAR_RADIATION, SENSOR_MULTILEVEL_SCALE_WAVELENGTH_PER_SQUARE_METER, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_DEW_POINT(GETTER)							ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_DEW_POINT, SENSOR_MULTILEVEL_SCALE_CELSIUS, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_RAIN_RATE(GETTER)							ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_RAIN_RATE, SENSOR_MULTILEVEL_SCALE_MILLIMETERS_PER_HOUR, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_TIDE_LEVEL(GETTER)							ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_TIDE_LEVEL, SENSOR_MULTILEVEL_SCALE_METER, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_WEIGHT(GETTER)								ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_WEIGHT, SENSOR_MULTILEVEL_SCALE_KILOGRAM, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_VOLTAGE(GETTER)								ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_VOLTAGE, SENSOR_MULTILEVEL_SCALE_VOLT, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_CURRENT(GETTER)								ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_CURRENT, SENSOR_MULTILEVEL_SCALE_AMPERE, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_CO2_LEVEL(GETTER)							ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_CO2_LEVEL, SENSOR_MULTILEVEL_SCALE_PARTS_PER_MILLION, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_AIR_FLOW(GETTER)								ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_AIR_FLOW, SENSOR_MULTILEVEL_SCALE_CUBIC_METER_PER_HOUR, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_TANK_CAPACITY(GETTER)						ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_TANK_CAPACITY, SENSOR_MULTILEVEL_SCALE_LITER, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_DISTANCE(GETTER)								ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_DISTANCE, SENSOR_MULTILEVEL_SCALE_METER, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_MOISTURE(GETTER)								ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_MOISTURE, SENSOR_MULTILEVEL_SCALE_PERCENTAGE_VALUE, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_ANGLE_POSITION(GETTER)						ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_ANGLE_POSITION, SENSOR_MULTILEVEL_SCALE_PERCENTAGE_VALUE, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_ROTATION(GETTER)								ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_ROTATION, SENSOR_MULTILEVEL_SCALE_REVOLUTION_PER_MINUTE, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_WATER_TEMPERATURE(GETTER)					ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_WATER_TEMPERATURE, SENSOR_MULTILEVEL_SCALE_CELSIUS, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_SOIL_TEMPERATURE(GETTER)						ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_SOIL_TEMPERATURE, SENSOR_MULTILEVEL_SCALE_CELSIUS, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_SEISMIC_INTENSITY(GETTER)					ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_SEISMIC_INTENSITY, SENSOR_MULTILEVEL_SCALE_MERCALLI, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_SEISMIC_MAGNITUDE(GETTER)					ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_SEISMIC_MAGNITUDE, SENSOR_MULTILEVEL_SCALE_LOCAL, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_ULTRAVIOLET(GETTER)							ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_ULTRAVIOLET, SENSOR_MULTILEVEL_SCALE_ULTRAVIOLET_INDEX, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_ELECTRICAL_RESISTIVITY(GETTER)				ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_ELECTRICAL_RESISTIVITY, SENSOR_MULTILEVEL_SCALE_OHM_METER, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_LOUDNESS(GETTER)						ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_LOUDNESS, SENSOR_MULTILEVEL_SCALE_DECIBELS, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_ZERO_DECIMALS, GETTER))
#define ZUNO_SENSOR_MULTILEVEL_ELECTRICAL_CONDUCTIVITY(GETTER)				ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_ELECTRICAL_CONDUCTIVITY, SENSOR_MULTILEVEL_SCALE_SIEMENS_PER_METER, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_FREQUENCY(GETTER)							ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_FREQUENCY, SENSOR_MULTILEVEL_SCALE_HERTZ, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_TIME(GETTER)									ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_TIME, SENSOR_MULTILEVEL_SCALE_SECOND, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)
#define ZUNO_SENSOR_MULTILEVEL_TARGET_TEMPERATURE(GETTER)					ZUNO_SENSOR_MULTILEVEL(ZUNO_SENSOR_MULTILEVEL_TYPE_TARGET_TEMPERATURE, SENSOR_MULTILEVEL_SCALE_CELSIUS, SENSOR_MULTILEVEL_SIZE_ONE_BYTE, SENSOR_MULTILEVEL_PRECISION_ZERO_DECIMALS, GETTER)

// Additional Macroses

//#define XBYTE  _xdata BYTE /* External data byte */





// Associations
// -----------------------------------------------------------------
enum {
	ZUNO_ASSOC_BASIC_SET_NUMBER = 1, 						//0x01
	ZUNO_ASSOC_BASIC_SET_AND_DIM_NUMBER,				//0x02
	ZUNO_ASSOC_SCENE_ACTIVATION_NUMBER, 				//0x03
	ZUNO_ASSOC_DOORLOCK_CONTROL_NUMBER,
	ZUNO_END_OF_SUPPORTED_ASSOC_NUM

};

#define ZUNO_ASSOC_NO_PARAMS 							0x00

#define ZUNO_NO_ASSOCIATIONS							{0, 0}
#define ZUNO_ASSOCIATION_GROUP_SET_VALUE 				{ZUNO_ASSOC_BASIC_SET_NUMBER, ZUNO_ASSOC_NO_PARAMS}
#define ZUNO_ASSOCIATION_GROUP_SET_VALUE_AND_DIM 		{ZUNO_ASSOC_BASIC_SET_AND_DIM_NUMBER, ZUNO_ASSOC_NO_PARAMS}
#define ZUNO_ASSOCIATION_GROUP_SCENE_CONTROL 			{ZUNO_ASSOC_SCENE_ACTIVATION_NUMBER, ZUNO_ASSOC_NO_PARAMS}
#define ZUNO_ASSOCIATION_GROUP_DOORLOCK					{ZUNO_ASSOC_DOORLOCK_CONTROL_NUMBER, ZUNO_ASSOC_NO_PARAMS}

//TODO #define ZUNO_ASSOCIATION_GROUP_COLOR_CONTROL 		 		{}
//TODO #define ZUNO_ASSOCIATION_GROUP_THERMOSTAT_CONTROL 		 	{}
//TODO #define ZUNO_ASSOCIATION_GROUP_DOOR_LOCK_CONTROL 		 	{}

#define ZUNO_SETUP_ASSOCIATIONS(...)	\
								__code ZUNO_ASSOCIATION_PROPERTIES_DESCRIPTION zunoAssociationSetupArray[]= \
								{ \
									{0x42, 0x42}, \
									__VA_ARGS__, \
									{0x43, 0x43} \
								}

// -----------------------------------------------------------------

// Sleeping Mode
// -----------------------------------------------------------------

enum {
	ZUNO_MODE_ALWAYS_LISTENING_NUMBER,				//0
	ZUNO_MODE_WAKE_UP_NUMBER,						//1
	ZUNO_MODE_FLIRS_NUMBER,							//2
};

#define ZUNO_SLEEPING_MODE_ALWAYS_AWAKE 			{ZUNO_MODE_ALWAYS_LISTENING_NUMBER, 0, 0}
#define ZUNO_SLEEPING_MODE_SLEEPING			 		{ZUNO_MODE_WAKE_UP_NUMBER, 0, 0}
#define ZUNO_SLEEPING_MODE_FREQUENTLY_AWAKE 		{ZUNO_MODE_FLIRS_NUMBER, 0, 0}
#define ZUNO_SETUP_SLEEPING_MODE(VALUE) 		\
								__code ZUNO_SLEEPING_MODE_PROPERTIES_DESCRIPTION zunoSleepingModeSetupStruct = VALUE

// -----------------------------------------------------------------

				

#define ZUNO_SETUP_DEBUG_MODE(VALUE) 		\
								__code BYTE zunoDebugParameter = VALUE


#define ZUNO_MAX_MULTI_CHANNEL_NUMBER 					10

#define ZUNO_REPORT_NO_IMMEDIATE_VALUE 		0xffff
#define zunoSendReport(CHANNEL)  			zunoSendUncolicitedReport(CHANNEL,ZUNO_REPORT_NO_IMMEDIATE_VALUE)

#define ZUNO_DIMMING_UP				0
#define ZUNO_DIMMING_DOWN 			1
#define ZUNO_DIMMING_START			1
#define ZUNO_DIMMING_STOP 			0

#define zunoSendToGroupSetValueCommand(GROUP,VALUE) 					zunoSendAssociationCommand(GROUP,ZUNO_ASSOC_BASIC_SET_NUMBER,VALUE,0)
#define zunoSendToGroupDimmingCommand(GROUP,DIRECTION,START_STOP) 		zunoSendAssociationCommand(GROUP,ZUNO_ASSOC_BASIC_SET_AND_DIM_NUMBER,DIRECTION,START_STOP)
#define zunoSendToGroupScene(GROUP,SCENE_NUMBER) 						zunoSendAssociationCommand(GROUP,ZUNO_ASSOC_SCENE_ACTIVATION_NUMBER,SCENE_NUMBER,0)
#define zunoSendToGroupDoorlockControl(GROUP,OPEN_CLOSE) 				zunoSendAssociationCommand(GROUP,ZUNO_ASSOC_DOORLOCK_CONTROL_NUMBER,OPEN_CLOSE,0)



// SPI
// -----------------------------------------------------------------
#define SPI_SPEED_8_MHZ   0x00
#define SPI_SPEED_4_MHZ   0x01
#define SPI_SPEED_2_MHZ   0x02
#define SPI_SPEED_1_MHZ   0x03

#define SPI_MODE0       0x00
#define SPI_MODE1       0x01
#define SPI_MODE2       0x02
#define SPI_MODE3       0x03

#define MSBFIRST     0x01
#define LSBFIRST     0x00
// -----------------------------------------------------------------


// Для совместимости с библиотеками Arduino используем определение частоты процессора
#define F_CPU			  16000000
// Версия Arduino
#define ARDUINO 		    152	
#define DEG_TO_RAD 			0.017453292519
#define RAD_TO_DEG 			57.29577951308
#define EULER 				2.718281828459

#define min(a,b) 				((a)<(b)?(a):(b))
#define max(a,b) 				((a)>(b)?(a):(b))
#define abs(x) 					((x)>0?(x):-(x))
#define constrain(amt,low,high) ((amt)<(low)?(low):((amt)>(high)?(high):(amt)))
#define round(x)     			((x)>=0?(long)((x)+0.5):(long)((x)-0.5))
#define radians(deg) 			((deg)*DEG_TO_RAD)
#define degrees(rad) 			((rad)*RAD_TO_DEG)
#define sq(x) 					((x)*(x))
 
// Битовые операции
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
#define _BV(bit) (1 << (bit))


#define lowByte(w) ((uint8_t) ((w) & 0xff))
#define highByte(w) ((uint8_t) ((w) >> 8))
								
#define _NOP()  NOPS(1)


#define CHANGE 1
#define FALLING 2
#define RISING 3

// ADC REF
// set it up via  analogReference()
// ZUno specific
#define ADC_HIGH_EXTERNAL	0x00  // Use pin A0 as external High reference source						
#define ADC_HIGH_INTERNAL	0x01  // Use built-in 1.2V source as Hight reference 							
#define ADC_HIGH_VCC		0x02  // Use VCC as High reference
#define ADC_LOW_EXTERNAL	0x00  // Use pin A1 as external Low reference source							
#define ADC_LOW_GND			0x04  // Use GND as Low reference							
// Arduino-like								
#define DEFAULT 	(ADC_HIGH_VCC | ADC_LOW_GND) 		// VCC for High reference and GND for Low reference 
#define INTERNAL 	(ADC_HIGH_INTERNAL | ADC_LOW_GND)  	// 1.2V internal reference source for Hight reference and GND for Low Reference
#define EXTERNAL 	(ADC_HIGH_EXTERNAL | ADC_LOW_GND) 	// pin A0 for High reference, GND for Low reference

// Advanced ADC options
// set it up via  zunoADCAdvConfig()								
#define ZUNO_ADC_ADV_BUFFERED 0x01
#define ZUNO_ADC_ADV_AZP128   0x00
#define ZUNO_ADC_ADV_AZP256   0x40
#define ZUNO_ADC_ADV_AZP512   0x80
#define ZUNO_ADC_ADV_AZP1024  0xC0

// GPT constants

#define ZUNO_GPT_SCALE1024    0x04
#define ZUNO_GPT_IMWRITE	  0x40	
#define ZUNO_GPT_CYCLIC		  0x08	








#endif // #define __ZUNO_DEFINES___
