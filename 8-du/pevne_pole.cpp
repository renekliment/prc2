#include "pevne_pole.h"


PevnePole::PevnePole()
{
	for (unsigned int i = 0; i < velikost(); i++)
		m_data[i] = 0;
}
