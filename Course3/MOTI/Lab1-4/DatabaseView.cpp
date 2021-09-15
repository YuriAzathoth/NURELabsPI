#include <cmath>
#include <algorithm>
#include <numeric>
#include <utility>
#include <wx/choice.h>
#include <wx/combobox.h>
#include <wx/grid.h>
#include "nanodbc/nanodbc.h"
#include "DatabaseView.h"
#include "DatabaseUtility.h"

static const nanodbc::string g_sConnectionString = NANODBC_TEXT("Driver={PostgreSQL ODBC Driver(UNICODE)};Server=localhost;Port=5432;Database=moti-db;Uid=moti-user;Pwd=24682468;");

// =========================================
// Constructor/Destructor
// =========================================

DatabaseView::DatabaseView() : m_pConnection(new nanodbc::connection(g_sConnectionString))
{
	LoadUsers();
	LoadCriterions();
	LoadAlternatives();
	LoadResults();
}

DatabaseView::~DatabaseView()
{
	delete m_pConnection;
}

// =========================================
// Users
// =========================================

void DatabaseView::LoadUsersList(wxItemContainer* pItemContainer)
{
	m_Users.Order.clear();
	m_Users.Order.resize(m_Users.Data.size());
	pItemContainer->Clear();
	std::for_each(m_Users.Data.begin(), m_Users.Data.end(), [pItemContainer, this](const auto &data)
	{
		const int iPos = pItemContainer->Append(data.second.sName);
		m_Users.Order[iPos] = data.second.nId;
	});
	pItemContainer->SetSelection(0);
}

void DatabaseView::InsertUserData(const UserData &rData)
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(INSERT INTO "LPR" VALUES(DEFAULT, ?, ?))"));
	statement.bind(0, wx_to_nano(rData.sName));
	statement.bind(1, &rData.fRange);
	statement.execute();
	LoadUsers();
}

void DatabaseView::EditUserData(const UserData &rData)
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(UPDATE "LPR" SET "LName" = ?, "LRange" = ? WHERE "IdLPR" = ?)"));
	statement.bind(0, wx_to_nano(rData.sName));
	statement.bind(1, &rData.fRange);
	statement.bind(2, &m_Users.Order[m_Users.nCurrentId]);
	statement.execute();
	LoadUsers();
}

void DatabaseView::DeleteUserData()
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(DELETE FROM "LPR" WHERE "IdLPR" = ?)"));
	statement.bind(0, &m_Users.Order[m_Users.nCurrentId]);
	statement.execute();
	LoadUsers();
}

void DatabaseView::LoadUsers()
{
	UserData data;
	nanodbc::result result = nanodbc::execute(*m_pConnection, NANODBC_TEXT(R"(SELECT * FROM "LPR")"));
	m_Users.Data.clear();
	for (unsigned i = 0; result.next(); ++i)
	{
		data.nId = result.get<unsigned>(0);
		data.sName = nano_to_wx(result.get<nanodbc::string>(1));;
		data.fRange = result.get<float>(2);
		m_Users.Data.emplace(data.nId, data);
	}
}

// =========================================
// Criterions
// =========================================

void DatabaseView::LoadCriterionsList(wxItemContainer* pItemContainer)
{
	m_Criterions.Order.clear();
	m_Criterions.Order.resize(m_Criterions.Data.size());
	pItemContainer->Clear();
	std::for_each(m_Criterions.Data.begin(), m_Criterions.Data.end(), [pItemContainer, this](const auto &data)
	{
		const int iPos = pItemContainer->Append(data.second.sName);
		m_Criterions.Order[iPos] = data.second.nId;
	});
	pItemContainer->SetSelection(0);
}

void DatabaseView::InsertCriterionData(const CriterionData &rData)
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(INSERT INTO "Criterion" VALUES(DEFAULT, ?, ?, ?, ?, ?, ?, ?))"));
	statement.bind(0, wx_to_nano(rData.sName));
	statement.bind(1, &rData.nRange);
	statement.bind(2, &rData.nWeight);
	statement.bind(3, &rData.nType);
	statement.bind(4, &rData.nOptimal);
	statement.bind(5, wx_to_nano(rData.sUnits));
	statement.bind(6, wx_to_nano(rData.sScale));
	statement.execute();
	LoadCriterions();
}

