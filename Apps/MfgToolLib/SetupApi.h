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

#pragma once

#include "stdafx.h"
#include <setupapi.h>
#include <cfgmgr32.h>
#include <initguid.h>
#include <devguid.h>
#include <usbiodef.h>

class SetupApi
{
	typedef BOOL (WINAPI *PSetupDiClassGuidsFromNameA)(
			_In_ PCSTR ClassName,
			_Out_writes_to_(ClassGuidListSize, *RequiredSize) LPGUID ClassGuidList,
			_In_ DWORD ClassGuidListSize,
			_Out_ PDWORD RequiredSize);

	typedef BOOL (WINAPI *PSetupDiClassGuidsFromNameW)(
			_In_ PCWSTR ClassName,
			_Out_writes_to_(ClassGuidListSize, *RequiredSize) LPGUID ClassGuidList,
			_In_ DWORD ClassGuidListSize,
			_Out_ PDWORD RequiredSize);

    typedef DWORD (WINAPI *PCM_Get_DevNode_Registry_PropertyA)(
             DEVINST     dnDevInst,
             ULONG       ulProperty,
             PULONG      pulRegDataType,
             PVOID       Buffer,
             PULONG  pulLength,
             ULONG       ulFlags);

    typedef DWORD (WINAPI *PCM_Get_DevNode_Registry_PropertyW)(
             DEVINST     dnDevInst,
             ULONG       ulProperty,
             PULONG      pulRegDataType,
             PVOID       Buffer,
             PULONG  pulLength,
             ULONG       ulFlags);

    typedef HDEVINFO (WINAPI *PSetupDiCreateDeviceInfoList)(
        CONST GUID *ClassGuid,
        HWND        hwndParent);

    typedef DWORD (WINAPI *PCM_Open_DevNode_Key)(
        DEVINST        dnDevNode,
        REGSAM         samDesired,
        ULONG          ulHardwareProfile,
        REGDISPOSITION Disposition,
        PHKEY          phkDevice,
        ULONG          ulFlags);

    typedef DWORD (WINAPI *PCM_Request_Device_EjectA)(
        DEVINST dnDevInst,
        PPNP_VETO_TYPE pVetoType,
        LPSTR pszVetoName,
        ULONG ulNameLength,
        ULONG ulFlags);

    typedef DWORD (WINAPI *PCM_Request_Device_EjectW)(
        DEVINST dnDevInst,
        PPNP_VETO_TYPE pVetoType,
        LPWSTR pszVetoName,
        ULONG ulNameLength,
        ULONG ulFlags);

    typedef BOOL (WINAPI *PSetupDiOpenDeviceInfoA)(
        HDEVINFO DeviceInfoSet,
        PCSTR DeviceInstanceId,
        HWND hwndParent,
        DWORD OpenFlags,
        PSP_DEVINFO_DATA DeviceInfoData);

    typedef BOOL (WINAPI *PSetupDiOpenDeviceInfoW)(
        HDEVINFO DeviceInfoSet,
        PCWSTR DeviceInstanceId,
        HWND hwndParent,
        DWORD OpenFlags,
        PSP_DEVINFO_DATA DeviceInfoData);

    typedef BOOL (WINAPI *PSetupDiGetDeviceInstanceIdW)(
        HDEVINFO DeviceInfoSet,
        PSP_DEVINFO_DATA DeviceInfoData,
        PWSTR DeviceInstanceId,
        DWORD DeviceInstanceIdSize,
        PDWORD RequiredSize);

    typedef BOOL (WINAPI *PSetupDiGetDeviceInstanceIdA)(
        HDEVINFO DeviceInfoSet,
        PSP_DEVINFO_DATA DeviceInfoData,
        PSTR DeviceInstanceId,
        DWORD DeviceInstanceIdSize,
        PDWORD RequiredSize);

    typedef BOOL(WINAPI *PSetupDiGetDeviceRegistryPropertyW)(
        HDEVINFO DeviceInfoSet,
        PSP_DEVINFO_DATA DeviceInfoData,
        DWORD Property,
        PDWORD PropertyRegDataType,
        PBYTE PropertyBuffer,
        DWORD PropertyBufferSize,
        PDWORD RequiredSize);

    typedef BOOL(WINAPI *PSetupDiGetDeviceRegistryPropertyA)(
        HDEVINFO         DeviceInfoSet,
        PSP_DEVINFO_DATA DeviceInfoData,
        DWORD            Property,
        PDWORD           PropertyRegDataType,
        PBYTE            PropertyBuffer,
        DWORD            PropertyBufferSize,
        PDWORD           RequiredSize);
    
    typedef BOOL(WINAPI *PSetupDiGetDeviceInterfaceDetailW)(
        HDEVINFO  DeviceInfoSet,
        PSP_DEVICE_INTERFACE_DATA  DeviceInterfaceData,
        PSP_DEVICE_INTERFACE_DETAIL_DATA_W  DeviceInterfaceDetailData, 
        DWORD  DeviceInterfaceDetailDataSize,
        PDWORD  RequiredSize, 
        PSP_DEVINFO_DATA  DeviceInfoData);

