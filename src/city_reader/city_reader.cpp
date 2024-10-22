#include <city_reader/city_reader.h>
#include <set>

std::vector<std::string> read(std::string path)
{
	rapidcsv::Document doc(path);

	std::vector<std::string> col = doc.GetColumn<std::string>("name");
	std::cout << "Read " << col.size() << " values." << std::endl;
	return col;
}
