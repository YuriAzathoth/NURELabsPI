/***************************************************************
 * Name:      Lab03Main.h
 * Purpose:   Defines Application Frame
 * Author:    Юрий Зинченко (asmodeus.x5@outlook.com)
 * Created:   2018-11-30
 * Copyright: Юрий Зинченко (2018)
 * License:   GPLv3
 **************************************************************/

#ifndef LAB03MAIN_H
#define LAB03MAIN_H

//(*Headers(Lab03Frame)
#include <wx/bmpbuttn.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textdlg.h>
#include <wx/treectrl.h>
//*)

class MapFormat;

class Lab03Frame: public wxFrame
{
public:

	Lab03Frame(wxWindow* parent,wxWindowID id = -1);
	virtual ~Lab03Frame();

private:
    enum ETOOL
    {
    	TOOL_NULL,
    	TOOL_CITY,
    	TOOL_VILLAGE,
    	TOOL_ROAD,
    	TOOL_RAILWAY,
    	TOOL_FOREST,
    	TOOL_WOOD,
    	TOOL_RIVER,
    	TOOL_SEA
    };

    void Save();
    void SaveAs();

    void DrawBackground(wxPaintDC &rDC, wxRect rectPanelSize);
    void UpdateMode();
    void UpdateTree();
    wxPoint* GetVertex(const wxPoint &rCoord) const;

    void AddObject(int eType);
    void ClearMap();

    inline void SetTool(ETOOL eTool)
    {
		if (!GetNewName() || eTool == TOOL_NULL)
			return;
		m_eCurrTool = eTool;
		UpdateMode();
    }
	inline wxString GetName()
	{
		NameTextDlg->ShowModal();
		if (NameTextDlg->GetReturnCode() != 5100)
			return wxEmptyString;
		else if (NameTextDlg->GetValue() == wxEmptyString)
		{
			wxMessageBox(_("Пожалуйста, введите имя!"), _("Имя не может быть пустым"), wxOK | wxCENTRE, this);
			return wxEmptyString;
		}
		else
			return NameTextDlg->GetValue();
	}
	inline bool GetNewName()
	{
		wxString wsName = GetName();
		if (wsName == wxEmptyString)
			return false;
		m_wsCurrName = wsName;
		return true;
	}

    MapFormat* m_pMap;
	wxLocale* m_pLocale;
	wxPointList m_BufferNew;
	wxString m_wsCurrName;

	wxPoint* m_pHoldVertex;
	bool m_bHoldVertex;

    ETOOL m_eCurrTool;

	//(*Handlers(Lab03Frame)
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);
	void OnEditorPanelPaint(wxPaintEvent& event);
	void OnOpen(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);
	void OnSaveAs(wxCommandEvent& event);
	void OnCloseMap(wxCommandEvent& event);
	void OnNew(wxCommandEvent& event);
	void OnBtnCityClick(wxCommandEvent& event);
	void OnBtnVillageClick(wxCommandEvent& event);
	void OnBtnRoadClick(wxCommandEvent& event);
	void OnBtnRailClick(wxCommandEvent& event);
	void OnBtnForestClick(wxCommandEvent& event);
	void OnBtnWoodClick(wxCommandEvent& event);
	void OnBtnRiverClick(wxCommandEvent& event);
	void OnBtnSeaClick(wxCommandEvent& event);
	void OnEditorPanelLeftDown(wxMouseEvent& event);
	void OnEditorPanelRightDown(wxMouseEvent& event);
	void OnBtnDelObjClick(wxCommandEvent& event);
	void OnObjsTreeCtrlSelectionChanged(wxTreeEvent& event);
	void OnBtnObjRenClick(wxCommandEvent& event);
	void OnEditorPanelLeftUp(wxMouseEvent& event);
	void OnEditorPanelMouseMove(wxMouseEvent& event);
	void OnHelp(wxCommandEvent& event);
	//*)

	//(*Identifiers(Lab03Frame)
	static const long ID_BITMAPBUTTON12;
	static const long ID_BITMAPBUTTON13;
	static const long ID_BITMAPBUTTON11;
	static const long ID_BITMAPBUTTON14;
	static const long ID_BITMAPBUTTON1;
	static const long ID_BITMAPBUTTON2;
	static const long ID_BITMAPBUTTON3;
	static const long ID_BITMAPBUTTON4;
	static const long ID_BITMAPBUTTON5;
	static const long ID_BITMAPBUTTON6;
	static const long ID_BITMAPBUTTON7;
	static const long ID_BITMAPBUTTON8;
	static const long ID_STATICTEXT1;
	static const long ID_PANEL2;
	static const long ID_BITMAPBUTTON9;
	static const long ID_BITMAPBUTTON10;
	static const long ID_TREECTRL1;
	static const long ID_PANEL1;
	static const long idMenuCreate;
	static const long idMenuOpen;
	static const long idMenuSave;
	static const long idMenuSaveAs;
	static const long idMenuClose;
	static const long idMenuQuit;
	static const long idMenuHelp;
	static const long idMenuAbout;
	static const long ID_STATUSBAR1;
	static const long ID_TEXTENTRYDIALOG1;
	//*)

	//(*Declarations(Lab03Frame)
	wxBitmapButton* BtnCity;
	wxBitmapButton* BtnCreate;
	wxBitmapButton* BtnForest;
	wxBitmapButton* BtnHelp;
	wxBitmapButton* BtnObjDel;
	wxBitmapButton* BtnObjRen;
	wxBitmapButton* BtnOpen;
	wxBitmapButton* BtnRail;
	wxBitmapButton* BtnRiver;
	wxBitmapButton* BtnRoad;
	wxBitmapButton* BtnSave;
	wxBitmapButton* BtnSea;
	wxBitmapButton* BtnVillage;
	wxBitmapButton* BtnWood;
	wxMenuItem* MenuItem3;
	wxMenuItem* MenuItem4;
	wxMenuItem* MenuItem5;
	wxMenuItem* MenuItem7;
	wxMenuItem* MenuItem8;
	wxMenuItem* MenuItem9;
	wxPanel* EditorPanel;
	wxPanel* MainPanel;
	wxStaticText* LabelTool;
	wxStatusBar* StatusBar;
	wxTextEntryDialog* NameTextDlg;
	wxTreeCtrl* ObjsTreeCtrl;
	//*)

	DECLARE_EVENT_TABLE()

	Lab03Frame(const Lab03Frame&) = delete;
	Lab03Frame& operator=(const Lab03Frame&) = delete;
};

#endif // LAB03MAIN_H