    typedef BOOL(WINAPI *PSetupDiGetDeviceInterfaceDetailA)(
        HDEVINFO  DeviceInfoSet,
        PSP_DEVICE_INTERFACE_DATA  DeviceInterfaceData,
        PSP_DEVICE_INTERFACE_DETAIL_DATA_A  DeviceInterfaceDetailData, 
        DWORD  DeviceInterfaceDetailDataSize,
        PDWORD  RequiredSize, 
        PSP_DEVINFO_DATA  DeviceInfoData);
    
    typedef BOOL (WINAPI *PSetupDiEnumDeviceInterfaces)(
        HDEVINFO  DeviceInfoSet,
        PSP_DEVINFO_DATA  DeviceInfoData, 
        LPCGUID  InterfaceClassGuid,
        DWORD  MemberIndex,
        PSP_DEVICE_INTERFACE_DATA  DeviceInterfaceData);

    typedef BOOL (WINAPI *PSetupDiEnumDeviceInfo)(
        HDEVINFO  DeviceInfoSet,
        DWORD  MemberIndex,
        PSP_DEVINFO_DATA  DeviceInfoData);

    typedef HDEVINFO (WINAPI *PSetupDiGetClassDevsW)(
        LPCGUID  ClassGuid, 
        PCWSTR  Enumerator, 
        HWND  hwndParent, 
        DWORD  Flags);

    typedef HDEVINFO (WINAPI *PSetupDiGetClassDevsA)(
        LPCGUID  ClassGuid, 
        PCSTR  Enumerator, 
        HWND  hwndParent, 
        DWORD  Flags);
    
    typedef DWORD (WINAPI *PCM_Get_Device_IDA)(
        DEVINST  dnDevInst,
        PCHAR    Buffer,
        ULONG    BufferLen,
        ULONG    ulFlags);

    typedef DWORD (WINAPI *PCM_Get_Device_IDW)(
        DEVINST  dnDevInst,
        PWCHAR   Buffer,
        ULONG    BufferLen,
        ULONG    ulFlags);

    typedef BOOL (WINAPI *PSetupDiDestroyDeviceInfoList)(
        HDEVINFO DeviceInfoSet);

    typedef BOOL (WINAPI *PSetupDiGetClassImageList)(
        PSP_CLASSIMAGELIST_DATA ClassImageListData);

    typedef BOOL (WINAPI *PSetupDiDestroyClassImageList)(
        PSP_CLASSIMAGELIST_DATA  ClassImageListData);

    typedef BOOL (WINAPI *PSetupDiGetClassImageIndex)(
        PSP_CLASSIMAGELIST_DATA  ClassImageListData,
        LPGUID  ClassGuid,
        PINT  ImageIndex);

    typedef BOOL (WINAPI *PSetupDiGetClassDescriptionA)(
        LPGUID  ClassGuid,
        PSTR  ClassDescription,
        DWORD  ClassDescriptionSize,
        PDWORD  RequiredSize);

    typedef BOOL (WINAPI *PSetupDiGetClassDescriptionW)(
        LPGUID  ClassGuid,
        PWSTR  ClassDescription,
        DWORD  ClassDescriptionSize,
        PDWORD  RequiredSize);

    typedef DWORD (WINAPI *PCM_Get_Child)(
        PDEVINST pdnDevInst,
        DEVINST  dnDevInst,
        ULONG    ulFlags );
    
    typedef DWORD (WINAPI *PCM_Get_Sibling)(
        PDEVINST pdnDevInst,
        DEVINST  dnDevInst,
        ULONG    ulFlags );
    
    typedef DWORD (WINAPI *PCM_Get_Parent)(
        PDEVINST pdnDevInst,
        DEVINST  dnDevInst,
        ULONG    ulFlags );
    
    typedef DWORD (WINAPI *PCM_Get_Device_ID_Size)(
        PULONG   pulLen,
        DEVINST  dnDevInst,
        ULONG    ulFlags);

    typedef DWORD (WINAPI *PCM_Get_DevNode_Status)(
        PULONG  pulStatus,
        PULONG  pulProblemNumber,
        DEVINST  dnDevInst,
        ULONG  ulFlags);

    HMODULE hModuleSetup;
    HMODULE hModuleCfgMgr;
    bool available;
    
