/*
 * DigitalIoPin.h
 *
 *  Created on: 31.1.2016
 *      Author: krl
 */

#ifndef DIGITALIOPIN_H_
#define DIGITALIOPIN_H_

class DigitalIoPin {
public:
	enum pinMode {
		output,
		input,
		pullup,
		pulldown
	};
	DigitalIoPin(int port, int pin, pinMode mode, bool invert = false);
	virtual ~DigitalIoPin();
	virtual bool read();
	void write(bool value);
	static void GPIO_interrupt_init();
	void enable_interrupt(const int& pin_irq_index, int priority, int port, int pin);
private:
	int port;
	int pin;
	bool inv;
};

#endif /* DIGITALIOPIN_H_ */
