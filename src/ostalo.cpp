#include "stdafx.h"
#include "funkcije.h"
#pragma warning(disable : 4996)
/************************************************************************************************/
/**OSNOVNE FUNKCIJE**/
void print_line()
{
    int sirina_linije=SIRINA_LINIJE;
    for(int i=0;std::cout<<"=",i<sirina_linije;i++);
    std::cout<<std::endl;
}
void print_line(std::ostream &out)
{
	int sirina_linije = SIRINA_LINIJE;
	for (int i = 0; out << "=", i < sirina_linije; i++);
	out << std::endl;
}
void print_line(int sirina_linije)
{
    for(int i=0;std::cout<<"=",i<sirina_linije;i++);
}
void print_naziv_menija(std::string s)
{
	int sirina_linije = SIRINA_LINIJE;
	sirina_linije -= s.length();
	print_line(sirina_linije / 2);
	std::cout << s;
	print_line(sirina_linije / 2 - (sirina_linije % 2 ? 0 : 1));
	std::cout << std::endl;
}
void ispisi_vrijeme(std::ostream &out) //ova funkcija je malo teza za shvatiti posto koristi time.h biblioteku
{
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    std::string s;;
    s=asctime(timeinfo);

    out<<s[11]<<s[12]<<":"<<s[14]<<s[15]<<":"<<s[17]<<s[18]<<" ";

    if(s[0]=='M'&&s[1]=='o'&&s[2]=='n')out<<" PON ";//dan u sedmici
    else if(s[0]=='T'&&s[1]=='u'&&s[2]=='e')out<<" UTO ";
    else if(s[0]=='W'&&s[1]=='e'&&s[2]=='d')out<<" SRI ";
    else if(s[0]=='T'&&s[1]=='h'&&s[2]=='n')out<<" CET ";
    else if(s[0]=='F'&&s[1]=='r'&&s[2]=='i')out<<" PET ";
    else if(s[0]=='S'&&s[1]=='a'&&s[2]=='t')out<<" SUB ";
    else if(s[0]=='S'&&s[1]=='u'&&s[2]=='n')out<<" NED ";

    out<<s[8]<<s[9];

    if(s[4]=='J'&&s[5]=='a'&&s[6]=='n')out<<".01.";//mjesec
    else if(s[4]=='F'&&s[5]=='e'&&s[6]=='b')out<<".02.";
    else if(s[4]=='M'&&s[5]=='a'&&s[6]=='r')out<<".03.";
    else if(s[4]=='A'&&s[5]=='p'&&s[6]=='r')out<<".04.";
    else if(s[4]=='M'&&s[5]=='a'&&s[6]=='y')out<<".05.";
    else if(s[4]=='J'&&s[5]=='u'&&s[6]=='n')out<<".06.";
    else if(s[4]=='J'&&s[5]=='u'&&s[6]=='l')out<<".07.";
    else if(s[4]=='A'&&s[5]=='u'&&s[6]=='g')out<<".08.";
    else if(s[4]=='S'&&s[5]=='e'&&s[6]=='p')out<<".09.";
    else if(s[4]=='O'&&s[5]=='c'&&s[6]=='t')out<<".10.";
    else if(s[4]=='N'&&s[5]=='o'&&s[6]=='v')out<<".11.";
    else if(s[4]=='D'&&s[5]=='e'&&s[6]=='c')out<<".12.";

    out<<s[20]<<s[21]<<s[22]<<s[23]<<".g.";//godina
}
std::string datum()
{
	time_t rawtime;
	struct tm *timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	std::string s;;
	s = asctime(timeinfo);
	std::string out;

	out += s[8];
	out += s[9];

	if (s[4] == 'J'&&s[5] == 'a'&&s[6] == 'n')out += ".01.";//mjesec
	else if (s[4] == 'F'&&s[5] == 'e'&&s[6] == 'b')out += ".02.";
	else if (s[4] == 'M'&&s[5] == 'a'&&s[6] == 'r')out += ".03.";
	else if (s[4] == 'A'&&s[5] == 'p'&&s[6] == 'r')out += ".04.";
	else if (s[4] == 'M'&&s[5] == 'a'&&s[6] == 'y')out += ".05.";
	else if (s[4] == 'J'&&s[5] == 'u'&&s[6] == 'n')out += ".06.";
	else if (s[4] == 'J'&&s[5] == 'u'&&s[6] == 'l')out += ".07.";
	else if (s[4] == 'A'&&s[5] == 'u'&&s[6] == 'g')out += ".08.";
	else if (s[4] == 'S'&&s[5] == 'e'&&s[6] == 'p')out += ".09.";
	else if (s[4] == 'O'&&s[5] == 'c'&&s[6] == 't')out += ".10.";
	else if (s[4] == 'N'&&s[5] == 'o'&&s[6] == 'v')out += ".11.";
	else if (s[4] == 'D'&&s[5] == 'e'&&s[6] == 'c')out += ".12.";

	out += s[20];//godina
	out += s[21];
	out += s[22];
	out += s[23];
	out += ".g.";

	return out;
}
void log(Korisnik k, std::string s)
{
    std::ofstream out("log.txt",std::ofstream::app);
    ispisi_vrijeme(out);
    out<<" "<<std::setw(25)<<s;
    out<<std::setw(25)<<k.get_sifra()<<std::setw(25)<<k.get_ime()<<std::setw(25)<<k.get_prezime()<<std::endl;
    out.close();
}
bool isnotnumeric(std::string s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] < '0' || '9' < s[i])
			return true;
		++i;
	}
	return false;
}
bool isnotdouble(std::string s)
{
	bool dot = 0;
	int i = 0;
	while (s[i])
	{
		if (s[i] == '.')
		{
			if (dot)return true;
			dot = true;
		}
		if ((s[i] < '0' || '9' < s[i]) && (s[i] != '.'))
				return true;
		++i;
	}
	return false;
}
void start_boja()
{
	std::string str;
	std::ifstream boje("boje.txt", std::ofstream::out);
	getline(boje, str);
	char zaSystem[9];
	zaSystem[8] = 0;
	for (int i = 0; i < 8; i++)
		zaSystem[i] = str[i];
	system(zaSystem);
	boje.close();
}
void set_boja(std::string pozadina, std::string slova)
{
	std::string str = "color ";
	str += pozadina;
	str += slova;
	char zaSystem[9];
	zaSystem[8] = 0;
	for (int i = 0; i < 8; i++)
		zaSystem[i] = str[i];

	std::ofstream boje("boje.txt", std::ofstream::out);
	boje << str;
	boje.close();
}
/************************************************************************************************/
/**ISPISI MENI**/
void print_meni(std::string naziv_menija, std::string opcija1)
{
	print_naziv_menija(naziv_menija);
	print_naziv_menija("(" + opcija1 + ")");
}
void print_meni(std::string naziv_menija, std::string opcija1, std::string opcija2)
{
    print_naziv_menija(naziv_menija);
    print_naziv_menija("("+opcija1+","+opcija2+")");
}
void print_meni(std::string naziv_menija, std::string opcija1, std::string opcija2, std::string opcija3)
{
    print_naziv_menija(naziv_menija);
    print_naziv_menija("("+opcija1+","+opcija2+","+opcija3+")");
}
void print_meni(std::string naziv_menija, std::string opcija1, std::string opcija2, std::string opcija3, std::string opcija4)
{
    print_naziv_menija(naziv_menija);
    print_naziv_menija("("+opcija1+","+opcija2+","+opcija3+","+opcija4+")");
}
/************************************************************************************************/
/**PITANJE**/
void print_pitanje(std::string pitanje)
{
    std::cout<<pitanje<<"? "<<":"<<std::endl;
}
void print_pitanje(std::string pitanje, std::string odgovor)
{
    std::cout<<pitanje<<"? "<<"("<<odgovor<<")"<<":"<<std::endl;
}
void print_pitanje(std::string pitanje, std::string odgovor1, std::string odgovor2)
{
    std::cout<<pitanje<<"? "<<"("<<odgovor1<<","<<odgovor2<<")"<<":"<<std::endl;
}
void print_pitanje(std::string pitanje, std::string odgovor1, std::string odgovor2, std::string odgovor3)
{
    std::cout<<pitanje<<"? "<<"("<<odgovor1<<","<<odgovor2<<","<<odgovor3<<")"<<":"<<std::endl;
}
void print_pitanje(std::string pitanje, std::string odgovor1, std::string odgovor2, std::string odgovor3, std::string odgovor4)
{
    std::cout<<pitanje<<"? "<<"("<<odgovor1<<","<<odgovor2<<","<<odgovor3<<","<<odgovor4<<")"<<":"<<std::endl;
}
void print_pitanje(std::string pitanje, std::string odgovor1, std::string odgovor2, std::string odgovor3, std::string odgovor4, std::string odgovor5)
{
    std::cout<<pitanje<<"? "<<"("<<odgovor1<<","<<odgovor2<<","<<odgovor3<<","<<odgovor4<<","<<odgovor5<<")"<<":"<<std::endl;
}
/************************************************************************************************/