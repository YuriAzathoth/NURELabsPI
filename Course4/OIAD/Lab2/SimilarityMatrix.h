#pragma once

#include <memory>
#include <utility>
#include <vector>

template <typename T> class SimilarityMatrix
{
  public:
	SimilarityMatrix()
	    : rowSize_(0)
	{
	}
	SimilarityMatrix(std::size_t size) { Resize(size); }

	const T& Get(unsigned x, unsigned y) const { return data_[y * rowSize_ + x]; }
	void Set(unsigned x, unsigned y, T&& v) { data_[y * rowSize_ + x] = std::forward<T>(v); }

	void Resize(std::size_t size)
	{
		rowSize_ = size;
		data_.resize(size * size);
	}

  private:
	std::vector<T> data_;
	std::size_t rowSize_;
};
