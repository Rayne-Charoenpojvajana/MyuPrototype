#ifndef WAVFILE_H
#define WAVFILE_H
#include <QFile>
#include <QDebug>
#include <QAudioFormat>

class WAVFile
{
public:
    WAVFile(QString path);
    ~WAVFile();
    std::vector<float> data;
    QAudioFormat format;
};

#endif // WAVFILE_H
