#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

#include <functional>
#include <unordered_map>
#include <vector>
#include "DatabaseData.h"
namespace nanodbc
{
class connection;
class result;
}
class wxGrid;
class wxItemContainer;

class DatabaseView
{
public:
	DatabaseView();
	~DatabaseView();

	void LoadUsersList			(wxItemContainer* pItemContainer);
	void InsertUserData			(const UserData &rData);
	void EditUserData			(const UserData &rData);
	void DeleteUserData			();

	void LoadCriterionsList		(wxItemContainer* pItemContainer);
	void InsertCriterionData	(const CriterionData &rData);
	void EditCriterionData		(const CriterionData &rData);
	void DeleteCriterionData	();

	void LoadAlternativesList	(wxItemContainer* pItemContainer);
	void InsertAlternativeData	(const AlternativeData &rData);
	void EditAlternativeData	(const AlternativeData &rData);
	void DeleteAlternativeData	();

	void LoadMarksGrid			(wxGrid* pGrid, std::unordered_map<unsigned, unsigned> &rCritIdToPos) const;
	void InsertMarkData			(unsigned nIdCrit);
	void UpdateMarksData		(const AlternativeData &rData);

	void PushWeights			(wxGrid* gridWeights);
	void PullWeights			(wxGrid* gridWeights);

	void InsertResult			(unsigned nAltId);
	void LoadResultsGrid		(wxGrid* gridResult);
	void CalculateLab2			(int iTreshold);
	void CalculateLab4			(int iTreshold);

	void SetUserSelection		(int nId) noexcept { m_Users.nCurrentId			= static_cast<unsigned>(nId); }
	void SetCriterionSelection	(int nId) noexcept { m_Criterions.nCurrentId	= static_cast<unsigned>(nId); }
	void SetAlternativeSelection(int nId) noexcept { m_Alternatives.nCurrentId	= static_cast<unsigned>(nId); }

	const UserData			&GetUserData		() const { return m_Users.Data.at(m_Users.Order.at(m_Users.nCurrentId)); }
	const CriterionData		&GetCriterionData	() const { return m_Criterions.Data.at(m_Criterions.Order.at(m_Criterions.nCurrentId)); }
	const AlternativeData	&GetAlternativeData	() const { return m_Alternatives.Data.at(m_Alternatives.Order.at(m_Alternatives.nCurrentId)); }

	const DatabaseData<AlternativeData>*	GetAlternatives()	const noexcept { return &m_Alternatives; }
	const DatabaseData<CriterionData>*		GetCriterions()		const noexcept { return &m_Criterions; }

	const unsigned GetCurrentUserId() const { return m_Users.Order.at(m_Users.nCurrentId); }

private:
	using TUIntVecIt	= std::vector<unsigned>::iterator;
	using TFloatVecIt	= std::vector<float>::iterator;
	using TUIntVecCIt	= std::vector<unsigned>::const_iterator;
	using TFloatVecCIt	= std::vector<float>::const_iterator;
	using TResultVecIt	= std::vector<ResultData>::iterator;
	using TResultVecCIt	= std::vector<ResultData>::iterator;

	void LoadUsers			();
	void LoadCriterions		();
	void LoadAlternatives	();
	void LoadWeights		();
	void LoadResults		();
	void ClearResults		() const;
	void InsertResult		(const ResultData &result) const;
	void InsertResult		(TResultVecCIt result_begin, TResultVecCIt result_end, int iTreshold) const;
	void EditMarkNormData	(unsigned alt_id, unsigned crit_id, float norm_mark) const;

	void SaveToResult		(ResultData &result, unsigned alt_id, float percent) const;
	void SaveToResult		(TResultVecIt result_it_begin, TResultVecIt result_it_end, TUIntVecCIt alt_id_it, TFloatVecCIt percent_it) const;

	void CalculateMarks		(std::vector<std::vector<float>> &marks_norm,
							std::vector<unsigned> &crit_ids,
							std::vector<unsigned> &alt_ids) const;
	void CalculatePercents	(const std::vector<std::vector<float>> &marks_norm,
							const std::vector<unsigned> &crit_ids,
							const std::vector<unsigned> &alt_ids,
							const std::vector<float> &weights_norm,
							std::vector<float> &percents) const;

	DatabaseData<UserData>			m_Users;
	DatabaseData<CriterionData>		m_Criterions;
	DatabaseData<AlternativeData>	m_Alternatives;

	std::unordered_multimap<unsigned, ResultData> m_Results;
	std::vector<WeightData> m_Weights;

	mutable nanodbc::connection* m_pConnection;

	static void NormalizeVector(TFloatVecIt vec_begin, TFloatVecIt vec_end);
	template<typename TInputIt, typename TOutputIt, typename TSumPred, typename TGetPred>
	inline static void NormalizeVectorSum	(TInputIt input_begin,
											TInputIt input_end,
											TOutputIt output_it,
											TSumPred sum_pred,
											TGetPred get_pred);
};

#endif // DATABASEADAPTER_H
