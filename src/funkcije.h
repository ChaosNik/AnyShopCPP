#include "Korisnik.h"
#include "Proizvod.h"
/************************************************************************************************/
/**OSNOVNE FUNKCIJE**/
void print_line();//ispisuje liniju na standardni izlaz
void print_line(std::ostream &out);//ispisuje liniju na bilo koji izlaz
void print_line(int sirina_linije);//ispisuje liniju neke sirine na standardni izlaz
void print_naziv_menija(std::string s);//ispisuje formatirani naziv menija
void ispisi_vrijeme(std::ostream &out); //ova funkcija je malo teza za shvatiti posto koristi time.h biblioteku
std::string datum();//vraæa nam formatiran string datuma HH:MM:SS DAN DD:MM:GG
void log(Korisnik k, std::string s);//pamti string s u log.txt fajl
bool isnotnumeric(std::string s);//provjerava da li podatak nije numericki
bool isnotdouble(std::string s);//provjerava da li podatak nije realan
void start_boja();//ucitava podatke o bojama iz boje.txt fajla
void set_boja(std::string, std::string);//podesava nove boje i upisuje podatke o njima u
										//u boje.txt fajl
/************************************************************************************************/
/**ISPISI MENI**/
//ispisuju naziv menija i moguce komande
void print_meni(std::string naziv_menija, std::string opcija1);
void print_meni(std::string naziv_menija, std::string opcija1, std::string opcija2);
void print_meni(std::string naziv_menija, std::string opcija1, std::string opcija2, std::string opcija3);
void print_meni(std::string naziv_menija, std::string opcija1, std::string opcija2, std::string opcija3, std::string opcija4);
/************************************************************************************************/
/**PITANJE**/
//ispisuju pitanje
void print_pitanje(std::string pitanje);
void print_pitanje(std::string pitanje, std::string odgovor);
void print_pitanje(std::string pitanje, std::string odgovor1, std::string odgovor2);
void print_pitanje(std::string pitanje, std::string odgovor1, std::string odgovor2, std::string odgovor3);
void print_pitanje(std::string pitanje, std::string odgovor1, std::string odgovor2, std::string odgovor3, std::string odgovor4);
void print_pitanje(std::string pitanje, std::string odgovor1, std::string odgovor2, std::string odgovor3, std::string odgovor4, std::string odgovor5);
/************************************************************************************************/
//NULTI NIVO
void program(std::string);//glavna funkcija programa
Korisnik login(std::string);//funkcija za prijavu korisnika
void glavni_meni(std::ostream &, Korisnik);//funkcija za glavni meni
/************************************************************************************************/
//PRVI NIVO
void admin_meni(std::ostream &, Korisnik);//funkcija za admin meni
void trgovac_meni(std::ostream &, Korisnik);//funkcija za trgovac meni
void kupac_meni(std::ostream &, Korisnik);//funkcija za kupac meni
/************************************************************************************************/
//DRUGI NIVO
void statistika_admin(std::ostream &, Korisnik);//funkcija za statistiku
void nalozi_admin(std::ostream &, Korisnik);//funkcija za upravljanje nalozima
void definisanje_parametara_admin(std::ostream &, Korisnik);//funkcija meni za definisanje
															//parametara
void upravljanje_proizvodima_trgovac(std::ostream &, Korisnik);//funkcija za 
																//upravljanje proizvodima
void prodaja_trgovac(std::ostream &, Korisnik);//funkcija za prodaju
void kupci_trgovac(std::ostream &, Korisnik);//funkcija za upravljanje kupcima
void izvjestaji_trgovac(std::ostream &, Korisnik);//funkcija meni za izvjestaje

void pregled_proizvoda_kupac(std::ostream &, Korisnik);//funkcija za pregled proizvoda
void jedan_proizvod_kupac(std::ostream &, Korisnik);////funkcija za pregled jednog proizv.
/************************************************************************************************/
//TRECI NIVO
void aktivnosti_statistika_admin(std::ostream &, Korisnik);//funkcija za stampanje
														//aktivnosti korisnika u izvjestaje
void pregled_naloga_admin(std::ostream &, Korisnik);//funkcija za pregled naloga
void dodavanje_naloga_admin(std::ostream &, Korisnik);//funkcija za dodavanje naloga
void brisanje_naloga_admin(std::ostream &, Korisnik);//funkcija za brisanje naloga
void izmjena_naloga_admin(std::ostream &, Korisnik);//funkcija za izmjenu naloga

void brisi_datoteku_definisanje_parametara_admin(std::ostream &, Korisnik, std::string);
											//funkcija za brisanje programskih datoteka
void promjena_boja_definisanje_parametara_admin(std::ostream&, Korisnik);
													//funkcija za promjenu boja programa
void pregled_proizvoda_trgovac(std::ostream &, Korisnik);//funkcija za pregled proizvoda
void dodavanje_proizvoda_trgovac(std::ostream &, Korisnik);//funkcija za dodavanje proizvoda
void brisanje_proizvoda_trgovac(std::ostream &, Korisnik);//funkcija za brisanje proizvoda
void izmjena_proizvoda_trgovac(std::ostream &, Korisnik);//funkcija za izmjenu proizvoda

void racun_prodaja_trgovac(std::ostream &, Korisnik);//funkcija za izdavanje racuna

void pregled_kupaca_trgovac(std::ostream &, Korisnik);//funkcija za pregled kupaca
void dodavanje_kupaca_trgovac(std::ostream &, Korisnik);//funkcija za dodavanje kupca
void brisanje_kupaca_trgovac(std::ostream &, Korisnik);//funkcija za brisanje kupca
void izmjena_kupaca_trgovac(std::ostream &, Korisnik);//funkcija za izmjenu kupca

void svi_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);//funkcija za prikaz svih
																//proizvoda
void jedan_proizvod_izvjestaj_trgovac(std::ostream &, Korisnik);//funkcija za prikaz samo
																//jednog proizvoda
void svi_kupci_izvjestaj_trgovac(std::ostream &, Korisnik);//funkcija za ispis kupaca
/************************************************************************************************/
//CETVRTI NIVO - SAMO IZVJESTAJI
//funkcije za izvjestaje
void trenutno_svi_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void sedmicno_svi_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void mjesecno_svi_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void godisnje_svi_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);

void trenutno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void sedmicno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void mjesecno_jedan_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);
void godisnje_jedan_proizvodi_izvjestaj_trgovac(std::ostream &, Korisnik);

void lista_kupaca_izvjestaj_trgovac(std::ostream &, Korisnik);
/************************************************************************************************/