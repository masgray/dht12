#include "dht12.h"

constexpr uint8_t Dht12Address = 0x5c;

Dht12::Dht12(int sda, int scl)
	: m_sda(sda)
	, m_scl(scl)
{
}

void Dht12::begin()
{
	if (m_sda == 0 && m_scl == 0)
	{
		m_init = false;
		return;
	}
	Wire.begin(m_sda, m_scl);
	m_init = true;
}

bool readI2C(uint8_t deviceAdress, uint8_t registerAdress, uint8_t* buffer, size_t toRead)
{
	Wire.beginTransmission(deviceAdress);
	Wire.write(registerAdress);
	Wire.endTransmission();
	auto n = Wire.requestFrom(deviceAdress, static_cast<uint8_t>(toRead));
	if (n != toRead)
		return false;
	for (int i = 0; i < toRead; ++i)
		buffer[i] = Wire.read();
	return true;
}

bool Dht12::read(float& temperature, float& humidity)
{
	if (!m_init)
		return false;

	static uint8_t buf[5] = { 0 };
	if (!readI2C(Dht12Address, 0, &buf[0], 5))
	{
		return false;
	}
	static char s[32] = { 0 };
	uint8_t crc = 0;
	for (int i = 0; i < 4; ++i)
		crc += buf[i];
	if (crc != buf[4])
	{
		return false;
	}

	temperature = buf[2] + (float)buf[3] / 10;
	humidity = buf[0] + (float)buf[1] / 10;

	return true;
}
