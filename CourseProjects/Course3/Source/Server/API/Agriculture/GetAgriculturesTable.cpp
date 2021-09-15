#include "GetAgriculturesTable.h"
#include "Model/AgricultureTable.h"

std::string GetAgriculturesTable::ProcessRequest()
{
	AgricultureTable table;
	return table.ToJsonString();
}
