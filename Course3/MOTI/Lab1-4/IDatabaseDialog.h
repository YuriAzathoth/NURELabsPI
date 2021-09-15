#ifndef IDATABASEDIALOG_H
#define IDATABASEDIALOG_H

#include <memory>
#include <vector>
#include <wx/window.h>

#define DECLARE_DIALOG(CLASS) public: CLASS(wxWindow* parent, std::shared_ptr<DatabaseView> pDbAdapter) : I##CLASS(parent), IDatabaseDialog(parent, pDbAdapter) {}

class DatabaseView;

class IDatabaseDialog
{
public:
	IDatabaseDialog(wxWindow* parent, std::shared_ptr<DatabaseView> pDbAdapter) : m_pDbAdapter(pDbAdapter), m_wndParent(parent), m_iCurrentPos(-1) {}

protected:
	std::vector<int> m_Ids;
	std::shared_ptr<DatabaseView> m_pDbAdapter;
	wxWindow* m_wndParent;
	int m_iCurrentPos;
};

#endif // IDATABASEDIALOG_H
