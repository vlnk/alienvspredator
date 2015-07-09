#include "Conte.hpp"

Conte::Conte(std::string nom) :
	nom_(nom)
{}

Conte::~Conte() {
	for (unsigned int i = 0; i < liste_personnages_.size(); ++i)
	{
		delete liste_personnages_[i];
	}

	liste_personnages_.clear();
}

Conte::Conte(const Conte& C):
	nom_(C.nom_) 
{
	for(unsigned int i = 0; i < C.liste_personnages_.size(); ++i)
	{
		liste_personnages_.push_back(C.liste_personnages_[i]->clone());

	}
}

Conte& Conte::operator = (const Conte& C) {
	if (&C !=  this)
	{
		if (! liste_personnages_.empty())
		{
			for(std::vector<Personnage *>::iterator it = liste_personnages_.begin();
				it != liste_personnages_.end(); ++it)
			{
				delete *it;
			}
			liste_personnages_.clear();
		}

		for(unsigned int i = 0; i < C.liste_personnages_.size(); ++i)
		{
			liste_personnages_.push_back(C.liste_personnages_[i]->clone());
		}

		nom_ = C.nom_;
	}

	return * this;
}

std::ostream& operator << (std::ostream &o, const Conte& C) {

	for (int j = 0; j < (C.getNom().size() + 4); ++j)
	{
		o << "-";
	}
	o << std::endl; 

	o << "| " << C.getNom() << " |" << std::endl;

	for (int j = 0; j < (C.getNom().size() + 4); ++j)
	{
		o << "-";
	}
	o << std::endl;

	if (!C.getListePersonnages().empty()) {
		for (unsigned int i = 0; i < C.getListePersonnages().size(); ++i)
		{
			C.getListePersonnages()[i]->decrire(o);
			std::cout << std::endl;
		}
	}

	return o;
}

void Conte::add(Personnage * pers) {
	liste_personnages_.push_back(pers);
}

void Conte::setNom(std::string nom) {
	nom_ = nom;
}

void Conte::setListePersonnages(std::vector<Personnage *> liste_personnages){
	liste_personnages_ = liste_personnages;
}