#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class DataCarrier {
protected:
    double size;  

public:
    DataCarrier(double size = 0.0) : size(size) {}

     virtual ~DataCarrier() {}

    friend ostream& operator<<(ostream& os, const DataCarrier& dc) {
        os << "Data Carrier Size: " << dc.size << " GB";
        return os;
    }

    friend istream& operator>>(istream& is, DataCarrier& dc) {
        cout << "Enter data carrier size (GB): ";
        is >> dc.size;
        return is;
    }

    virtual void showInfo(ostream& os) const {
        os << "Size: " << size << " GB\n";
    }
};

class HardDrive : public DataCarrier {
private:
    int cylinders;  
    int tracks;    
    int sectors;    
    string brand;   

public:

    HardDrive(double size = 0.0, int cylinders = 0, int tracks = 0, int sectors = 0, string brand = "")
        : DataCarrier(size), cylinders(cylinders), tracks(tracks), sectors(sectors), brand(brand) {}

    friend ostream& operator<<(ostream& os, const HardDrive& hd) {
        os << "Hard Drive - Size: " << hd.size << " GB, Cylinders: " << hd.cylinders
            << ", Tracks: " << hd.tracks << ", Sectors: " << hd.sectors << ", Brand: " << hd.brand;
        return os;
    }

    friend istream& operator>>(istream& is, HardDrive& hd) {
        cout << "Enter hard drive size (GB): ";
        is >> hd.size;
        cout << "Enter number of cylinders: ";
        is >> hd.cylinders;
        cout << "Enter number of tracks: ";
        is >> hd.tracks;
        cout << "Enter number of sectors: ";
        is >> hd.sectors;
        cout << "Enter brand: ";
        is >> hd.brand;
        return is;
    }

    void showInfo(ostream& os) const override {
        os << "Hard Drive Info:\n";
        os << "Size: " << size << " GB\n";
        os << "Cylinders: " << cylinders << "\n";
        os << "Tracks: " << tracks << "\n";
        os << "Sectors: " << sectors << "\n";
        os << "Brand: " << brand << "\n";
    }
};

class OpticalDisk : public DataCarrier {
private:
    int cylinders;  
    int tracks;     
    int sectors;    
    string brand;   

public:

    OpticalDisk(double size = 0.0, int cylinders = 0, int tracks = 0, int sectors = 0, string brand = "")
        : DataCarrier(size), cylinders(cylinders), tracks(tracks), sectors(sectors), brand(brand) {}

    friend ostream& operator<<(ostream& os, const OpticalDisk& od) {
        os << "Optical Disk - Size: " << od.size << " GB, Cylinders: " << od.cylinders
            << ", Tracks: " << od.tracks << ", Sectors: " << od.sectors << ", Brand: " << od.brand;
        return os;
    }

    friend istream& operator>>(istream& is, OpticalDisk& od) {
        cout << "Enter optical disk size (GB): ";
        is >> od.size;
        cout << "Enter number of cylinders: ";
        is >> od.cylinders;
        cout << "Enter number of tracks: ";
        is >> od.tracks;
        cout << "Enter number of sectors: ";
        is >> od.sectors;
        cout << "Enter brand: ";
        is >> od.brand;
        return is;
    }

    void showInfo(ostream& os) const override {
        os << "Optical Disk Info:\n";
        os << "Size: " << size << " GB\n";
        os << "Cylinders: " << cylinders << "\n";
        os << "Tracks: " << tracks << "\n";
        os << "Sectors: " << sectors << "\n";
        os << "Brand: " << brand << "\n";
    }
};

void writeInfoToFile(const DataCarrier& dc, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        dc.showInfo(file);
        file.close();
        cout << "Information saved to " << filename << endl;
    }
    else {
        cerr << "Unable to open file!" << endl;
    }
}

int main() {
    HardDrive hd;
    OpticalDisk od;

    cout << "Enter hard drive information:\n";
    cin >> hd;

    cout << "\nEnter optical disk information:\n";
    cin >> od;

    cout << "\nHard Drive Information:\n" << hd << endl;
    cout << "Optical Disk Information:\n" << od << endl;

    writeInfoToFile(hd, "hard_drive_info.txt");
    writeInfoToFile(od, "optical_disk_info.txt");

    return 0;
}
