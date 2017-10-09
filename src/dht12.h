#pragma once

#include <Wire.h>

class Dht12
{
public:
	Dht12(int sda, int scl);

	void begin();
	bool read(float& temperature, float& humidity);

private:
	int m_sda = 0;
	int m_scl = 0;
	bool m_init = false;
};
