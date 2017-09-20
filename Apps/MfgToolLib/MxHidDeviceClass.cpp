/*
 * Copyright 2009-2013, Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice, this
 * list of conditions and the following disclaimer in the documentation and/or
 * other materials provided with the distribution.
 *
 * Neither the name of the Freescale Semiconductor nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include "stdafx.h"
#include <Assert.h>
#include <cfgmgr32.h>
#include <basetyps.h>
#include <setupapi.h>
#include <initguid.h>
extern "C" {
#include <hidsdi.h>
}
#include <hidclass.h>
#include "DeviceClass.h"
#include "MxHidDevice.h"
#include "MxHidDeviceClass.h"
#include "MfgToolLib_Export.h"
#include "MfgToolLib.h"

MxHidDeviceClass::MxHidDeviceClass(INSTANCE_HANDLE handle)
: DeviceClass(&GUID_DEVINTERFACE_HID, &GUID_DEVCLASS_HIDCLASS, _T("MXHID"), DeviceTypeMxHid, handle)
{
	LogMsg(LOG_MODULE_MFGTOOL_LIB, LOG_LEVEL_FATAL_ERROR, _T("new MxHidDeviceClass"));
}

MxHidDeviceClass::~MxHidDeviceClass(void)
{
	LogMsg(LOG_MODULE_MFGTOOL_LIB, LOG_LEVEL_FATAL_ERROR, _T("delete MxHidDeviceClass"));
}

Device* MxHidDeviceClass::CreateDevice(DeviceClass* deviceClass, SP_DEVINFO_DATA deviceInfoData, CString path)
{
    //Check if the path matches our device pid&vid.
    //An example of value of path: "\\?\hid#vid_413c&pid_2011&mi_01&col02#8&2598dfbd&0&0001#{4d1e55b2-f16f-11cf-88cb-001111000030}"

    //add filiters
	OP_STATE_ARRAY *pOpStates = GetOpStates((MFGLIB_VARS *)m_pLibHandle);
	CString filter;
	BOOL isRightDevice = FALSE;
	OP_STATE_ARRAY::iterator it = pOpStates->begin();
	COpState *pCurrentState = NULL;
	CString msg = path;
	for(; it!=pOpStates->end(); it++)
	{
        if (((*it)->opState) != MX_BOOTSTRAP)
        {
            continue;
        }
		filter.Format(_T("vid_%04x&pid_%04x"), (*it)->uiVid, (*it)->uiPid);
		//path.MakeUpper();
		msg.MakeUpper();
		filter.MakeUpper();
		if( msg.Find(filter) != -1 )
		{	//find
			isRightDevice = TRUE;
			pCurrentState = (*it);
			break;
		}
	}
	if(isRightDevice) //OK, find the device
	{
		return new MxHidDevice(deviceClass, deviceInfoData.DevInst, path, m_pLibHandle);
	}
	else
	{
		return NULL;
	}
}
