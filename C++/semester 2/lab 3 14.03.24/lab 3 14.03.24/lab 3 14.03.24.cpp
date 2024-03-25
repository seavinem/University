#include "Alcohol.h"

Composite* createStand() {

	Composite* stand = new Composite;

	for (int i = 0; i < 10; ++i)
		stand->addDrink(new Vodka);
	for (int i = 0; i < 10; ++i)
		stand->addDrink(new Cognac);
	for (int i = 0; i < 10; ++i)
		stand->addDrink(new Champagne);
	for (int i = 0; i < 10; ++i)
		stand->addDrink(new Wine);
	for (int i = 0; i < 10; ++i)
		stand->addDrink(new Beer);

	return stand;
}

int main() {
	setlocale(LC_ALL, "ru");

	Composite* bar = new Composite;
	for (int i = 0; i < 5; ++i)
		bar->addDrink(createStand());

	cout << "Общая стоимость напитков бара: "
		<< bar->getPrice() << " р." << endl;

	cout << "Общий объем напитков бара: "
		<< bar->getVolume() << " л" << endl;

	delete bar;
	return 0;
}
