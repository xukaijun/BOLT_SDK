/********************************************************************
*
* =-----------------------------------------------------------------=
* =                                                                 =
* =             Copyright (c) Xunlei, Ltd. 2004-2013              =
* =                                                                 =
* =-----------------------------------------------------------------=
* 
*   FileName    :   HostWndWrapper
*   Author      :   李亚星
*   Create      :   2013-5-19 0:04
*   LastChange  :   2013-5-19 0:04
*   History     :	
*
*   Description :   BOLT的hostwnd的C++辅助类
*
********************************************************************/ 
#ifndef __HOSTWNDWRAPPER_H__
#define __HOSTWNDWRAPPER_H__

#include <XLUE.h>
#include <assert.h>

namespace Xunlei
{
namespace Bolt
{

class HostWndWrapper
{
public:
	XLUE_HOSTWND_HANDLE m_hHostWnd;

public:

	HostWndWrapper(XLUE_HOSTWND_HANDLE hHostWnd = NULL)
		:m_hHostWnd(hHostWnd)
	{
	}

	HostWndWrapper& operator=(XLUE_HOSTWND_HANDLE hHostWnd)
	{
		m_hHostWnd = hHostWnd;

		return *this;
	}

	void Attach(XLUE_HOSTWND_HANDLE hNewHostWnd)
	{
		assert(m_hHostWnd == NULL);
		assert((hNewHostWnd == NULL) || XLUE_IsHostWndValid(hNewHostWnd));

		m_hHostWnd = hNewHostWnd;
	}

	XLUE_HOSTWND_HANDLE Detach()
	{
		XLUE_HOSTWND_HANDLE hHostWnd = m_hHostWnd;
		m_hHostWnd = NULL;

		return hHostWnd;
	}

	operator XLUE_HOSTWND_HANDLE() const
	{ 
		return m_hHostWnd; 
	}

public:

	bool IsValid() const
	{
		return ((m_hHostWnd !=NULL) && (!!XLUE_IsHostWndValid(m_hHostWnd)));
	}

	const char* GetClass() const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_GetHostWndClassName(m_hHostWnd);
	}

	const char* GetID() const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_GetHostWndID(m_hHostWnd);
	}

	bool BindUIObjectTree(XLUE_OBJTREE_HANDLE hObjTree) const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return !!XLUE_BindUIObjectTree(m_hHostWnd, hObjTree);
	}

	XLUE_OBJTREE_HANDLE UnbindUIObjectTree() const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_UnbindUIObjectTree(m_hHostWnd);
	}

	XLUE_OBJTREE_HANDLE GetBindUIObjectTree() const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_GetBindUIObjectTree(m_hHostWnd);
	}

	unsigned long GetUpdateFPS() const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_GetUpdateFPS(m_hHostWnd);
	}

	bool SetUpdateFPS(unsigned long fps) const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return !!XLUE_SetUpdateFPS(m_hHostWnd, fps);
	}

	bool GetVisible() const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return !!XLUE_GetHostWndVisible(m_hHostWnd);
	}

	bool SetVisible(bool visible) const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return !!XLUE_SetHostWndVisible(m_hHostWnd, visible? TRUE : FALSE);
	}

	bool SetLayered(bool layered) const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return !!XLUE_SetHostWndLayered(m_hHostWnd, layered? TRUE : FALSE);
	}

	bool GetLayered() const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return !!XLUE_GetHostWndLayered(m_hHostWnd);
	}


	bool MoveWindow(const RECT* lpRect) const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return !!XLUE_MoveHostWnd(m_hHostWnd, lpRect);
	}

	bool GetWindowRect(RECT* lpRect) const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return !!XLUE_GetHostWndRect(m_hHostWnd, lpRect);
	}

	OS_HOSTWND_HANDLE GetWindowHandle() const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_GetHostWndWindowHandle(m_hHostWnd);
	}

	BOOL SetHostWndTitle(const char* lpTitle) const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_SetHostWndTitle(m_hHostWnd, lpTitle);
	}

	const char* GetHostWndTitle() const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_GetHostWndTitle(m_hHostWnd);
	}

	BOOL SetHostWndEnable(BOOL enable) const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_SetHostWndEnable(m_hHostWnd, enable);
	}

	BOOL GetHostWndEnable() const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_GetHostWndEnable(m_hHostWnd);
	}

	BOOL SetHostWndTopMost(BOOL topmost) const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_SetHostWndTopMost(m_hHostWnd, topmost);
	}

	BOOL GetHostWndTopMost() const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_GetHostWndTopMost(m_hHostWnd);
	}

	XL_BITMAP_HANDLE GetWindowBitmap() const
	{
		assert(m_hHostWnd);
		assert(XLUE_IsHostWndValid(m_hHostWnd));

		return XLUE_GetWindowBitmap(m_hHostWnd);
	}
};

} // Bolt
} // Xunlei

#endif // __HOSTWNDWRAPPER_H__