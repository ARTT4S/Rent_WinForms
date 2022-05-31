#include "Autos.h"

namespace AutosClass {
	Autos::Autos() {
		m_number = 0;
		m_brand = "";
		m_price = 0;
		m_type = "";
	};

	void Autos::setNumber(int number) {
		m_number = number;
	};

	int Autos::getNumber() {
		return m_number;
	};

	void Autos::setBrand(String^ brand) {
		m_brand = brand;
	};

	String^ Autos::getBrand() {
		return m_brand;
	};

	void Autos::setPrice(int price) {
		m_price = price;
	};

	int Autos::getPrice() {
		return m_price;
	};

	void Autos::setType(String^ type) {
		m_type = type;
	};

	String^ Autos::getType() {
		return m_type;
	};
}