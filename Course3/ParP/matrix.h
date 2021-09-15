#ifndef MATRIX_H
#define MATRIX_H

template<typename T>
using TMatrix = std::vector<T>;

template<size_t row_size, typename T>
struct bench_prod_seq
{
	static constexpr size_t matrix_length = row_size * row_size;
	static void generate(T &data)
	{
		data = static_cast<T>(rand() % 100 - 50) / 10.0f;
	}
	void operator()()
	{
		TMatrix<T> lhs(matrix_length);
		TMatrix<T> rhs(matrix_length);
		TMatrix<T> res(matrix_length);
		TMatrix<T> tmp(matrix_length);

		std::for_each(lhs.begin(), lhs.end(), generate);
		std::for_each(rhs.begin(), rhs.end(), generate);
		std::fill(res.begin(), res.end(), 0);

		for (size_t y = 0; y < row_size; ++y)
			for (size_t x = 0; x < row_size; ++x)
				tmp[y * row_size + x] = res[x * row_size + y];

		std::copy(tmp.begin(), tmp.end(), res.begin());

		for (size_t y = 0; y < row_size; ++y)
			for (size_t x = 0; x < row_size; ++x)
				for (size_t i = 0; i < row_size; ++i)
					res[y * row_size + x] += lhs[y * row_size + i] * rhs[x * row_size + i];
	};
};

template<size_t row_size, typename T>
struct bench_prod_par
{
	static constexpr size_t matrix_length = row_size * row_size;
	static void generate(T &data)
	{
		data = static_cast<T>(rand() % 100 - 50) / 10.0f;
	}
	void operator()()
	{
		TMatrix<T> lhs(matrix_length);
		TMatrix<T> rhs(matrix_length);
		TMatrix<T> res(matrix_length);
		TMatrix<T> tmp(matrix_length);
		size_t i, x, y;
		T temp;

		#pragma omp parallel private(i, x, y, temp) shared(lhs, rhs, res)
		{
			#pragma omp for
			for (i = 0; i < row_size; ++i)
			{
				generate(lhs[i]);
				generate(rhs[i]);
				res[i] = 0;
			}

			#pragma omp for
			for (size_t y = 0; y < row_size; ++y)
				for (size_t x = 0; x < row_size; ++x)
					tmp[y * row_size + x] = res[x * row_size + y];

			#pragma omp for
			for (size_t i = 0; i < tmp.size(); ++i)
				res[i] = tmp[i];

			#pragma omp for
			for (size_t y = 0; y < row_size; ++y)
				for (size_t x = 0; x < row_size; ++x)
				{
					temp = 0.0f;
					for (size_t i = 0; i < row_size; ++i)
						temp += lhs[y * row_size + i] * rhs[x * row_size + i];
					res[y * row_size + x] = temp;
				}
		}
	};
};

template<size_t rows_count>
struct mprod_complexity
{
	static constexpr size_t value = rows_count * rows_count * rows_count + rows_count * rows_count + rows_count;
};

#endif // MATRIX_H
