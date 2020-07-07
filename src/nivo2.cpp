#include "stdafx.h"
#include "funkcije.h"
/************************************************************************************************/
//DRUGI NIVO
void statistika_admin(std::ostream &out, Korisnik k)
{
    log(k,"statistika");


	print_meni("Statistika", "aktivnosti");
    std::string pom;
    do
    {
        std::cout<<">";
		std::getline(std::cin, pom);
		if (pom == "aktivnosti" || pom == "akt" || pom == "a")aktivnosti_statistika_admin(out, k);
	} while (pom != "aktivnosti" && pom != "akt" && pom != "a");
}
void nalozi_admin(std::ostream &out, Korisnik k)
{
    log(k,"nalozi");
    print_meni("Nalozi","pregledaj","dodaj","brisi","izmjeni");
    std::string pom;
    do
    {
        std::cout<<">";
		std::getline(std::cin, pom);
		if (pom == "pregledaj" || pom == "pregl" || pom == "p")pregled_naloga_admin(out, k);
		else if (pom == "dodaj" || pom == "dod" || pom == "d")dodavanje_naloga_admin(out, k);
		else if (pom == "brisi" || pom == "br" || pom == "b")brisanje_naloga_admin(out, k);
		else if (pom == "izmjeni" || pom == "izm" || pom == "i")izmjena_naloga_admin(out, k);
        else std::cout<<"GRESKA U UNOSU!!!"<<std::endl;
	} while (pom != "pregledaj" && pom != "pregl" && pom != "p" && pom != "dodaj" && pom != "dod" && pom != "d" &&
		pom != "brisi" && pom != "br" && pom != "b" && pom != "izmjeni" && pom != "izm" && pom != "i");
}
void definisanje_parametara_admin(std::ostream &out, Korisnik k)
{
    log(k,"def_param");
	print_meni("Definisanje parametara", "brisi log.txt", "brisi proizvodi.txt", "brisi korisnici.txt", "promjeni boje");
    std::string pom;
    do
    {
        std::cout<<">";
		std::getline(std::cin, pom);
		if (pom == "brisi log.txt" || pom == "blog" || pom == "bl" || pom == "l")
			brisi_datoteku_definisanje_parametara_admin(out, k, "log.txt");
		else if (pom == "brisi proizvodi.txt" || pom == "bpro" || pom == "bp" || pom == "p")
			brisi_datoteku_definisanje_parametara_admin(out, k, "proizvodi.txt");
		else if (pom == "brisi korisnici.txt" || pom == "bkor" || pom == "bk" || pom == "k")
			brisi_datoteku_definisanje_parametara_admin(out, k, "korisnici.txt");
		else if (pom == "promjeni boje" || pom == "pb" || pom == "b")
			promjena_boja_definisanje_parametara_admin(out, k);
		else std::cout << "GRESKA U UNOSU!!!" << std::endl;
	} while (pom != "brisi log.txt"&&pom != "blog"&&pom != "bl"&&pom != "l"&&
		pom != "brisi proizvodi.txt"&&pom != "bpro"&&pom != "bp"&&pom != "p"&&
		pom != "brisi korisnici.txt"&&pom != "bkor"&&pom != "bk"&&pom != "k"&&
		pom != "promjeni boje" && pom != "pb" && pom != "b");
}

void upravljanje_proizvodima_trgovac(std::ostream &out, Korisnik k)
{
	log(k, "upravlj_proizv");
    print_meni("Proizvodi","pregledaj","dodaj","brisi","izmjeni");
    std::string pom;
    do
    {
        std::cout<<">";
		std::getline(std::cin, pom);
        if(pom=="pregledaj"||pom=="pregl"||pom=="p")pregled_proizvoda_trgovac(out,k);
        else if(pom=="dodaj"||pom=="dod"||pom=="d")dodavanje_proizvoda_trgovac(out,k);
        else if(pom=="brisi"||pom=="br"||pom=="b")brisanje_proizvoda_trgovac(out,k);
        else if(pom=="izmjeni"||pom=="izm"||pom=="i")izmjena_proizvoda_trgovac(out,k);
        else std::cout<<"GRESKA U UNOSU!!!"<<std::endl;
	} while (pom != "pregledaj" && pom != "pregl" && pom != "p" && pom != "dodaj" && pom != "dod" && pom != "d" &&
		pom != "brisi" && pom != "br" && pom != "b" && pom != "izmjeni" && pom != "izm" && pom != "i");
}
void prodaja_trgovac(std::ostream &out, Korisnik k)
{
    log(k,"prodaja");
	print_meni("Prodaja", "racun");
    std::string pom;
    do
    {
        std::cout<<">";
		std::getline(std::cin, pom);
		if (pom == "racun" || pom == "rac" || pom == "r")racun_prodaja_trgovac(out, k);
		else std::cout << "GRESKA U UNOSU!!!" << std::endl;
	} while (pom != "racun" && pom != "rac" && pom != "r");
}
void kupci_trgovac(std::ostream &out, Korisnik k)
{
    log(k,"kupci");
    print_meni("Kupci","pregledaj","dodaj","brisi","izmjeni");
    std::string pom;
    do
    {
        std::cout<<">";
		std::getline(std::cin, pom);
		if (pom == "pregledaj" || pom == "pregl" || pom == "p")pregled_kupaca_trgovac(out, k);
		else if (pom == "dodaj" || pom == "dod" || pom == "d")dodavanje_kupaca_trgovac(out, k);
		else if (pom == "brisi" || pom == "br" || pom == "b")brisanje_kupaca_trgovac(out, k);
		else if (pom == "izmjeni" || pom == "izm" || pom == "i")izmjena_kupaca_trgovac(out, k);
        else std::cout<<"GRESKA U UNOSU!!!"<<std::endl;
	} while (pom != "pregledaj" && pom != "pregl" && pom != "p" && pom != "dodaj" && pom != "dod" && pom != "d" &&
		pom != "brisi" && pom != "br" && pom != "b" && pom != "izmjeni" && pom != "izm" && pom != "i");
}
void izvjestaji_trgovac(std::ostream &out, Korisnik k)
{
    log(k,"izvjestaji");
    print_meni("Izvjestaji","svi proizvodi","jedan proizvod","svi kupci");
    std::string pom;
    do
    {
        std::cout<<">";
		std::getline(std::cin, pom);
		if (pom == "svi proizvodi" || pom == "spro" || pom == "sp")svi_proizvodi_izvjestaj_trgovac(out, k);
		else if (pom == "jedan proizvod" || pom == "jpro" || pom == "jp")jedan_proizvod_izvjestaj_trgovac(out, k);
		else if (pom == "svi kupci" || pom == "skup" || pom == "kp" || pom == "kupci" || pom == "kup" || pom == "k")
			svi_kupci_izvjestaj_trgovac(out,k);
		else std::cout << "GRESKA U UNOSU!!!" << std::endl;
	} while (pom != "svi proizvodi" && pom != "spro" && pom != "sp" &&
		pom != "jedan proizvod" && pom != "jpro" && pom != "jp" &&
		pom != "svi kupci" && pom != "skup" && pom != "kp" &&
		pom != "kupci" && pom != "kup" && pom != "k");
}
void pregled_proizvoda_kupac(std::ostream &out, Korisnik k)
{
	log(k, "pregl_s_proizv");
	trenutno_svi_proizvodi_izvjestaj_trgovac(out, k);
}
void jedan_proizvod_kupac(std::ostream &out, Korisnik k)
{
	log(k, "pregl_j_proizv");
	trenutno_jedan_proizvodi_izvjestaj_trgovac(out, k);
}
/************************************************************************************************/