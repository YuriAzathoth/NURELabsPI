#include <cstdlib>
#include <algorithm>
#include <array>
#include <wx/grid.h>
#include <wx/stattext.h>
#include <wx/string.h>
#include "MainWindow.h"

enum EResult { Draw, Win, Loose };
constexpr EResult g_eRulesMatrix[3][3] =
{
	EResult::Draw,	EResult::Win,	EResult::Loose,
	EResult::Loose,	EResult::Draw,	EResult::Win,
	EResult::Win,	EResult::Loose,	EResult::Draw
};

using char_t = decltype(wxT(' '));
constexpr char_t g_szStateLookup[][10] = { wxT("Ничья"), wxT("Победа"), wxT("Поражение") };
constexpr char_t g_szElementLookup[][8] = { wxT("Камень"), wxT("Ножницы"), wxT("Бумага") };

void MainWindow::OnInit(wxInitDialogEvent &event)
{
	m_RandGen.seed(std::random_device()());
	GenerateMatrix();
	m_Moves.reserve(32);
}

void MainWindow::OnClickReset(wxCommandEvent &event)
{
	GenerateMatrix();
	m_Moves.clear();
	m_nScorePlayer = 0;
	m_nScoreBot = 0;
	UpdateWindow();
	m_txtBotSelection->SetLabel(wxT(""));
}

void MainWindow::OnClickHelp(wxCommandEvent &event)
{
	std::array<unsigned, EElement::Count> rows_res;
	std::array<unsigned, EElement::Count> cols_res;
	for (int i = 0; i < EElement::Count; ++i)
	{
		rows_res[i] = (unsigned)wxAtoi(m_gridMatrix->GetCellValue(i, EElement::Count));
		cols_res[i] = (unsigned)wxAtoi(m_gridMatrix->GetCellValue(EElement::Count, i));
	}

	const auto rows_max_it = std::max_element(rows_res.begin(), rows_res.end());
	const auto cols_min_it = std::min_element(cols_res.begin(), cols_res.end());
	const size_t row_id = std::distance(rows_res.begin(), rows_max_it);
	const size_t col_id = std::distance(cols_res.begin(), cols_min_it);

	m_gridMatrix->SetCellBackgroundColour(row_id, EElement::Count, wxColour(150, 255, 150));
	m_gridMatrix->SetCellBackgroundColour(EElement::Count, col_id, wxColour(255, 150, 150));
	m_gridMatrix->Refresh();
}

void MainWindow::DoMove(EElement ePlayerSelection)
{
	std::uniform_int_distribution<unsigned> Dist(0, EElement::Count);

	unsigned nBotSelection = Dist(m_RandGen);
	const EResult eResult = g_eRulesMatrix[ePlayerSelection][nBotSelection];
	switch (eResult)
	{
	case EResult::Win:
		m_nScorePlayer += wxAtoi(m_gridMatrix->GetCellValue(ePlayerSelection, nBotSelection));
		break;
	case EResult::Loose:
		m_nScoreBot += wxAtoi(m_gridMatrix->GetCellValue(ePlayerSelection, nBotSelection));
		break;
	}

	m_txtStatus->SetLabel(g_szStateLookup[eResult]);
	m_txtBotSelection->SetLabel(g_szElementLookup[nBotSelection]);
	UpdateWindow();

	m_Moves.emplace_back(ePlayerSelection, nBotSelection);
}

void MainWindow::UpdateMatrix()
{
	for (int i = 0; i < EElement::Count; ++i)
	{
		unsigned max_col = 0;
		unsigned min_row = (unsigned)-1;
		for (int j = 0; j < EElement::Count; ++j)
		{
			min_row = std::min(min_row, (unsigned)wxAtoi(m_gridMatrix->GetCellValue(i, j)));
			max_col = std::max(max_col, (unsigned)wxAtoi(m_gridMatrix->GetCellValue(j, i)));
		}
		m_gridMatrix->SetCellValue(EElement::Count, i, wxString::Format("%u", max_col));
		m_gridMatrix->SetCellValue(i, EElement::Count, wxString::Format("%u", min_row));
	}

	for (int i = 0; i <= EElement::Count; ++i)
		for (int j = 0; j <= EElement::Count; ++j)
			m_gridMatrix->SetCellBackgroundColour(i, j, wxColour(255, 255, 255));
	m_gridMatrix->Refresh();
}

void MainWindow::UpdateWindow()
{
	m_txtScorePlayer->SetLabel(wxString::Format("%u", m_nScorePlayer));
	m_txtScoreBot->SetLabel(wxString::Format("%u", m_nScoreBot));
}

void MainWindow::GenerateMatrix()
{
	std::uniform_int_distribution<unsigned> Dist(1, 10);

	for (int i = 0; i < EElement::Count; ++i)
	{
		m_gridMatrix->SetReadOnly(i, EElement::Count, true);
		m_gridMatrix->SetReadOnly(EElement::Count, i, true);
		for (int j = 0; j < EElement::Count; ++j)
			m_gridMatrix->SetCellValue(i, j, wxString::Format("%u", Dist(m_RandGen)));
	}
	UpdateMatrix();
}
