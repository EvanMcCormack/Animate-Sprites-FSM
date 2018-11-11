#include <Input.h>

Input::Input() 
{
	m_current = 0;
}
Input::~Input() {}

void Input::setCurrent(int a) {
	m_current = a;
}

int Input:: getCurrent() {
	return m_current;
}
