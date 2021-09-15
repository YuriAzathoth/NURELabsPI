#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cstdint>
#include <random>
#include <utility>
#include <vector>
#include "GeneratedWindows.h"

class MainWindow : public IMainWindow
{
public:
	MainWindow(wxWindow* pParent) : IMainWindow(pParent), m_nScorePlayer(0), m_nScoreBot(0) {}

private:
	enum EElement  : uint8_t { Stone, Scissors, Paper, Count };

	void OnInit			(wxInitDialogEvent &event) override final;
	void OnClickReset	(wxCommandEvent &event) override final;
	void OnClickHelp	(wxCommandEvent &event)	override final;

	void OnClickStone	(wxCommandEvent &event)	override final { DoMove(EElement::Stone); }
	void OnClickScissors(wxCommandEvent &event)	override final { DoMove(EElement::Scissors); }
	void OnClickPaper	(wxCommandEvent &event)	override final { DoMove(EElement::Paper); }
	void OnClose		(wxCloseEvent &event)	override final { wxExit(); }
	void OnEditMatrix	(wxGridEvent &event)	override final { UpdateMatrix(); }

	void DoMove			(EElement ePlayerSelection);
	void UpdateWindow	();
	void UpdateMatrix	();
	void GenerateMatrix	();

	std::mt19937 m_RandGen;
	std::vector<std::pair<uint8_t, uint8_t>> m_Moves;

    uint8_t m_nScorePlayer;
	uint8_t m_nScoreBot;
};

#endif // MAINWINDOW_H
