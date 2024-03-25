#pragma once
#include "Carriage.h"

class TicketSale : public Carriage {

	const int carriageMaxAmmount = 0;
	int carriageRealAmmount;
	int* freeSeats;
	

public:

	TicketSale() = delete;
	TicketSale(const string&, const Type&, const int&, const int&, const int&, const int*);

	~TicketSale();

	TicketSale(const TicketSale&);
	TicketSale(TicketSale&&) noexcept;

	int getCarriageMaxAmmount() const;
	int getCarriageRealAmmount() const;
	int* getFreeSeats() const;

	void setCarriageRealAmmount(const int&);
	void setFreeSeats(const int*);

	TicketSale& operator= (const TicketSale&);
	TicketSale& operator= (TicketSale&&) noexcept;

	friend ostream& operator<<(ostream&, const TicketSale&);

	virtual void print() const override;
};

