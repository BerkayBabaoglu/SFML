#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class MemoryStream : public sf::InputStream
{
public:
    MemoryStream(const void* data, size_t size)
        : m_data(reinterpret_cast<const char*>(data)), m_size(size), m_offset(0) {}

    optional<size_t> read(void* data, size_t size) override
    {
        if (m_offset >= m_size)
            return -1; // okuma bitmiþse

        if (m_offset + size > static_cast<std::size_t>(m_size))
            size = m_size - m_offset;

        memcpy(data, m_data + m_offset, static_cast<size_t>(size));
        m_offset += size;
        return size;
    }

    optional<size_t> seek(size_t position) override
    {
        if (position < 0 || position > static_cast<size_t>(m_size))
            return -1;

        m_offset = position;
        return m_offset;
    }

    optional<size_t> tell() override
    {
        return m_offset;
    }

    optional<size_t> getSize() override
    {
        return m_size;
    }

private:
    const char* m_data;
    size_t m_size;
    std::int64_t m_offset;
};

int main()
{
    ifstream file("C:/Users/user/source/repos/SFML/x64/Debug/sebnemferahsigara.ogg", ios::binary);

    if (!file) {
        cout << "Not found .ogg file." << endl;
        return -1;
    }

    vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();

    MemoryStream memStream(buffer.data(), buffer.size());

    sf::Music music;
    if (!music.openFromStream(memStream)) {
        cout << "Music is not running." << endl;
        return -1;
    }

    music.play();

    while (music.getStatus() == sf::SoundSource::Status::Playing) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
            break;

        sf::sleep(sf::milliseconds(100));
    }

    return 0;
}
