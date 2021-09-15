#ifndef CCHATMESSAGE_H
#define CCHATMESSAGE_H

#include <cstdint>
#include <wx/socket.h>
#include <wx/string.h>

class CChatMessage
{
public:
	CChatMessage() {}
	CChatMessage(uint8_t id, const wxString &message);

	void Read(wxSocketBase* socket);
	void Write(wxSocketBase* socket) const;

	const wxString &GetMessage() const noexcept { return message_; }
	uint8_t GetId() const noexcept { return id_; }

private:
	wxString message_;
	uint8_t id_;
};

#endif // CCHATMESSAGE_H
