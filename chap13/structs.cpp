#include <iostream>


struct Fraction
{
	int numerator {1};
	int denominator {1};
};

struct Ads
{
	int adNum {};
	int clickPer {};
	double avgEarn {};
};

void printAds(const Ads& ad)
{
	std::cout << "Number of ads watched: " << ad.adNum << "\n";
	std::cout << "Click percentage: " << ad.clickPer << "\n";
	std::cout << "Avg earning: " << ad.avgEarn << "\n";

	std::cout << "Total revenue: " << static_cast<float>(ad.adNum) * static_cast<float>(ad.clickPer) * ad.avgEarn << "\n\n";
}

Fraction getFraction()
{
	Fraction frac {};
	std::cout << "Numerator: ";
	std::cin >> frac.numerator;
	std::cout << "Denominator: ";
	std::cin >> frac.denominator;
	return frac;
}

void printFraction(const Fraction& frac)
{
	std::cout << frac.numerator << "/" << frac.denominator << "\n";
}

Fraction multiplyFractions(Fraction& frac1, Fraction& frac2)
{
	Fraction newfrac {frac1.numerator * frac2.numerator, frac1.denominator * frac2.denominator};
	printFraction(newfrac);
	return newfrac;
}

// Now we can make use of our Fraction type
int main()
{
	// printAds(Ads {10, 25, 34.2});
	
	Fraction frac1 {getFraction()};
	std::cout << "\n";
	Fraction frac2 {getFraction()};
	multiplyFractions(frac1, frac2);
	
	return 0;
}