    PCM_Get_DevNode_Registry_PropertyA CM_Get_DevNode_Registry_PropertyA;
    PSetupDiGetClassDescriptionA SetupDiGetClassDescriptionA;
    PSetupDiOpenDeviceInfoA SetupDiOpenDeviceInfoA;
    PSetupDiGetDeviceRegistryPropertyA SetupDiGetDeviceRegistryPropertyA;
    PSetupDiGetDeviceInterfaceDetailA SetupDiGetDeviceInterfaceDetailA;
    PSetupDiGetClassDevsA SetupDiGetClassDevsA;
    PSetupDiGetDeviceInstanceIdA SetupDiGetDeviceInstanceIdA;
    PCM_Get_Device_IDA CM_Get_Device_IDA;
    PCM_Request_Device_EjectA CM_Request_Device_EjectA;
	PSetupDiClassGuidsFromNameA SetupDiClassGuidsFromNameA;

#if defined(UNICODE)
    PCM_Get_DevNode_Registry_PropertyW CM_Get_DevNode_Registry_PropertyW;
    PSetupDiGetClassDescriptionW SetupDiGetClassDescriptionW;
    PSetupDiOpenDeviceInfoW SetupDiOpenDeviceInfoW;
    PSetupDiGetDeviceRegistryPropertyW SetupDiGetDeviceRegistryPropertyW;
    PSetupDiGetDeviceInterfaceDetailW SetupDiGetDeviceInterfaceDetailW;
    PSetupDiGetClassDevsW SetupDiGetClassDevsW;
    PSetupDiGetDeviceInstanceIdW SetupDiGetDeviceInstanceIdW;
    PCM_Get_Device_IDW CM_Get_Device_IDW;
    PCM_Request_Device_EjectW CM_Request_Device_EjectW;
	PSetupDiClassGuidsFromNameW SetupDiClassGuidsFromNameW;

#endif

public:
    PSetupDiCreateDeviceInfoList SetupDiCreateDeviceInfoList;
    PSetupDiGetClassImageIndex SetupDiGetClassImageIndex;
    PSetupDiGetClassImageList SetupDiGetClassImageList;
    PSetupDiDestroyClassImageList SetupDiDestroyClassImageList;
    PSetupDiEnumDeviceInterfaces SetupDiEnumDeviceInterfaces;
    PSetupDiEnumDeviceInfo SetupDiEnumDeviceInfo;
    PSetupDiDestroyDeviceInfoList SetupDiDestroyDeviceInfoList;
    PCM_Get_Child CM_Get_Child;
    PCM_Get_Sibling CM_Get_Sibling;
    PCM_Get_Parent CM_Get_Parent;
    PCM_Get_Device_ID_Size CM_Get_Device_ID_Size;
    PCM_Get_DevNode_Status CM_Get_DevNode_Status;
    PCM_Open_DevNode_Key CM_Open_DevNode_Key;

	BOOL apiSetupDiClassGuidsFromName(
		_In_ PCWSTR ClassName,
		_Out_writes_to_(ClassGuidListSize, *RequiredSize) LPGUID ClassGuidList,
		_In_ DWORD ClassGuidListSize,
		_Out_ PDWORD RequiredSize);
	
	DWORD apiCM_Get_DevNode_Registry_Property(
        DEVINST dnDevInst,
        ULONG ulProperty,
        PULONG pulRegDataType,
        PVOID Buffer,
        PULONG pulLength,
        ULONG ulFlags);

    BOOL apiSetupDiOpenDeviceInfo(
        HDEVINFO DeviceInfoSet,
        PCTSTR DeviceInstanceId,
        HWND hwndParent,
        DWORD OpenFlags,
        PSP_DEVINFO_DATA DeviceInfoData);

    BOOL apiSetupDiGetDeviceInterfaceDetail(
        HDEVINFO  DeviceInfoSet,
        PSP_DEVICE_INTERFACE_DATA  DeviceInterfaceData,
        PSP_DEVICE_INTERFACE_DETAIL_DATA  DeviceInterfaceDetailData, 
        DWORD  DeviceInterfaceDetailDataSize,
        PDWORD  RequiredSize, 
        PSP_DEVINFO_DATA  DeviceInfoData);

    HDEVINFO apiSetupDiGetClassDevs(
        LPCGUID  ClassGuid, 
        LPCTSTR  Enumerator, 
        HWND  hwndParent, 
        DWORD  Flags);
    
    BOOL apiSetupDiGetDeviceRegistryProperty(    
        HDEVINFO DeviceInfoSet,
        PSP_DEVINFO_DATA DeviceInfoData,
        DWORD Property,
        PDWORD PropertyRegDataType,
        PBYTE PropertyBuffer,
        DWORD PropertyBufferSize,
        PDWORD RequiredSize);

    BOOL apiSetupDiGetDeviceInstanceId(
        HDEVINFO DeviceInfoSet,
        PSP_DEVINFO_DATA DeviceInfoData,
        PTSTR DeviceInstanceId,
        DWORD DeviceInstanceIdSize,
        PDWORD RequiredSize);

    BOOL apiSetupDiGetClassDescription(
        LPGUID  ClassGuid,
        PTSTR  ClassDescription,
        DWORD  ClassDescriptionSize,
        PDWORD  RequiredSize);

    DWORD apiCM_Get_Device_ID(
        DEVINST  dnDevInst,
        CString& deviceInstanceId);

    DWORD apiCM_Request_Device_Eject(
        DEVINST dnDevInst,
        PPNP_VETO_TYPE pVetoType,
        PTSTR pszVetoName,
        ULONG ulNameLength);

    bool IsDevNodeOk( DEVINST dnDevInst );
    CString CR_GetErrorString( DWORD errorCode );
    CString CM_GetProblemString( DWORD problemCode );
    
    bool IsAvailable() const { return available; };
    
    SetupApi();
    ~SetupApi();
};

extern SetupApi& gSetupApi();
