#include "stdafx.h"
#include "funkcije.h"
/************************************************************************************************/
//PRVI NIVO
void admin_meni(std::ostream &out, Korisnik k)
{
	log(k, "admin_meni");
	print_meni("Admin meni", "statistika", "nalozi", "definisanje parametara");
    std::string pom;
    do
    {
		std::cout << ">";
		std::getline(std::cin, pom);
		if (pom == "statistika" || pom == "stat" || pom == "s")statistika_admin(out, k);
		else if (pom == "nalozi" || pom == "n")nalozi_admin(out, k);
		else if (pom == "definisanje parametara" || pom == "defparam" || pom == "dp" || pom == "d")
			definisanje_parametara_admin(out, k);
		else std::cout << "GRESKA U UNOSU!!!" << std::endl;
	} while (pom != "statistika" && pom != "stat" && pom != "s" && pom != "nalozi" && pom != "n" &&
		pom != "definisanje parametara" && pom != "defparam" && pom != "dp" && pom != "d");
}
void trgovac_meni(std::ostream &out, Korisnik k)
{
	log(k, "trgovac_meni");
	print_meni("Trgovac meni", "upravljanje proizvodima", "prodaja", "kupci", "izvjestaji");
    std::string pom;
    do
    {
		std::cout << ">";
		std::getline(std::cin, pom);
		if (pom == "upravljanje proizvodima" || pom == "uprpro" || pom == "up" || pom == "u")
			upravljanje_proizvodima_trgovac(out, k);
		else if (pom == "prodaja" || pom == "p")prodaja_trgovac(out, k);
		else if (pom == "kupci" || pom == "k")kupci_trgovac(out, k);
		else if (pom == "izvjestaji" || pom == "izvj" || pom == "i")izvjestaji_trgovac(out, k);
		else std::cout << "GRESKA U UNOSU!!!" << std::endl;
	} while (pom != "uravljanje proizvodima" && pom != "uprpro" && pom != "up" && pom != "u" && pom != "prodaja" &&
		pom != "p" && pom != "kupci" && pom != "k" && pom != "izvjestaji" && pom != "izvj" && pom != "i");
}
void kupac_meni(std::ostream &out, Korisnik k)
{
	log(k, "kupac_meni");
	print_meni("Kupac meni", "pregled svih proizvoda", "pregled jednog proizvoda");
    std::string pom;
    do
    {
		std::cout << ">";
		std::getline(std::cin, pom);
		if (pom == "pregled svih proizvoda" || pom == "svi" || pom == "s")pregled_proizvoda_kupac(out, k);
		else if (pom == "pregled jednog proizvoda" || pom == "jedan" || pom == "j")jedan_proizvod_kupac(out, k);
		else std::cout << "GRESKA U UNOSU!!!" << std::endl;
	} while (pom != "pregled svih proizvoda" && pom != "svi" && pom != "s" &&
		pom != "pregled jednog proizvoda" && pom != "jedan" && pom != "j");
}
/************************************************************************************************/