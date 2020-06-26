#pragma once

#include "UIWindow.h"
#include "UIListWnd.h"
#include "UIListItemServer.h"
#include "UIFrameWindow.h"
#include "UIEditBox.h"
#include "UI3tButton.h"

class CUIXml;
class CGameSpy_Browser;
class CUIColorAnimatorWrapper;
class CUIMessageBoxEx;
class CGameSpy_Browser;
struct ServerInfo;

#define LST_SERVER		0 
#define LST_SRV_PROP	1
#define LST_PLAYERS		2
#define DIF_HEIGHT		180
#define LST_COLUMN_COUNT	7

class SServerFilters{
public:
	bool	empty;
	bool	full;
	bool	with_pass;
	bool	without_pass;
	bool	without_ff;
	bool	listen_servers;
};

class CServerList : public CUIWindow{
public:
	CServerList();
	virtual ~CServerList();

	virtual void 	Init				(float x, float y, float width, float height);
	virtual void 	Update				();
	virtual void 	SendMessage			(CUIWindow* pWnd, s16 msg, void* pData = NULL);
			void 	InitFromXml			(CUIXml& xml_doc, LPCSTR path);
			void 	InitHeader			();
			void 	InitSeparator		();
			void 	AddServerToList		(ServerInfo* pServerInfo);
			void 	UpdateServerInList	(ServerInfo* pServerInfo, int index);
			void 	UpdateServerInList	(ServerInfo* pServerInfo, CUIListItemServer* pItem);
			void 	ConnectToSelected	();
			void 	SetFilters			(SServerFilters& sf);
			void 	SetPlayerName		(LPCSTR name);
			void 	SetSortFunc			(LPCSTR func_name, bool make_sort);
			void	NetRadioChanged		(bool Local);
	virtual void	RefreshGameSpyList	(bool Local);
			void	RefreshQuick();
			void	ShowServerInfo();			
	virtual	void	RefreshList();

protected:
			bool IsValidItem(ServerInfo& item);
			void SrvInfo2LstSrvInfo(const ServerInfo* pSrvInfo);
			void UpdateSizes();
			void UpdateVisibility();
			void BeforeAppear();
			void AfterAppear();
			void BeforeDisapear();
			void AfterDisappear();
			void FillUpDetailedServerInfo();
			void ClearDetailedServerInfo();

			void SaveCurItem();
			void RestoreCurItem();
			void ResetCurItem();
			bool NeedToRefreshCurServer	();

	static	bool sort_by_ServerName(int p1, int p2);
	static	bool sort_by_Map(int p1, int p2);
	static	bool sort_by_GameType(int p1, int p2);
	static	bool sort_by_Players(int p1, int p2);
	static	bool sort_by_Ping(int p1, int p2);
	static	bool sort_by_Version(int p1, int p2);

	CUIColorAnimatorWrapper* m_pAnimation;

	LIST_SRV_ITEM	m_itemInfo;
	SServerFilters	m_sf;
	CUIListWnd		m_list[3];
	CUIFrameWindow	m_frame[3];
	CUI3tButton		m_header[LST_COLUMN_COUNT];
	CUILabel		m_header2[4];
	CUIFrameLineWnd	m_header_frames[LST_COLUMN_COUNT];
	CUIEditBox		m_edit_gs_filter;
	xr_string		m_playerName;
	bool			m_bShowServerInfo;
	bool			m_bAnimation;
	float			m_fListH[2];
	float			m_fEditPos[2];
	int				m_cur_item;
	bool			m_b_local;

	CUIMessageBoxEx* m_message_box;

	CGameSpy_Browser*	m_GSBrowser;	

	shared_str						m_sort_func;
	xr_vector<int>					m_tmp_srv_lst;
	struct SrvItem{
		CUIListItemServer*	m_ui_item;
		bool				m_busy;
	};
	CUIListItemServer*			GetFreeItem		();
	void						DestroySrvItems	();	
	void						ClearSrvItems	();	

	typedef xr_vector<SrvItem>	SrvItems;
	typedef SrvItems::iterator	SrvItems_It;
	SrvItems					m_items_cache;
	u32							m_last_retreived_index;
	u32							m_need_refresh_fr;
	void						RefreshList_internal();
};