void DatabaseView::EditCriterionData(const CriterionData &rData)
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(UPDATE "Criterion" SET "CName" = ?, "CRange" = ?, "CWeight" = ?, "CType" = ?, "OptimType" = ?, "EdIzmer" = ?, "ScaleType" = ? WHERE "IdCrit" = ?)"));
	statement.bind(0, wx_to_nano(rData.sName));
	statement.bind(1, &rData.nRange);
	statement.bind(2, &rData.nWeight);
	statement.bind(3, &rData.nType);
	statement.bind(4, &rData.nOptimal);
	statement.bind(5, wx_to_nano(rData.sUnits));
	statement.bind(6, wx_to_nano(rData.sScale));
	statement.bind(7, &m_Criterions.Order[m_Criterions.nCurrentId]);
	statement.execute();
	LoadCriterions();
}

void DatabaseView::DeleteCriterionData()
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(DELETE FROM "Criterion" WHERE "IdCrit" = ?)"));
	statement.bind(0, &m_Criterions.Order[m_Criterions.nCurrentId]);
	statement.execute();
	LoadCriterions();
}

void DatabaseView::LoadCriterions()
{
	CriterionData data;
	nanodbc::result result = nanodbc::execute(*m_pConnection, NANODBC_TEXT(R"(SELECT * FROM "Criterion")"));
	m_Criterions.Data.clear();
	for (unsigned i = 0; result.next(); ++i)
	{
		data.nId		= result.get<unsigned>(0);
		data.sName		= nano_to_wx(result.get<nanodbc::string>(1));
		data.nRange		= result.get<unsigned>(2);
		data.nWeight	= result.get<unsigned>(3);
		data.nType		= result.get<unsigned>(4);
		data.nOptimal	= result.get<unsigned>(5);
		data.sUnits		= nano_to_wx(result.get<nanodbc::string>(6));
		data.sScale		= nano_to_wx(result.get<nanodbc::string>(7));
		m_Criterions.Data.emplace(data.nId, data);
	}
}

// =========================================
// Alternatives
// =========================================

void DatabaseView::LoadAlternativesList(wxItemContainer* pItemContainer)
{
	m_Alternatives.Order.clear();
	m_Alternatives.Order.resize(m_Alternatives.Data.size());
	pItemContainer->Clear();
	std::for_each(m_Alternatives.Data.begin(), m_Alternatives.Data.end(), [pItemContainer, this](const auto &data)
	{
		const int iPos = pItemContainer->Append(data.second.sName);
		m_Alternatives.Order[iPos] = data.second.nId;
	});
	pItemContainer->SetSelection(0);
}

void DatabaseView::InsertAlternativeData(const AlternativeData &rData)
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(INSERT INTO "Alternative" VALUES(DEFAULT, ?))"));
	statement.bind(0, wx_to_nano(rData.sName));
	statement.execute();
	LoadAlternatives();
}

void DatabaseView::EditAlternativeData(const AlternativeData &rData)
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(UPDATE "Alternative" SET "AName" = ? WHERE "IdAlt" = ?)"));
	statement.bind(0, wx_to_nano(rData.sName));
	statement.bind(1, &m_Alternatives.Order[m_Alternatives.nCurrentId]);
	statement.execute();
	LoadAlternatives();
}

void DatabaseView::DeleteAlternativeData()
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(DELETE FROM "Alternative" WHERE "IdAlt" = ?)"));
	statement.bind(0, &m_Alternatives.Order[m_Alternatives.nCurrentId]);
	statement.execute();
	LoadAlternatives();
}

