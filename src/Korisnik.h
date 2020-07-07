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
/**KLASA KORISNIK**/
class Korisnik
{
	std::string sifra;
	std::string ime;
	std::string prezime;
	std::string korisnicko_ime;
	std::string lozinka;
	std::string zaduzenje;
public:
	Korisnik(const std::string sifra, const std::string ime, const std::string prezime,
		const std::string korisnicko_ime, const std::string lozinka, const std::string zaduzenje)
		:sifra(sifra), ime(ime), prezime(prezime), korisnicko_ime(korisnicko_ime),
		lozinka(lozinka), zaduzenje(zaduzenje) {}
	Korisnik(int i = 0) { sifra = ime = prezime = korisnicko_ime = lozinka = zaduzenje = ""; }
	Korisnik(const std::string sifra) :sifra(sifra) {}
	std::string get_sifra() { return sifra; }
	std::string get_ime() { return ime; }
	std::string get_prezime() { return prezime; }
	std::string get_korisnicko_ime() { return korisnicko_ime; }
	std::string get_lozinka() { return lozinka; }
	std::string get_zaduzenje() { return zaduzenje; }

	void set_sifra(std::string a) { sifra.clear(); sifra = a; }
	void set_ime(std::string a) { ime.clear(); ime = a; }
	void set_prezime(std::string a) { prezime.clear(); prezime = a; }
	void set_korisnicko_ime(std::string a) { korisnicko_ime.clear(); korisnicko_ime = a; }
	void set_lozinka(std::string a) { lozinka.clear(); lozinka = a; }
	void set_zaduzenje(std::string a) { zaduzenje.clear(); zaduzenje = a; }

	void nema(std::string ki, std::string l)//kreiranje objekta greske
	{
		sifra.clear(); ime.clear(); prezime.clear(); korisnicko_ime.clear(); lozinka.clear(); zaduzenje.clear();
		sifra = "-NEMA-"; ime = korisnicko_ime = ki; prezime = lozinka = l; zaduzenje = "0";
	}
	void out(std::ostream &out)
	{out << sifra << " " << ime << " " << prezime << " " << korisnicko_ime << " " << lozinka << " " << zaduzenje << std::endl;}

	friend std::istream &operator>>(std::istream &in, Korisnik &k);
	friend std::ostream &operator<<(std::ostream &out, const Korisnik &k);
	
};
/************************************************************************************************/
/**PRIJATELJSKE FUNKCIJE**/
std::istream &operator>>(std::istream &in, Korisnik &k);
std::ostream &operator<<(std::ostream &out, const Korisnik &k);
/************************************************************************************************/