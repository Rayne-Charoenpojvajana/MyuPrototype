#include "wavfile.h"

WAVFile::WAVFile(QString path) {
    QFile file(path);
    if (!file.exists()) {
        return;
    }
    if (!file.open(QIODevice::ReadOnly)) {
        return;
    }
    QByteArray rawData = file.readAll();
    uint32_t fmt = *((ushort *) &rawData[20]);
    ushort channelCount = *((ushort *) &rawData[22]);
    channels = channelCount;
    data = new float*[channelCount];
    uint32_t sr = *((uint32_t *) &rawData[24]);
    uint32_t bufferSize = *((ushort *) &rawData[34]);
    sampleRate = sr;
    int startidx = 0;
    for(int i = 0; i < 100; i++) {
        char test[5];
        memcpy(&test, &rawData[i], 4);
        if (!strcmp(test, "data")) {
            startidx = i + 4;
            break;
        }
    }
    uint32_t size = *((uint32_t *) &rawData[startidx]);
    startidx += 4;
    length = size / (channels * (bufferSize / 8));
    for(int i = 0; i < channelCount; i++) {
        data[i] = new float[length];
    }

    if (fmt == 3 && bufferSize == 32) {
        for(int i = 0; i < length; i++) {
            for(int j = 0; j < channels; j++) {
                size_t idx = startidx + i * channels * bufferSize / 8 + j * (bufferSize / 8);
                float current = *((float *) &rawData[idx]);
                data[j][i] = current;
            }
        }
    }
}

WAVFile::~WAVFile() {
    for (int i = 0; i < channels; i++) {
        delete data[i];
    }
    delete data;
}

