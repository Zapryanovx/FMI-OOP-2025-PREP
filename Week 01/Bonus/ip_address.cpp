//��������� �� ��������:

//���� ���������� union �������� ������ ��������, 
//����� �������� ���������� �� IP ��������.#include <iostream>


#include <iostream>

//ip �������� �������� ������������� ���������� �����

//���� �������� ����������� �� ��������� �� ���� ����� � �����
//���������� ip �����

union ipAddress
{
	int number;
	uint8_t parts[4];
} ip;

int main()
{
	ip.number = 2563931973;
	std::cout << (int) ip.parts[0] << "." << (int) ip.parts[1] << "." << (int) ip.parts[2] << "." << (int) ip.parts[3];

	return 0;
}