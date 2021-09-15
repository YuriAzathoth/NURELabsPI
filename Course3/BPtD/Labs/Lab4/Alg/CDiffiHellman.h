#ifndef CDIFFIHELLMAN_H
#define CDIFFIHELLMAN_H

#include <cstdint>
#include <iostream>
#include <unordered_map>

class CDiffiHellman
{
public:
	using TNumber = uint64_t;

	CDiffiHellman();
	CDiffiHellman(TNumber q, TNumber a, TNumber y);

	void CreateKey(TNumber y, uint8_t id);
	void Process(std::string &data, uint8_t id) const;

	TNumber GetQ() const noexcept { return q_; }
	TNumber GetA() const noexcept { return a_; }
	TNumber GetPrivateKey() const noexcept { return x_; }
	TNumber GetPublicKey() const noexcept { return y_; }
//	TNumber GetKey() const noexcept { return k_; }

	friend std::ostream &operator<<(std::ostream &out, const CDiffiHellman &obj);

private:
	static TNumber PowMod(TNumber num, TNumber exp, TNumber mod);
	static TNumber Euler(TNumber num);
	static TNumber Generator(TNumber p);

	std::unordered_map<uint8_t, TNumber> k_;
	TNumber q_;
	TNumber a_;
	TNumber x_;
	TNumber y_;
};

#endif // CDIFFIHELLMAN_H
