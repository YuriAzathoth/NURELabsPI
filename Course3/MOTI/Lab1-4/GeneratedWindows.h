///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Oct 26 2018)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/button.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statline.h>
#include <wx/stattext.h>
#include <wx/choice.h>
#include <wx/grid.h>
#include <wx/spinctrl.h>
#include <wx/dialog.h>
#include <wx/combobox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class IMainDialog
///////////////////////////////////////////////////////////////////////////////
class IMainDialog : public wxDialog
{
	private:

	protected:
		wxButton* m_btnUserRegistration;
		wxButton* m_btnCriterionEdit;
		wxButton* m_btnEditAlternatives;
		wxStaticLine* m_staticline8;
		wxStaticText* m_staticText14;
		wxChoice* m_selUserName;
		wxGrid* m_gridVitality;
		wxButton* m_btnSaveWeights;
		wxStaticLine* m_staticline4;
		wxStaticText* m_staticText141;
		wxSpinCtrl* m_spinThreshold;
		wxGrid* m_gridResult;
		wxStaticLine* m_staticline6;
		wxButton* m_btnCalcLab2;
		wxButton* m_btnCalcLab3;
		wxButton* m_btnCalcLab4;

		// Virtual event handlers, overide them in your derived class
		virtual void OnClose( wxCloseEvent& event ) { event.Skip(); }
		virtual void OnInit( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnClickEditUsers( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEditCriterions( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEditAlternatives( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelectName( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveWeights( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCalcLab2( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCalcLab3( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCalcLab4( wxCommandEvent& event ) { event.Skip(); }


	public:

		IMainDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Лаба по MOTI"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_DIALOG_STYLE|wxTAB_TRAVERSAL );
		~IMainDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class IComparisonDialog
///////////////////////////////////////////////////////////////////////////////
class IComparisonDialog : public wxDialog
{
	private:

	protected:
		wxGrid* m_gridPair;
		wxButton* m_btnSelect1;
		wxButton* m_btnSelect2;

		// Virtual event handlers, overide them in your derived class
		virtual void OnInit( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnSelect1Click( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSelect2Click( wxCommandEvent& event ) { event.Skip(); }


	public:

		IComparisonDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Сравнение альтернатив"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~IComparisonDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class IUsersDialog
///////////////////////////////////////////////////////////////////////////////
class IUsersDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText16;
		wxComboBox* m_cmbName;
		wxStaticText* m_staticText18;
		wxSpinCtrlDouble* m_spinRange;
		wxButton* m_btnCreate;
		wxButton* m_btnEdit;
		wxButton* m_btnDelete;

		// Virtual event handlers, overide them in your derived class
		virtual void OnInit( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnSelectName( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCreate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEdit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickDelete( wxCommandEvent& event ) { event.Skip(); }


	public:

		IUsersDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Создание пользователя"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~IUsersDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ICriterionsDialog
///////////////////////////////////////////////////////////////////////////////
class ICriterionsDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText14;
		wxComboBox* m_cmbName;
		wxStaticText* m_staticText16;
		wxSpinCtrlDouble* m_spinRange;
		wxStaticText* m_staticText18;
		wxSpinCtrlDouble* m_spinWeight;
		wxStaticText* m_staticText20;
		wxChoice* m_selType;
		wxStaticText* m_staticText22;
		wxChoice* m_selOptimal;
		wxStaticText* m_staticText24;
		wxComboBox* m_cmbUnits;
		wxStaticText* m_staticText26;
		wxComboBox* m_cmbScaleType;
		wxButton* m_btnCreate;
		wxButton* m_btnEdit;
		wxButton* m_btnDelete;

		// Virtual event handlers, overide them in your derived class
		virtual void OnInit( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnSelectName( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCreate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEdit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickDelete( wxCommandEvent& event ) { event.Skip(); }


	public:

		ICriterionsDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Критерии качества"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~ICriterionsDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class IAlternativesDialog
///////////////////////////////////////////////////////////////////////////////
class IAlternativesDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText14;
		wxComboBox* m_cmbName;
		wxStaticLine* m_staticline2;
		wxGrid* m_gridMarks;
		wxStaticLine* m_staticline4;
		wxButton* m_btnCreate;
		wxButton* m_btnEdit;
		wxButton* m_btnDelete;

		// Virtual event handlers, overide them in your derived class
		virtual void OnInit( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnSelectName( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickCreate( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickEdit( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClickDelete( wxCommandEvent& event ) { event.Skip(); }


	public:

		IAlternativesDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Альтернативы"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~IAlternativesDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ICalculateDialog
///////////////////////////////////////////////////////////////////////////////
class ICalculateDialog : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText16;
		wxChoice* m_selUser;

		// Virtual event handlers, overide them in your derived class
		virtual void OnInit( wxInitDialogEvent& event ) { event.Skip(); }


	public:

		ICalculateDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Рассчёт"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );
		~ICalculateDialog();

};

