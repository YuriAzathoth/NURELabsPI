#include <random>
#include <boost/math/special_functions/prime.hpp>
#include "CDiffiHellman.h"

CDiffiHellman::CDiffiHellman() :
	x_(0),
	y_(0)
{
	std::random_device device;
	std::mt19937 generator(device());
	using random = std::uniform_int_distribution<TNumber>;

	q_ = random(boost::math::max_prime / 10, boost::math::max_prime)(generator);
	a_ = Generator(q_);
	x_ = random(100, q_ - 1)(generator);
	y_ = PowMod(a_, x_, q_);
}

CDiffiHellman::CDiffiHellman(TNumber q, TNumber a, TNumber y) :
	q_(q),
	a_(a)
{
	std::random_device device;
	std::mt19937 generator(device());
	using random = std::uniform_int_distribution<TNumber>;

	x_ = random(boost::math::max_prime / 10, q_ - 1)(generator);
	y_ = PowMod(a_, x_, q_);

	CreateKey(y, 0);
}

void CDiffiHellman::CreateKey(TNumber y, uint8_t id)
{
	k_[id] = PowMod(y, x_, q_);
}

void CDiffiHellman::Process(std::string &data, uint8_t id) const
{
	union conv_t
	{
		uint64_t flat;
		char arr[sizeof(flat)];
	}
	conv
	{
		.flat = k_.at(id)
	};

	for (size_t i = 0; i < data.size(); ++i)
	{
		data[i] ^= conv.arr[i % sizeof(k_)];
	}
}

std::ostream &operator<<(std::ostream &out, const CDiffiHellman &obj)
{
	out << "Q = " << obj.q_ << std::endl;
	out << "A = " << obj.a_ << std::endl;
	out << "X = " << obj.x_ << std::endl;
	out << "Y = " << obj.y_ << std::endl;
	out << "K = " << std::endl;
	for (const auto &pair : obj.k_)
		out << std::to_string(pair.first) << " : " << pair.second << std::endl;
	return out;
}

CDiffiHellman::TNumber CDiffiHellman::PowMod(TNumber num, TNumber exp, TNumber mod)
{
	TNumber result = 1;
	TNumber temp;

	while (exp)
	{
		temp = result * num % mod;
		if (exp & 1)
		{
			result = temp;
			--exp;
		}
		else
		{
			num = temp;
			exp >>= 1;
		}
	}
	return result;
}

CDiffiHellman::TNumber CDiffiHellman::Euler(TNumber num)
{
	TNumber result = num;
	for (TNumber i = 2; i * i < num; ++i)
		if (num % i == 0)
		{
			while (num % i == 0)
				num /= i;
			result -= result / i;
		}
	if (num > 1)
		result -= result / num;
	return result;
}

CDiffiHellman::TNumber CDiffiHellman::Generator(TNumber p)
{
	std::vector<TNumber> fact;
	fact.reserve(128);

	TNumber phi = Euler(p - 1);
	TNumber n = phi;

	for (TNumber i = 2; i * i <= n; ++i)
		if (n % i == 0)
		{
			fact.push_back(i);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		fact.push_back(n);

	for (int result = p / 4; result <= p; ++result)
	{
		bool ok = true;
		for (size_t i = 0; i < fact.size(); ++i)
			ok &= PowMod(result, phi / fact[i], p);
		if (ok)
			return result;
	}

	return -1;
}