void DatabaseView::LoadAlternatives()
{
	AlternativeData data;
	nanodbc::result result = nanodbc::execute(*m_pConnection, NANODBC_TEXT(R"(SELECT * FROM "Alternative")"));
	m_Alternatives.Data.clear();
	for (unsigned i = 0; result.next(); ++i)
	{
		data.nId = result.get<unsigned>(0);
		data.sName = nano_to_wx(result.get<nanodbc::string>(1));
		m_Alternatives.Data.emplace(data.nId, data);
	}

	result = nanodbc::execute(*m_pConnection, NANODBC_TEXT(R"(SELECT "IdVect", "Mark"."IdMark", "Criterion"."IdCrit", "MName", "MRange", "NumMark", "NormMark", "IdAlt" FROM  "Vector" INNER JOIN "Mark" ON "Vector"."IdMark" = "Mark"."IdMark" INNER JOIN "Criterion" ON "Mark"."IdCrit" = "Criterion"."IdCrit")"));
	for (unsigned i = 0; result.next(); ++i)
	{
		MarkData mark;
		mark.nVectorId	= result.get<unsigned>(0);
		mark.nMarkId	= result.get<unsigned>(1);
		mark.nCritId	= result.get<unsigned>(2);
		mark.sName		= nano_to_wx(result.get<nanodbc::string>(3));
		mark.nRange		= result.get<unsigned>(4);
		mark.fNumMark	= result.get<float>(5);
		mark.fNormMark	= result.get<float>(6);
		AlternativeData &alt = m_Alternatives.Data[result.get<unsigned>(7)];
		alt.Marks.emplace(mark.nCritId, mark);
	}
}

// =========================================
// Marks
// =========================================

void DatabaseView::LoadMarksGrid(wxGrid* pGrid, std::unordered_map<unsigned, unsigned> &rCritIdToPos) const
{
	pGrid->AppendRows(m_Criterions.Data.size());

	int i = 0;
	for (auto it = m_Criterions.Data.cbegin(); it != m_Criterions.Data.cend(); ++it, ++i)
	{
		const unsigned nCritId = it->first;
		pGrid->SetCellValue(i, 0, m_Criterions.Data.at(nCritId).sName);
		pGrid->SetReadOnly(i, 0, true);
		pGrid->SetReadOnly(i, 4, true);
		rCritIdToPos.emplace(nCritId, i);
	}

	pGrid->AutoSize();
}

void DatabaseView::InsertMarkData(unsigned nIdCrit)
{
	const unsigned zero = 0;
	const wxString null_name = wxT("");

	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(INSERT INTO "Mark" VALUES (DEFAULT, ?, ?, ?, ?, ?))"));
	statement.bind(0, wx_to_nano(null_name));
	statement.bind(1, &zero);
	statement.bind(2, &zero);
	statement.bind(3, &zero);
	statement.bind(4, &nIdCrit);
	statement.execute();

	nanodbc::result result = nanodbc::execute(*m_pConnection, NANODBC_TEXT(R"(SELECT MAX("IdMark") FROM "Mark")"));
	result.next();
	const unsigned mark_id = result.get<unsigned>(0);

	statement.prepare(NANODBC_TEXT(R"(INSERT INTO "Vector" VALUES (DEFAULT, ?, ?))"));
	statement.bind(0, &m_Alternatives.Order[m_Alternatives.nCurrentId]);
	statement.bind(1, &mark_id);
	statement.execute();

	LoadAlternatives();
}

void DatabaseView::UpdateMarksData(const AlternativeData &rData)
{
	std::for_each(rData.Marks.begin(), rData.Marks.end(), [this](const auto &pair)
	{
		const MarkData &mark = pair.second;
		nanodbc::statement statement(*m_pConnection);
		statement.prepare(NANODBC_TEXT(R"(UPDATE "Mark" SET "MName" = ?, "MRange" = ?, "NumMark" = ?, "NormMark" = ?, "IdCrit" = ? WHERE "IdMark" = (SELECT "Mark"."IdMark" FROM "Mark" INNER JOIN "Vector" ON "Mark"."IdMark" = "Vector"."IdMark" WHERE "IdCrit" = ? AND "IdAlt" = ?))"));
		statement.bind(0, wx_to_nano(mark.sName));
		statement.bind(1, &mark.nRange);
		statement.bind(2, &mark.fNumMark);
		statement.bind(3, &mark.fNormMark);
		statement.bind(4, &mark.nCritId);
		statement.bind(5, &mark.nCritId);
		statement.bind(6, &m_Alternatives.Order[m_Alternatives.nCurrentId]);
		statement.execute();
	});
	LoadAlternatives();
}

