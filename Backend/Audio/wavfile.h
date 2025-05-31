#ifndef WAVFILE_H
#define WAVFILE_H
#include <QFile>
#include <QDebug>
class WAVFile
{
public:
    WAVFile(QString path);
    ~WAVFile();
    double** data;
    int channels;
    int length;
    int cursor = 0;
    bool on = false;
    int interval;
    int count = 0;
    int sampleRate;
    void increment() {
        cursor++;
    }
    bool atEnd() {
        return (cursor == length);
    }
};

#endif // WAVFILE_H
