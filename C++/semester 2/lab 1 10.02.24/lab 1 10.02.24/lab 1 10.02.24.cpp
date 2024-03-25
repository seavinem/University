#include "Drinks.h"
#include <vector>

int main() {
	setlocale(LC_ALL, "ru");
	
	
	vector<Alcohol*> drinks;
	
	CognacFactory* cognacFactory = new CognacFactory;
	VodkaFactory* vodkaFactory = new VodkaFactory;

	drinks.push_back(cognacFactory->createDrink());
	drinks.push_back(vodkaFactory->createDrink());
	drinks.push_back(Alcohol::createDrink(Alcohol_ID::Wine_ID));
	drinks.push_back(Alcohol::createDrink(Alcohol_ID::Beer_ID));

	for (const auto& i : drinks) {
		i->setVolume(2);
		i->setPrice(1000);
	}

	for (const auto& i : drinks) {
		cout << *i << endl;
		cout << endl;
	}






	
	/*
	try {
		cout << "ЧАСТЬ 1" << endl << endl;


		//	------- Создание алкогольных напитков (крепость установлена по умолчанию, у объекта класса Beer установлена по умолчанию выдержка) -------

		Beer beer("Средне-светлое", 0.5, 294, "Heineken", "Нидерланды");
		Cognac cognac(0.5, 3100, "Hennessy", "Франция", 6);
		Vodka vodka(0.7, 4428, "Neft", "Австрия", 5);
		Wine wine("Белое сухое", 1, 556, "Gallo", "Франция", 10);
		Champagne champagne(0.75, 14839, "Dom Perignon", "Франция", 8);
	


		cout << endl << " ----------------------------- Вывод на экран алкогольных напитков -----------------------------" << endl << endl;

		cout << beer << endl << endl
			 << cognac << endl << endl
			 << vodka << endl << endl
			 << wine << endl << endl
			 << champagne << endl << endl;



		cout << endl << "  ------------------------------------------ Копирование ------------------------------------------" << endl << endl;

		Beer beer2 = beer;
		Cognac cognac2 = cognac;
		Vodka vodka2 = vodka;
		Wine wine2 = wine;
		Champagne champagne2 = champagne;

		cout << beer2 << endl << endl
			 << cognac2 << endl << endl
			 << vodka2 << endl << endl
			 << wine2 << endl << endl
			 << champagne2 << endl << endl;



		cout << endl << "  ------------------------------------------ Присваивание ------------------------------------------" << endl << endl;

		Beer beer3("Темное", 0.5, 300, "Heineken", "Нидерланды");
		Cognac cognac3(0.5, 2500, "Hennessy", "Франция", 2);

		cout << "ДО:" << endl;
		cout << beer3 << endl << endl
			 << cognac3 << endl << endl;

		beer3 = beer;
		cognac3 = cognac;

		cout << "ПОСЛЕ:" << endl;
		cout << beer3 << endl << endl
			<< cognac3 << endl << endl;



		cout << endl << "  --------------------------------------- Set- и Get- методы ---------------------------------------" << endl << endl;

		beer.setBrand("Corona Extra");
		cognac.setCountry("Англия");
		vodka.setDegree(45);
		wine.setType("Красное");
		champagne.setPrice(14000);

		cout << "Измененние поля БРЕНД у объекта класса Beer: " << beer.getBrand() << endl
			 << "Измененние поля СТРАНА ПРОИЗВОДИТЕЛЯ у объекта класса Cognac: " << cognac.getCountry() << endl
			 << "Измененние поля КРЕПОСТЬ у объекта класса Vodka: " << vodka.getDegree() << endl
			 << "Измененние поля ТИП у объекта класса Wine: " << wine.getType() << endl
			 << "Измененние поля ЦЕНА у объекта класса Champagne: " << champagne.getPrice() << endl << endl;

	

		cout << endl << "  ------------------------------- Функции drink() и shareWithFriend() -------------------------------" << endl << endl;

		cout << "ДО:" << endl;
		cout << beer3 << endl << endl
			<< cognac3 << endl << endl;

		beer3.drink();
		cognac3.drink();

		cout << "ПОСЛЕ drink():" << endl;
		cout << beer3 << endl << endl
			<< cognac3 << endl << endl;

		beer3.shareWithFriend();
		cognac3.shareWithFriend();

		cout << "ПОСЛЕ shareWithFriend():" << endl;
		cout << beer3 << endl << endl
			<< cognac3 << endl << endl;



		cout << endl << " ------------------------------------------ Сравнение == ------------------------------------------" << endl << endl;

		cout << "У объектов класса Alcohol сравнение происходит по допустимой разнице соотношения цены к объему и разнице крепости" << endl
			<< "У объектов класса Beer сравнение происходит также по полю ТИП: beer == beer2 -> " << (beer == beer2) << endl
			<< "У объектов класса Cognac: cognac == cognac2 -> " << (cognac == cognac2) << endl
			<< "У объектов класса Vodka: vodka == vodka2 -> " << (vodka == vodka2) << endl
			<< "У объектов класса Wine сравнение происходяит также по полю ТИП: wine == wine2 -> " << (wine == wine2) << endl
			<< "У объектов класса Champagne: champagne == champagne2 -> " << (champagne == champagne2) << endl << endl
			<< "champagne == wine -> " << (champagne == wine) << endl
			<< "cognac == vodka -> " << (cognac == vodka) << endl << endl;





		cout << "ЧАСТЬ 2" << endl << endl;


		//	------------------------- Создание массива указателей на базовый класс Alcohol, его заполнение и действия над ним -------------------------

		Alcohol* drinks[10] = { 
			&beer, &beer2, 
			&cognac, &cognac2,
			&vodka, &vodka2, 
			&wine, &wine2,
			&champagne, &champagne2 };


		int countBeer = 0,
			countCognac = 0,
			countVodka = 0,
			countWine = 0,
			countChampagne = 0;

		for (int i = 0; i < 10; i++) {

			drinks[i]->setVolume(1);
			drinks[i]->setCountry("Беларусь");
			drinks[i]->shareWithFriend();

			if (dynamic_cast<Beer*>(drinks[i])) {
				countBeer++;
			}
			if (dynamic_cast<Cognac*>(drinks[i])) {
				countCognac++;
			}
			if (dynamic_cast<Vodka*>(drinks[i])) {
				countVodka++;
			}
			if (dynamic_cast<Wine*>(drinks[i])) {
				countWine++;
			}
			if (dynamic_cast<Champagne*>(drinks[i])) {
				countChampagne++;
			}
			
		}



		cout << endl << " ------------------------------- Количество объектов каждого класса -------------------------------" << endl << endl;
		
		cout << "класс Beer: " << countBeer << endl
			 << "класс Cognac: " << countCognac << endl
			 << "класс Vodka: " << countVodka << endl
			 << "класс Wine: " << countWine << endl
			 << "класс Champagne: " << countChampagne << endl << endl;



		cout << endl << " --------------------------- Элементы массива после дествий над массивом ---------------------------" << endl << endl;

		for (int i = 0; i < 10; i++) {
			cout << *drinks[i] << endl << endl;
		}

	}
	catch (...) {
		cout << "Данные введены неверно" << endl;
	}
	*/
}