void DatabaseView::EditMarkNormData(unsigned alt_id, unsigned crit_id, float norm_mark) const
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(UPDATE "Mark" SET "NormMark" = ? WHERE "IdMark" = (SELECT "Mark"."IdMark" FROM "Vector" INNER JOIN "Mark" ON "Vector"."IdMark" = "Mark"."IdMark" WHERE "IdAlt" = ? AND "IdCrit" = ?))"));
	statement.bind(0, &norm_mark);
	statement.bind(1, &alt_id);
	statement.bind(2, &crit_id);
	statement.execute();
}

// =========================================
// Weights
// =========================================

void DatabaseView::PushWeights(wxGrid* gridWeights)
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(DELETE FROM "Weight" WHERE "IdLPR" = ?)"));
	statement.bind(0, &m_Users.Order.at(m_Users.nCurrentId));
	statement.execute();

	const unsigned user_id = m_Users.Order.at(m_Users.nCurrentId);
	if (std::find_if(m_Weights.cbegin(), m_Weights.cend(), [user_id](const WeightData &weight)
{
	return weight.nUserId == user_id;
}) != m_Weights.cend())
	{
		auto [it1, it2] = std::equal_range(m_Weights.begin(), m_Weights.end(), GetCurrentUserId(), weights_compare());
		int i = 0;
		std::for_each(it1, it2, [&i, &statement, user_id, gridWeights](const WeightData &weight)
		{
			const int weight_num = wxAtoi(gridWeights->GetCellValue(i, 0));
			statement.prepare(NANODBC_TEXT(R"(INSERT INTO "Weight" VALUES (DEFAULT, ?, ?, ?))"));
			statement.bind(0, &weight.nCritId);
			statement.bind(1, &user_id);
			statement.bind(2, &weight_num);
			statement.execute();
			++i;
		});
	}
	else
		for (const auto &pair : m_Criterions.Data)
		{
			statement.prepare(*m_pConnection, NANODBC_TEXT(R"(INSERT INTO "Weight" VALUES (DEFAULT, ?, ?, 0.0))"));
			statement.bind(0, &pair.second.nId);
			statement.bind(1, &user_id);
			statement.execute();
		}

	LoadWeights();
}

void DatabaseView::PullWeights(wxGrid* gridWeights)
{
	LoadWeights();

	auto [it1, it2] = std::equal_range(m_Weights.begin(), m_Weights.end(), GetCurrentUserId(), weights_compare());

	gridWeights->DeleteRows(0, -1);
	gridWeights->AppendRows(static_cast<int>(std::distance(it1, it2)));

	if (it1 == it2)
		return;

	int i = 0;
	for (; it1 != it2; ++it1, ++i)
	{
		gridWeights->SetRowLabelValue(i, m_Criterions.Data.at(it1->nCritId).sName);
		gridWeights->SetCellValue(i, 0, wxString::Format("%u", it1->nWeight));
	}
}

void DatabaseView::LoadWeights()
{
	m_Weights.clear();

	WeightData weight;
	nanodbc::result result = nanodbc::execute(*m_pConnection, NANODBC_TEXT(R"(SELECT * FROM "Weight")"));
	while (result.next())
	{
		weight.nId		= result.get<unsigned>(0);
		weight.nCritId	= result.get<unsigned>(1);
		weight.nUserId	= result.get<unsigned>(2);
		weight.nWeight	= result.get<unsigned>(3);
		m_Weights.push_back(weight);
	}

	std::sort(m_Weights.begin(), m_Weights.end(), [](const WeightData &lhs, const WeightData &rhs) -> bool
	{
		if (lhs.nUserId == rhs.nUserId)
			return lhs.nCritId < rhs.nCritId;
		else
			return lhs.nUserId < rhs.nUserId;
	});
}

// =========================================
// Results
// =========================================

