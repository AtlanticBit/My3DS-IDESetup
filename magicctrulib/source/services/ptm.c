#include <stdlib.h>
#include <3ds/types.h>
#include <3ds/svc.h>
#include <3ds/srv.h>
#include <3ds/services/ptm.h>


static Handle ptmHandle;

Result ptmInit()
{
	return srvGetServiceHandle(&ptmHandle, "ptm:u");	
}

Result ptmExit()
{
	return svcCloseHandle(ptmHandle);
}

Result PTMU_GetShellState(Handle* servhandle, u8 *out)
{
	if(!servhandle)servhandle=&ptmHandle;
	Result ret=0;
	u32 *cmdbuf = getThreadCommandBuffer();

	cmdbuf[0] = 0x00060000;

	if((ret = svcSendSyncRequest(*servhandle))!=0)return ret;

	*out = (u8)cmdbuf[2];

	return (Result)cmdbuf[1];
}

Result PTMU_GetBatteryLevel(Handle* servhandle, u8 *out)
{
	if(!servhandle)servhandle=&ptmHandle;
	Result ret=0;
	u32 *cmdbuf = getThreadCommandBuffer();

	cmdbuf[0] = 0x00070000;

	if((ret = svcSendSyncRequest(*servhandle))!=0)return ret;

	*out = (u8)cmdbuf[2];

	return (Result)cmdbuf[1];
}

Result PTMU_GetBatteryChargeState(Handle* servhandle, u8 *out)
{
	if(!servhandle)servhandle=&ptmHandle;
	Result ret=0;
	u32 *cmdbuf = getThreadCommandBuffer();

	cmdbuf[0] = 0x00080000;

	if((ret = svcSendSyncRequest(*servhandle))!=0)return ret;

	*out = (u8)cmdbuf[2];

	return (Result)cmdbuf[1];
}

Result PTMU_GetPedometerState(Handle* servhandle, u8 *out)
{
	if(!servhandle)servhandle=&ptmHandle;
	Result ret=0;
	u32 *cmdbuf = getThreadCommandBuffer();

	cmdbuf[0] = 0x00090000;

	if((ret = svcSendSyncRequest(*servhandle))!=0)return ret;

	*out = (u8)cmdbuf[2];

	return (Result)cmdbuf[1];
}

Result PTMU_GetTotalStepCount(Handle* servhandle, u32 *steps)
{
	if(!servhandle)servhandle=&ptmHandle;
	Result ret=0;
	u32 *cmdbuf = getThreadCommandBuffer();

	cmdbuf[0] = 0x000C0000;

	if((ret = svcSendSyncRequest(*servhandle))!=0)return ret;

	*steps = cmdbuf[2];

	return (Result)cmdbuf[1];
}
