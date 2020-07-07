#include "stdafx.h"
#include "funkcije.h"
/************************************************************************************************/
//NULTI NIVO
void program(std::string rep)
{
	start_boja();
	Korisnik k;
	ispisi_vrijeme(std::cout);
	std::cout << std::endl;
	print_meni("Prodavnica APP", " korisnicko ime = GOST ", " lozinka = GOST ");
	print_line();
	std::string pom = "";
	bool za_nulti_logout = true;
	do
	{
		if (pom != "")
		{
			print_pitanje("Zadrzati korisnika", "da", "ne", "kraj");
			pom = "";
			do
			{
				if (pom != "") std::cout << "GRESKA U UNOSU!!!" << std::endl;
				std::cout << ">";
				std::getline(std::cin, pom);
			} while (pom != "da" && pom != "d" && pom != "ne" && pom != "n" && pom != "kraj" && pom != "k");
		}
		else
			pom = "ne";

		if (pom == "da" || pom == "d")
		{
			glavni_meni(std::cout, k);
		}
		else if (pom == "ne" || pom == "n")
		{
			if (!za_nulti_logout)//ovo je logout za posljednji puta
				log(k, "-------------LOGOUT");
			za_nulti_logout = false;
			do
			{
				k = login(rep);
				if (k.get_sifra() == "-NEMA-")
				{
					std::cout << "Pogresna lozinka ili korisnicko ime!!!" << std::endl;
					log(k, "nelegalna_prijava");
				}
			} while (k.get_sifra() == "-NEMA-");
			log(k, "--------------LOGIN");
			glavni_meni(std::cout, k);
		}
		else if (pom == "kraj" || pom == "k")
			log(k, "-------------LOGOUT");
	} while (pom != "kraj" && pom != "k");
}
Korisnik login(std::string rep)
{
	std::ifstream in(rep, std::ifstream::in);
	std::string korisnicko_ime;
	std::string lozinka;
	std::cout << "Korisnicko ime: ";
	std::getline(std::cin, korisnicko_ime);
	std::cout << "Lozinka: ";
	std::getline(std::cin, lozinka);

	Korisnik k;
	while (in.good())
	{
		in >> k;
		if ((k.get_korisnicko_ime() == korisnicko_ime) && (k.get_lozinka() == lozinka))
		{
			in.close();
			return k;
		}
	}
	k.nema(korisnicko_ime, lozinka);
	in.close();
	return k;
}
void glavni_meni(std::ostream& out, Korisnik k)
{
	log(k, "glavni_meni");
	if (k.get_zaduzenje() == "admin")admin_meni(out, k);
	else if (k.get_zaduzenje() == "trgovac")trgovac_meni(out, k);
	else if (k.get_zaduzenje() == "kupac")kupac_meni(out, k);
	else std::cout << "GERSKA U BAZI PODATAKA!!!" << std::endl;
}
/************************************************************************************************/