void DatabaseView::LoadResultsGrid(wxGrid* gridResult)
{
	LoadCriterions();
	LoadResults();

	if (m_Users.Data.empty() || m_Results.empty())
		return;


	const unsigned user_id = m_Users.Order.at(m_Users.nCurrentId);
	auto [it1, it2] = m_Results.equal_range(user_id);
	if (it1 == it2)
		return;

	const int results_count = std::distance(it1, it2);
	std::vector<ResultDataPrepared> result(results_count);
	std::transform(it1, it2, result.begin(), [this](const auto &pair) -> ResultDataPrepared
	{
		return
		{
			m_Alternatives.Data.at(pair.second.nAltId).sName,
			pair.second.nWeight,
			pair.second.nRange
		};
	});
	std::sort(result.begin(), result.end(), [](const ResultDataPrepared &lhs, const ResultDataPrepared &rhs) -> bool
	{
		return lhs.nRange < rhs.nRange;
	});

	gridResult->DeleteRows(0, -1);
	gridResult->AppendRows(results_count);
	for (auto it = result.begin(); it != result.end(); ++it)
	{
		const int row_id = std::distance(result.begin(), it);
		gridResult->SetRowLabelValue(row_id, it->sAltName);
		gridResult->SetCellValue(row_id, 0, wxString::Format("%u", it->nWeight));
		gridResult->SetCellValue(row_id, 1, wxString::Format("%u", it->nRange));
		gridResult->SetReadOnly(row_id, 0, true);
		gridResult->SetReadOnly(row_id, 1, true);
	}
}

void DatabaseView::LoadResults()
{
	m_Results.clear();
	ResultData data;
	nanodbc::result result = nanodbc::execute(*m_pConnection, NANODBC_TEXT(R"(SELECT * FROM "Result")"));
	for (unsigned i = 0; result.next(); ++i)
	{
		data.nResId = result.get<unsigned>(0);
		data.nLprId = result.get<unsigned>(1);
		data.nAltId = result.get<unsigned>(2);
		data.nRange = result.get<unsigned>(3);
		data.nWeight = result.get<unsigned>(4);
		m_Results.emplace(data.nLprId, data);
	}
}

void DatabaseView::ClearResults() const
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(DELETE FROM "Result" WHERE "IdLPR" = ?)"));
	statement.bind(0, &m_Users.Order[m_Users.nCurrentId]);
	statement.execute();
}

void DatabaseView::InsertResult(const ResultData &result) const
{
	nanodbc::statement statement(*m_pConnection);
	statement.prepare(NANODBC_TEXT(R"(INSERT INTO "Result" VALUES (DEFAULT, ?, ?, ?, ?))"));
	statement.bind(0, &result.nLprId);
	statement.bind(1, &result.nAltId);
	statement.bind(2, &result.nRange);
	statement.bind(3, &result.nWeight);
	statement.execute();
}

void DatabaseView::InsertResult(unsigned nAltId)
{
	ResultData result;
	SaveToResult(result, nAltId, 1.0f);
	result.nRange = 1;
	ClearResults();
	InsertResult(result);
	LoadResults();
}

void DatabaseView::InsertResult(TResultVecCIt result_begin, TResultVecCIt result_end, int iTreshold) const
{
	std::vector<ResultData> result(result_begin, result_end);
	auto thresholder = [iTreshold](ResultData &data) -> bool
	{
		return data.nWeight < iTreshold;
	};
	result.erase(std::remove_if(result.begin(), result.end(), thresholder), result.end());
	std::for_each(result.begin(), result.end(), [this](const ResultData &result)
	{
		InsertResult(result);
	});
}

void DatabaseView::SaveToResult(ResultData &result, unsigned alt_id, float percent) const
{
	ResultData &res_data	= result;
	res_data.nLprId			= GetCurrentUserId();
	res_data.nAltId			= alt_id;
	res_data.nWeight		= static_cast<unsigned>(percent * 100.0f);
}

void DatabaseView::SaveToResult(TResultVecIt result_it_begin, TResultVecIt result_it_end, TUIntVecCIt alt_id_it, TFloatVecCIt percent_it) const
{
	for (TResultVecIt result_it = result_it_begin; result_it != result_it_end; ++result_it, ++alt_id_it, ++percent_it)
		SaveToResult(*result_it, *alt_id_it, *percent_it);
	std::sort(result_it_begin, result_it_end, [](const ResultData &lhs, const ResultData &rhs)
	{
		return lhs.nWeight > rhs.nWeight;
	});
	int i = 1;
	for (TResultVecIt result_it = result_it_begin; result_it != result_it_end; ++result_it, ++i)
		result_it->nRange = i;
}

