/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2013              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   TimerManagerWrapper
*   Author      :   ������
*   Create      :   2013-5-21 22:22
*   LastChange  :   2013-5-21 22:22
*   History     :	
*
*   Description :   BOLT�����timermanager��C++��װ
*
********************************************************************/ 
#ifndef __TIMERMANAGERWRAPPER_H__
#define __TIMERMANAGERWRAPPER_H__

#include <XLUE.h>

namespace Xunlei
{
namespace Bolt
{

class TimerManagerWrapper
{
public:
	TimerManagerWrapper()
	{}

	virtual ~TimerManagerWrapper()
	{}
	
	unsigned long SetTimer(unsigned int elapse)
	{
		return XLUE_SetTimer(&OnTimerCallBack, elapse, this);
	}

	unsigned long SetOnceTimer(unsigned int elapse)
	{
		return XLUE_SetOnceTimer(&OnTimerCallBack, elapse, this);
	}

	unsigned long SetIDTimer(unsigned int timerID, unsigned int elapse)
	{
		return XLUE_SetIDTimer(&OnTimerCallBack, timerID, elapse, this);
	}

	unsigned long SetOnceIDTimer(unsigned int timerID, unsigned int elapse)
	{
		return XLUE_SetOnceIDTimer(&OnTimerCallBack, timerID, elapse, this);
	}

	bool QueryTime(unsigned int timerID)
	{
		return !!XLUE_QueryTimer(timerID);
	}

	bool KillTimer(unsigned int timerID)
	{
		return !!XLUE_KillTimer(timerID, NULL);
	}

protected:

	virtual void OnTimer(unsigned int /*timerID*/)
	{
		
	}

private:

	static void XLUE_STDCALL OnTimerCallBack(void* userData, unsigned int timerID)
	{
		TimerManagerWrapper* lpThis = (TimerManagerWrapper*)userData;
		assert(lpThis);

		lpThis->OnTimer(timerID);
	}
};

} // Bolt
} // Xunlei
#endif // __TIMERMANAGERWRAPPER_H__