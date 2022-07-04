#ifndef SDP_PROJECT_RAWDATARECORD_H
#define SDP_PROJECT_RAWDATARECORD_H

#include <vector>
#include <string>

using namespace std;

class RawDataRecord {
private:
    vector<string> raw_data;
    vector<int> indexes;
public:
    explicit RawDataRecord(const string& line);
    bool isPrunable();
    vector<string> getRawData();
};


#endif //SDP_PROJECT_RAWDATARECORD_H
