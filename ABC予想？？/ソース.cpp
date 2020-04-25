#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <numeric>

//https://ja.wikipedia.org/wiki/ABC—\‘z

typedef std::vector<std::uintmax_t> DType;

DType PrimeFacterlize(std::uintmax_t In) {
	DType R;
	for (std::uintmax_t i = 2; i <= In; i++) {
		if (In % i == 0) {
			R.push_back(i);
			In /= i;
			i--;
		}
	}

	return R;
}

std::uintmax_t Radical(std::uintmax_t In) {
	auto D = PrimeFacterlize(In);

	std::sort(D.begin(), D.end());

	D.erase(std::unique(D.begin(), D.end()), D.end());

	std::uintmax_t R = 1;

	for (auto& o : D) {
		R *= o;
	}

	return R;
}

int main() {

	//auto P = PrimeFacterlize(7875);
	//auto Rad = Radical(7875);
	std::uintmax_t L = 2;
	//std::uintmax_t L = 100;
	//std::uintmax_t A = 1;

	for (std::size_t A = 1; A <= L; A++) {
		for (std::uintmax_t N = 1; N < 10; N++) {
			//double B =  std::pow(2, 6 * N)-1;
			std::uintmax_t B = std::pow(2, 6 * N) - 1;
			if (std::gcd(A, B) == 1) {
				std::uintmax_t C = A + B;
				auto R = Radical(A * B * C);

				std::cout << "N=" << N << ',' << "A=" << A << ',' << "B=" << B << ',' << "C=" << C << ',' << "Rad=" << R << ',' << ((C > R) ? "true" : "false") << std::endl;
			}
		}

	}
	return 0;

}