void DatabaseView::CalculateMarks(	std::vector<std::vector<float>> &marks_norm,
									std::vector<unsigned> &crit_ids,
									std::vector<unsigned> &alt_ids) const
{
	const DatabaseData<CriterionData>::TDataMap		&criterions		= m_Criterions.Data;
	const DatabaseData<AlternativeData>::TDataMap	&alternatives	= m_Alternatives.Data;

	crit_ids.resize(criterions.size());
	alt_ids.resize(alternatives.size());
	marks_norm.resize(criterions.size());
	for (std::vector<float> &vec : marks_norm)
		vec.resize(alternatives.size());

	std::transform(criterions.begin(), criterions.end(), crit_ids.begin(), [](const auto &pair)
	{
		return pair.second.nId;
	});
	std::transform(alternatives.begin(), alternatives.end(), alt_ids.begin(), [](const auto &pair)
	{
		return pair.second.nId;
	});

	for (size_t crit = 0; crit < criterions.size(); ++crit)
	{
		std::vector<float> &marks_crit_vector = marks_norm[crit];
		for (size_t alt = 0; alt < alternatives.size(); ++alt)
		{
			float &crit_mark = marks_crit_vector[alt];
			crit_mark = m_Alternatives.Data.at(alt_ids.at(alt)).Marks.at(crit_ids.at(crit)).fNumMark;
			if (!m_Criterions.Data.at(crit_ids.at(crit)).nOptimal)
				crit_mark *= -1.0f;
		}
		NormalizeVector(marks_crit_vector.begin(), marks_crit_vector.end());
	}
}

void DatabaseView::CalculatePercents(const std::vector<std::vector<float>> &marks_norm,
									 const std::vector<unsigned> &crit_ids,
									 const std::vector<unsigned> &alt_ids,
									 const std::vector<float> &weights_norm,
									 std::vector<float> &percents) const
{
	percents.resize(m_Alternatives.Data.size(), 0.0f);

	for (size_t crit = 0; crit < m_Criterions.Data.size(); ++crit)
		for (size_t alt = 0; alt < m_Alternatives.Data.size(); ++alt)
		{
			const float mark = marks_norm.at(crit).at(alt) * weights_norm.at(crit);
			percents[alt] += mark;
			EditMarkNormData(alt_ids.at(alt), crit_ids.at(crit), mark);
		}

	NormalizeVector(percents.begin(), percents.end());
}

void DatabaseView::CalculateLab2(int iTreshold)
{
	std::vector<unsigned> crit_ids;
	std::vector<unsigned> alt_ids;
	std::vector<std::vector<float>>	marks_norm;
	CalculateMarks(marks_norm, crit_ids, alt_ids);

	std::vector<float> weights_norm(m_Criterions.Data.size());
	NormalizeVectorSum(m_Criterions.Data.begin(), m_Criterions.Data.end(), weights_norm.begin(), [](unsigned lhs, const auto &rhs) -> float
	{
		return static_cast<float>(lhs + rhs.second.nWeight * (rhs.second.nOptimal ? 1 : -1));
	},
	[](const auto &src, float sum) -> float
	{
		return static_cast<float>(src.second.nWeight) / sum;
	});

	std::vector<float> percents;
	CalculatePercents(marks_norm, crit_ids, alt_ids, weights_norm, percents);

	std::vector<ResultData> result(m_Alternatives.Data.size());
	SaveToResult(result.begin(), result.end(), alt_ids.cbegin(), percents.cbegin());
	ClearResults();
	InsertResult(result.begin(), result.end(), iTreshold);
	LoadResults();
}

