#include "stdafx.h"
#include "Proizvod.h"
/************************************************************************************************/
/**PRIJATELJSKE FUNKCIJE**/
std::istream &operator>>(std::istream &in, Proizvod &k)
{
	std::string temp;
	std::getline(in, k.sifra);
	std::getline(in, k.naziv);
	in >> k.cijena >> k.kolicina;
	std::getline(in, temp);
	return in;
}
std::ostream &operator<<(std::ostream &out, const Proizvod &k)
{
	int wsifre = 7;
	int wnaziva = 29;
	int w = 15;
	out << "|" << std::setw(wsifre) << k.sifra << "|" << std::setw(wnaziva) << k.naziv << "|" <<
		std::setw(w) << std::fixed << std::setprecision(2) << k.cijena << "|" <<
		std::setw(w) << std::fixed << std::setprecision(2) << k.kolicina << "|" << std::defaultfloat << std::endl;
	return out;
}
void zaglavlje(std::ostream &out)
{
	int wsifre = 7;
	int wnaziva = 29;
	int w = 15;
	out << "|" << std::setw(wsifre) << "SIFRA" << "|" << std::setw(wnaziva) << "NAZIV" << "|" <<
		std::setw(w) << "CIJENA" << "|" << std::setw(w) << "KOLICINA" << "|" << std::endl;
}
/************************************************************************************************/