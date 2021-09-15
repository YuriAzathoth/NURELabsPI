#ifndef DATABASEDATA_H
#define DATABASEDATA_H

#include <unordered_map>
#include <vector>
#include <wx/string.h>

template<typename TData>
struct DatabaseData
{
	DatabaseData() : nCurrentId(0) {}
	using TDataMap = std::unordered_map<unsigned, TData>;
	TDataMap Data;
	std::vector<unsigned> Order;
	unsigned nCurrentId;
};

struct MarkData
{
	wxString sName;
	float fNumMark;
	float fNormMark;
	unsigned nMarkId;
	unsigned nRange;
	unsigned nCritId;
	unsigned nVectorId;
};

struct AlternativeData
{
	using TMarksMap = std::unordered_map<unsigned, MarkData>;
	TMarksMap Marks;
    wxString sName;
    unsigned nId;
};

struct CriterionData
{
    wxString sName;
    wxString sUnits;
    wxString sScale;
    unsigned nId;
    unsigned nRange;
    unsigned nWeight;
    unsigned nType;
    unsigned nOptimal;
};

struct ResultData
{
	unsigned nResId;
	unsigned nLprId;
	unsigned nAltId;
	unsigned nRange;
	unsigned nWeight;
};

struct UserData
{
    wxString sName;
    float fRange;
    unsigned nId;
};

struct ResultDataPrepared
{
	wxString sAltName;
	unsigned nWeight;
	unsigned nRange;
};

struct WeightData
{
    unsigned nId;
    unsigned nCritId;
    unsigned nUserId;
    unsigned nWeight;
};

struct weights_compare
{
	bool operator()(const WeightData &lhs, unsigned rhs)
	{
		return lhs.nUserId < rhs;
	}
	bool operator()(unsigned lhs, const WeightData &rhs)
	{
		return lhs < rhs.nUserId;
	}
};

#endif // DATABASEDATA_H
