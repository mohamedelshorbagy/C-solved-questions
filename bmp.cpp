#include <fstream>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <iterator>
using namespace std;



unsigned char* ReadBMP(char* filename)
{
    int i;
    FILE* f = fopen(filename, "rb");

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    cout << endl;
    cout << "  Name: " << filename << endl;
    cout << " Width: " << width << endl;
    cout << "Height: " << height << endl;

    int row_padded = (width*3 + 3) & (~3);
    unsigned char* data = new unsigned char[row_padded];
    unsigned char tmp;

    for(int i = 0; i < height; i++)
    {
        fread(data, sizeof(unsigned char), row_padded, f);
        for(int j = 0; j < width*3; j += 3)
        {
            // Convert (B, G, R) to (R, G, B)
            tmp = data[j];
            data[j] = data[j+2];
            data[j+2] = tmp;

            // cout << "R: "<< (int)data[j] << " G: " << (int)data[j+1]<< " B: " << (int)data[j+2]<< endl;
        }
    }

    fclose(f);
    return data;
}


unsigned char* readBMP2(char* filename)
{
    int i;
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    cout << "Width : " << width << endl;
    cout << "Height : " << width << endl;
    int size = 3 * width * height;
    cout << "Size : " << size << endl;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
    fclose(f);

    for(i = 0; i < size; i += 3)
    {
            unsigned char tmp = data[i];
            data[i] = data[i+2];
            data[i+2] = tmp;


    }



    return data;
}
struct BmpSignature
{
    unsigned char data[2];
    BmpSignature() { data[0] = data[1] = 0; }
};

struct BmpHeader
{
    unsigned int fileSize;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned int dataOffset;
    BmpHeader() : fileSize(0),  reserved1(0), reserved2(0), dataOffset(0) { }
};

void ReadHeader(ifstream &fin, BmpSignature & sig, BmpHeader &header)
{
    if(!fin)
        return;

    fin.seekg(0, ios::beg);
    
    fin.read((char*) &sig, sizeof(sig));
    fin.read((char*) &header, sizeof(header));
}

void PrintHeader(BmpSignature sig, BmpHeader header)
{
    cout<<"==== BMP HEADER ===="<<endl;
    cout<<"+ Signature  : " << sig.data[0]<<sig.data[1]<<endl;
    cout<<"+ File Size  : " << header.fileSize<<" byte(s)"<<endl;
    cout<<"+ Reserved1  : " << header.reserved1<<endl;
    cout<<"+ Reserved2  : " << header.reserved2<<endl;
    cout<<"+ Data Offset: " << header.dataOffset<<" byte(s)"<<endl;
}




int main() {


    // char * image = readBMP2("dossier-ardoise-images-icon.png");

    ifstream fin("dossier-ardoise-images-icon.png", ios::binary);
    
    BmpSignature sig;
    BmpHeader hdr;
    PrintHeader(sig, hdr);
    ReadHeader(fin, sig, hdr);
    PrintHeader(sig, hdr);




    return 0;
}