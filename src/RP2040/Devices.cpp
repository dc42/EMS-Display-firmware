/*
 * Devices.cpp
 *
 *  Created on: 28 Jul 2020
 *      Author: David
 */

#include "Devices.h"

#if RP2040

#include <AnalogIn.h>
#include <AnalogOut.h>
#include <TaskPriorities.h>
#include <RTOSIface/RTOSIface.h>
#include <RP2040USB.h>
#include <SerialCDC.h>

// Analog input support
constexpr size_t AnalogInTaskStackWords = 300;
static Task<AnalogInTaskStackWords> analogInTask;

constexpr size_t UsbDeviceTaskStackWords = 200;
static Task<UsbDeviceTaskStackWords> usbDeviceTask;

SerialCDC serialUSB(NoPin, 512, 512);

void DeviceInit() noexcept
{
#if 0
	AnalogIn::Init(DmacChanAdcRx, DmacPrioAdcRx);
	AnalogOut::Init();
	analogInTask.Create(AnalogIn::TaskLoop, "AIN", nullptr, TaskPriority::AinPriority);
#endif

	__USBStart();
	usbDeviceTask.Create(UsbDeviceTask, "USBD", nullptr, TaskPriority::UsbPriority);
}

#endif

// End