#include <iostream>
#include <string>
#include <vector>
#include <ostream>
#include <fstream>
#include <exception>

class Caeser
{
public:
    Caeser() = default;
    ~Caeser() = default;
public:
    void decude(const std::string &code);
    void ecode(const std::string& code);
private:
    Caeser(const std::string&) = delete;
    Caeser(const Caeser&) = delete;
    Caeser(Caeser&&) = delete;
    Caeser &operator=(const Caeser&) = delete;
    Caeser &operator=(Caeser&&) = delete;
private:
    void is_open_file();
private:
    std::string m_file1;
};

void Caeser::is_open_file()
{
    std::ifstream fin("ecode.txt");
    std::ofstream fout("decude.txt");
    if(fin.is_open() && fout.is_open())
    {
        std::cout << "Okey Baby" << std::endl;
    }
    else
    {
        throw std::exception();
    }
}

void Caeser::ecode(const std::string& code)
{
    std::ifstream file(code);
    std::ofstream read_file("decude.txt");

    while(std::getline(file,m_file1))
    {
        for(int i = 0; i < m_file1.length(); ++i)
        {
            if (m_file1[i] >= 65 && m_file1[i] <= 67)
            {
                m_file1[i] += 26;
            }
            if(m_file1[i] == ' ')
            {
                read_file << ' ';
                continue;
            }
            read_file << (char)(m_file1[i] - 3);
        }
        read_file << ' ';
        read_file << std::endl;
    }
    file.close();
    read_file.close();
}

void Caeser::decude(const std::string& code)
{
    std::ifstream file2(code);
    std::ofstream read_file2("ecode.txt");

    while (std::getline(file2, m_file1))
    {
        for (int i = 0; i < m_file1.length(); ++i)
        {
            if (m_file1[i] >= 'X' && m_file1[i] <= 'Z')
            {
                m_file1[i] -= 23;
            }
            if (m_file1[i] == ' ')
            {
                read_file2 << ' ';
                continue;
            }
            read_file2 << (char)(m_file1[i] + 3);
        }
        read_file2 << std::endl;
    }
    file2.close();
    read_file2.close();
}

int main()
{
    std::string file1 = "ecode.txt";
    std::string file2 = "decude.txt";
    Caeser Coding;
    Coding.ecode(file1);
    

}