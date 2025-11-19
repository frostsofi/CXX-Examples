#include <iostream>

class DataCount {
public:

    auto GetCountsCopy() {
        return (_counts);
    }

    decltype(auto) GetCountsRef() {
        return (_counts);
    }

    std::vector<int>& GetCounts() {
        return _counts;
    }

private:
    std::vector<int> _counts;
};

struct DataInfo {
    int id;
    std::string extraInfo;
    int size;
};

void AutoTest() 
{
    DataCount dc;
    dc.GetCountsCopy().push_back(2);
    std::cout << dc.GetCounts().size() << std::endl;

    dc.GetCountsRef().push_back(2);
    std::cout << dc.GetCounts().size() << std::endl;

    // std::integral auto x = 30.0;
    std::integral auto x = 30;

    DataInfo di{9, "some info", 10};
    auto [id, extraInfo, size] = di;
    std::cout << id << " " << extraInfo << " " << size << std::endl;

    int* p = new auto(10);
    delete p;
}
