#include <iostream>

class String {
private:
	char* m_buffer;
	int m_size;
public:
	String( const char* f_str) {
		m_size = strlen(f_str);
		m_buffer = new char[m_size+1];
		memcpy(m_buffer, f_str, m_size+1);

	}

	String(String& other)
		:m_size(other.m_size)
	{
		m_buffer = new char[m_size + 1];
		memcpy(m_buffer, other.m_buffer, m_size+1);
	}
	~String() {
		delete m_buffer;
	}

	friend std::ostream& operator<<(std::ostream& stream, String f_str);
};
std::ostream& operator<<( std::ostream& stream, String f_str) {
	stream << f_str.m_buffer << std::endl;
	return stream;
}
int main() {

	String l_string("The Witcher");
	String l_stringSec = l_string;
	std::cout << l_string << std::endl;
	std::cout << l_stringSec << std::endl;
	std::cin.get();
}