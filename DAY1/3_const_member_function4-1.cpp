#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : buff(new T[sz]), size(sz) {}
	~vector() { delete[] buff; }
	
	// �����̸��� "��� ��� �Լ��� ���� ��� �Լ���" ���ÿ� �����Ҽ� �ֽ��ϴ�.
	// ���� ��ü ==> ���� ��� �Լ�
	// ��� ��ü   ==> ��� ��� �Լ��� ����ϰ� �˴ϴ�.
	T& operator[](int idx)             { return buff[idx]; }
	const T& operator[](int idx) const { return buff[idx]; }
};
int main()
{
	vector<int> v1(10);
	const vector<int> v2(10); // �б� �������� vector�� ����ϰڴٴ°�

//	v1.front() = 10; // T& front() {}
//	v2.front() = 10; // error. const T& front() const {} �� ����� �˴ϴ�.
		
	int n = 0;

	// ������ ������ ���;� �ϴ� �ڵ带 ��� ������
	v1[0] = 0;		// 1
	n     = v1[0];	// 2

//	v2[0] = 0;		// 3. error ���;� �մϴ�.
	n     = v2[0];	// 4. ok    �Ǿ�� �մϴ�.

}