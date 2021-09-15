#include <cstdint>
#include <cstring>
#include "CChatMessage.h"
#include <wx/buffer.h>

CChatMessage::CChatMessage(uint8_t id, const wxString &message) :
	id_(id),
	message_(message)
{
}

void CChatMessage::Read(wxSocketBase* socket)
{
	uint8_t length;

	socket->Read(&id_, 1);
	socket->Read(&length, 1);

	wxCharBuffer buffer(length);
	socket->Read(buffer.data(), length);
	message_ = buffer.data();
}

void CChatMessage::Write(wxSocketBase* socket) const
{
	const uint8_t length = static_cast<uint8_t>(message_.Length());

	socket->Write(&id_, 1);
	socket->Write(&length, 1);
	socket->Write(message_.c_str().AsChar(), length);
}
