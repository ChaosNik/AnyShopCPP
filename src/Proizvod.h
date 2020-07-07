#pragma once
#include "stdafx.h"
#include <ctime>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#define SIRINA_LINIJE 70
/************************************************************************************************/
/**KLASA PROIZVOD**/
class Proizvod
{
	std::string sifra;
	std::string naziv;
	double cijena;
	double kolicina;
public:
	Proizvod(const std::string sifra, const std::string naziv, const double cijena, const double kolicina)
		:sifra(sifra), naziv(naziv), cijena(cijena), kolicina(kolicina) {}
	Proizvod(int i = 0) { sifra = naziv = ""; cijena = kolicina = 0; }
	Proizvod(const std::string sifra) :sifra(sifra) {}
	std::string get_sifra() { return sifra; }
	std::string get_naziv() { return naziv; }
	double get_cijena() { return cijena; }
	double get_kolicina() { return kolicina; }

	void set_sifra(std::string a) { sifra.clear(); sifra = a; }
	void set_naziv(std::string a) { naziv.clear(); naziv = a; }
	void set_cijena(double a) { cijena = a; }
	void set_kolicina(double a) { kolicina = a; }

	void out(std::ostream &out)
	{
		out << sifra << std::endl << naziv << std::endl << cijena << std::endl << kolicina << std::endl;
	}

	friend std::istream &operator>>(std::istream &in, Proizvod &k);
	friend std::ostream &operator<<(std::ostream &out, const Proizvod &k);
	friend void zaglavlje(std::ostream &out);

};
/************************************************************************************************/
/**PRIJATELJSKE FUNKCIJE**/
std::istream &operator>>(std::istream &in, Proizvod &k);
std::ostream &operator<<(std::ostream &out, const Proizvod &k);
void zaglavlje();
/************************************************************************************************/