void DatabaseView::CalculateLab4(int iTreshold)
{
	// Marks
	std::vector<unsigned> crit_ids;
	std::vector<unsigned> alt_ids;
	std::vector<std::vector<float>>	marks_norm; // [crit][alt]
	CalculateMarks(marks_norm, crit_ids, alt_ids);

	std::vector<unsigned> user_ids(m_Users.Data.size());
	std::transform(m_Users.Data.begin(), m_Users.Data.end(), user_ids.begin(), [](const auto &pair)
	{
		return pair.second.nId;
	});

	// User ranges
	std::vector<float> user_weights(m_Users.Data.size());
	NormalizeVectorSum(m_Users.Data.begin(), m_Users.Data.end(), user_weights.begin(), [](float lhs, const auto &rhs) -> float
	{
		return lhs + rhs.second.fRange;
	},
	[](const auto &src, float sum) -> float
	{
		return src.second.fRange / sum;
	});

	// Criterion weights
	std::vector<std::vector<float>> global_crit_weights(m_Users.Data.size()); // [user][crit]
	for (size_t i = 0; i < m_Users.Data.size(); ++i)
	{
		std::vector<float> &user_crit_weights = global_crit_weights[i];
		user_crit_weights.resize(m_Criterions.Data.size());

		auto [it_in_begin, it_in_end] = std::equal_range(m_Weights.begin(), m_Weights.end(), m_Users.Order.at(i), weights_compare());
		std::transform(it_in_begin, it_in_end, user_crit_weights.begin(), [this](const WeightData &weight) -> float
		{
			return static_cast<float>(weight.nWeight);
		});

		NormalizeVectorSum(user_crit_weights.begin(), user_crit_weights.end(), user_crit_weights.begin(), std::plus<float>(), std::divides<float>());

		for (float &weight : user_crit_weights)
			weight *= user_weights.at(i);
	}

	// Alternatives
	std::vector<std::vector<float>> percents_interm(m_Users.Data.size()); // [user][alt]
	for (std::vector<float> &vec : percents_interm)
		vec.resize(m_Alternatives.Data.size());

	for (size_t user = 0; user < m_Users.Data.size(); ++user)
		CalculatePercents(marks_norm, crit_ids, alt_ids, global_crit_weights[user], percents_interm[user]);

	// Result
	std::vector<float> percents(m_Alternatives.Data.size(), 0.0f);
	for (size_t alt = 0; alt < m_Alternatives.Data.size(); ++alt)
		for (size_t user = 0; user < m_Users.Data.size(); ++user)
			percents[alt] += percents_interm[user][alt];
	NormalizeVector(percents.begin(), percents.end());

	std::vector<ResultData> result(m_Alternatives.Data.size());
	SaveToResult(result.begin(), result.end(), alt_ids.cbegin(), percents.cbegin());
	ClearResults();
	InsertResult(result.begin(), result.end(), iTreshold);
	LoadResults();

#ifdef LAB4_DEBUG
	printf("USER RANGES:\n");
	for (float weight : user_weights)
		printf("%f ", weight);
	printf("\n");
	printf("Sum: %f\n\n", std::accumulate(user_weights.begin(), user_weights.end(), 0.0f));

	printf("CRITERION WEIGHTS:\n");
	for (size_t i = 0; i < m_Users.Data.size(); ++i)
	{
		const auto &user_crit_weights = global_crit_weights.at(i);
		printf("UserId: %u Weights: ", m_Users.Order.at(i));
		for (float weight : user_crit_weights)
			printf("%f ", weight);
		printf("Sum: %f\n", std::accumulate(user_crit_weights.begin(), user_crit_weights.end(), 0.0f));
	}
	printf("\n");

	printf("RESULTS PER USERS\n");
	for (size_t user = 0; user < m_Users.Data.size(); ++user)
	{
		printf("UserId: %u Rating: ", m_Users.Order.at(user));
		for (float value : percents_interm.at(user))
			printf("%f ", value);
		printf("\n");
	}
	printf("\n");

	printf("FINAL RESULTS\n");
	for (size_t alt = 0; alt < m_Alternatives.Data.size(); ++alt)
		printf("%f ", percents[alt]);
	printf("\n\n");
#endif // LAB4_DEBUG
}

void DatabaseView::NormalizeVector(TFloatVecIt vec_begin, TFloatVecIt vec_end)
{
	const float max = *std::max_element(vec_begin, vec_end);
	std::for_each(vec_begin, vec_end, [max](float &value)
	{
		value /= max;
	});
}

template<typename TInputIt, typename TOutputIt, typename TSumPred, typename TGetPred>
void DatabaseView::NormalizeVectorSum	(TInputIt input_begin,
		TInputIt input_end,
		TOutputIt output_it,
		TSumPred sum_pred,
		TGetPred get_pred)
{
	using TSum = typename TOutputIt::value_type;
	const TSum sum = std::accumulate(input_begin, input_end, static_cast<TSum>(0), sum_pred);
	std::transform(input_begin, input_end, output_it, [sum, &get_pred](const auto &src)
	{
		return get_pred(src, sum);
	});
}
