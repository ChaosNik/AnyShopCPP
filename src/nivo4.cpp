#include "stdafx.h"
#include "funkcije.h"
/***********************************************************************************************/
//CETVRTI NIVO - SAMO IZVJESTAJI
/*U SUSTINI SAMO VRACAMO TRENUTNE PREGLEDE PROIZVODA, POSTO NAM OVO NIJE U OPISU ZADATKA*/
void trenutno_svi_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "trenutno");
	print_naziv_menija("Svi proizvodi - trenutno");
	pregled_proizvoda_trgovac(out, k);
}
void sedmicno_svi_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "sedmicno");
	print_naziv_menija("Svi proizvodi - sedmicno");
	pregled_proizvoda_trgovac(out, k);
}
void mjesecno_svi_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "mjesecno");
	print_naziv_menija("Svi proizvodi - mjesecno");
	pregled_proizvoda_trgovac(out, k);
}
void godisnje_svi_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "godisnje");
	print_naziv_menija("Svi proizvodi - godisnje");
	pregled_proizvoda_trgovac(out, k);
}
void trenutno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "trenutno");
	print_naziv_menija("Jedan proizvod - trenutno");
	std::string streamstring = "proizvodi.txt";
	std::ifstream i(streamstring, std::ifstream::in);

	std::string sifra = "";

	std::cout << "Sifra: ";
	do
	{
		if (sifra != "")
			std::cout << "     >";
		std::getline(std::cin, sifra);
	} while (sifra.length() != 6 || isnotnumeric(sifra));

	Proizvod niz[1000];
	Proizvod pro;
	int n = 0;
	bool postoji = false;
	while (i.good() && !postoji)
	{
		i >> pro;
		if (pro.get_sifra() != "")
		{
			niz[n] = pro;
			if (niz[n].get_sifra() == sifra)
				postoji = true;
			++n;
		}
	}
	i.close();
	print_line();
	if (postoji)
	{
		zaglavlje(std::cout);
		print_line();
		std::cout << niz[n - 1];
		print_line();
	}
	else
		std::cout << "PROIZVOD SA ZADATOM SIFROM NE POSTOJI!!!" << std::endl;
}
void sedmicno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "sedmicno");
	print_naziv_menija("Jedan proizvod - sedmicno");
	std::string streamstring = "proizvodi.txt";
	std::ifstream i(streamstring, std::ifstream::in);

	std::string sifra = "";

	std::cout << "Sifra: ";
	do
	{
		if (sifra != "")
			std::cout << "     >";
		std::getline(std::cin, sifra);
	} while (sifra.length() != 6 || isnotnumeric(sifra));

	Proizvod niz[1000];
	Proizvod pro;
	int n = 0;
	bool postoji = false;
	while (i.good() && !postoji)
	{
		i >> pro;
		if (pro.get_sifra() != "")
		{
			niz[n] = pro;
			if (niz[n].get_sifra() == sifra)
				postoji = true;
			++n;
		}
	}
	i.close();
	print_line();
	if (postoji)
	{
		zaglavlje(std::cout);
		print_line();
		std::cout << niz[n - 1];
		print_line();
	}
	else
		std::cout << "PROIZVOD SA ZADATOM SIFROM NE POSTOJI!!!" << std::endl;
}
void mjesecno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "mjesecno");
	print_naziv_menija("Jedan proizvod - mjesecno");
	std::string streamstring = "proizvodi.txt";
	std::ifstream i(streamstring, std::ifstream::in);

	std::string sifra = "";

	std::cout << "Sifra: ";
	do
	{
		if (sifra != "")
			std::cout << "     >";
		std::getline(std::cin, sifra);
	} while (sifra.length() != 6 || isnotnumeric(sifra));

	Proizvod niz[1000];
	Proizvod pro;
	int n = 0;
	bool postoji = false;
	while (i.good() && !postoji)
	{
		i >> pro;
		if (pro.get_sifra() != "")
		{
			niz[n] = pro;
			if (niz[n].get_sifra() == sifra)
				postoji = true;
			++n;
		}
	}
	i.close();
	print_line();
	if (postoji)
	{
		zaglavlje(std::cout);
		print_line();
		std::cout << niz[n - 1];
		print_line();
	}
	else
		std::cout << "PROIZVOD SA ZADATOM SIFROM NE POSTOJI!!!" << std::endl;
}
void godisnje_jedan_proizvodi_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "godisnje");
	print_naziv_menija("Jedan proizvod - godisnje");
	std::string streamstring = "proizvodi.txt";
	std::ifstream i(streamstring, std::ifstream::in);

	std::string sifra = "";

	std::cout << "Sifra: ";
	do
	{
		if (sifra != "")
			std::cout << "     >";
		std::getline(std::cin, sifra);
	} while (sifra.length() != 6 || isnotnumeric(sifra));

	Proizvod niz[1000];
	Proizvod pro;
	int n = 0;
	bool postoji = false;
	while (i.good() && !postoji)
	{
		i >> pro;
		if (pro.get_sifra() != "")
		{
			niz[n] = pro;
			if (niz[n].get_sifra() == sifra)
				postoji = true;
			++n;
		}
	}
	i.close();
	print_line();
	if (postoji)
	{
		zaglavlje(std::cout);
		print_line();
		std::cout << niz[n - 1];
		print_line();
	}
	else
		std::cout << "PROIZVOD SA ZADATOM SIFROM NE POSTOJI!!!" << std::endl;
}
void lista_kupaca_izvjestaj_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "svi_kupci");
	pregled_kupaca_trgovac(out, k);
}
/************************************************************************************************/