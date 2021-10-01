#include<iostream>
#include<windows.h>
#include<direct.h>
#include<dirent.h>
#include<string>
using namespace std;

void novi_direktorij(){
	string naziv;
	cout<<"Unesite naziv direktorija: "<<endl;
	cin.ignore();
	getline(cin,naziv);
	if(mkdir(naziv.c_str())==0)cout<<"Direktorij uspjesno kreiran"<<endl;
	else cout<<"Problem kod kreiranja direktorija,provjerite postoji li vec direktorij pod tim imenom"<<endl;}
	
void ukloni_direktorij(){
	string naziv;
	cout<<"Unesite naziv direktorija: "<<endl;
	cin.ignore();
	getline(cin,naziv);
	if(rmdir(naziv.c_str())==0)cout<<"Direktorij uspjesno izbrisan"<<endl;
	else cout<<"Nije moguce obrisati direktorij ili direktorij ne postoji"<<endl;}
	
void ispisi_putanju(){
cout<<"Trenutna putanja je:"<< getcwd(NULL,0)<<endl;}

void svi_direktoriji(){
string folder;
DIR *direktorij;
struct dirent *ent;
string dire=getcwd(NULL,0);
if((direktorij=opendir(dire.c_str()))!=NULL){
	while((ent=readdir(direktorij))!=NULL){
		folder=ent->d_name;
		cout<<"		"<<telldir(direktorij)<<". "<<folder<<endl;}}
closedir(direktorij);}

void unos_putanje(){
	string put;
	cin.ignore();
	getline(cin,put);
	chdir(put.c_str());}

void promjeni_dir(){
	int odabir;
	cout<<"----------------------"<<endl;
	cout<<"Svi direktoriji na trenutnoj radnoj putanji"<<endl;
	svi_direktoriji();
	cout<<"----------------------"<<endl;
	cout<<"Unesite broj ispred zaljenog direktorija: ";cin>>odabir;
	string folder;
	DIR *direktorij;
	struct dirent *ent;
	string dire=getcwd(NULL,0);
	
	if((direktorij=opendir(dire.c_str()))!=NULL){
		seekdir(direktorij,odabir);
		if((ent=readdir(direktorij))!=NULL){
			folder=ent->d_name;
			chdir(folder.c_str());}
	else cout<<"Pogresan odabir."<<endl;}
}

void promjeni_disk(){
	string disk;
	cout<<"unesite SAMO slovo diska na koji se zelite prebaciti (npr. C)"<<endl;
	cin.ignore();
	cin>>disk;
	disk=disk+':';
	disk=disk+(char)92;
	chdir(disk.c_str());}

void browse(){
	char odabir;
	do{
		cout<<"-----------------------"<<endl;	
		cout<<"Trenutna putanja: "<<getcwd(NULL,0)<<endl;
		cout<<"a Svi direktoriji na trenutnoj radnoj lokaciji"<<endl;
		cout<<"b Promjeni direktorij"<<endl;
		cout<<"c Korak nazad"<<endl;
		cout<<"d Povratak u root direktorij"<<endl;
		cout<<"e Promjena diska"<<endl;
		cout<<"f Izlaz"<<endl;
		cin.ignore();
		cin>>odabir;
		cout<<"-----------------------"<<endl;
		switch(odabir){
				case 97: svi_direktoriji();break;
				case 98: promjeni_dir();break;
				case 99: chdir("../");break;
				case 100: chdir("/");break;
				case 101: promjeni_disk();break; 		
		
		}
		
		}while(odabir!=102);
}

void mijenjanje_radnog_direktorija(){
	int tip;
	do{cout<<"1. Rucni unos putanje\n2. Browse...\n3. Izlaz"<<endl;
		cin>>tip;
		switch(tip){
			case 1: unos_putanje();break;
			case 2: browse();break;
		}
	
	}while(tip!=3);

}


int main(){
int odabir;
do{
	cout<<"-----------------------"<<endl;
	cout<<"1. Kreiranje novog direktorija na trenutnoj radnoj lokaciji"<<endl;
	cout<<"2. Uklanjanje direktorija na trenutnoj lokaciji"<<endl;
	cout<<"3. Ispisi trenutnu putanju radnog direktorija"<<endl;
	cout<<"4. Ispisi sadrzaj trenutnog direktorija"<<endl;
	cout<<"5. Mijenjanje radnog direktorija"<<endl;  
	cin>>odabir;
	cout<<"-----------------------"<<endl;
	switch(odabir){
		case 1: novi_direktorij();break;
		case 2: ukloni_direktorij();break;
		case 3: ispisi_putanju();break;
		case 4: svi_direktoriji();break;
		case 5: mijenjanje_radnog_direktorija();break;
	}
}while(odabir!=0);

return 0;
}
