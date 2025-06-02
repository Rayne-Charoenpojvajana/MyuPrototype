#include "wavfile.h"
WAVFile::WAVFile(QString path) {
    if (!QFile::exists(path)) {
        return;
    }
    QFile file(path);
    if (!file.open(QIODeviceBase::ReadOnly)) {
        return;
    }
    QByteArray rawData = file.readAll();
    int dataIdx = 0;
    for(int k = 0; k < rawData.size() - 4; k++) {
        char curr[4];
        memcpy(curr, &rawData[k], 4);
        if (!strncmp(curr, "data", 4)) {
            dataIdx = k;
            break;
        }
    }
    if (dataIdx == 0) {
        return;
    }
    dataIdx += 4;
    uint32_t size = *(int*)&rawData[dataIdx];
    dataIdx += 4;
    for(uint32_t i = 0; i < size; i+= 4) {
        uint32_t idx = dataIdx + i;
        data.push_back(*(float*)&rawData[idx]);
    }
    format.setSampleRate(*(int*)&rawData[24]);
    format.setSampleFormat(QAudioFormat::Float);
    format.setChannelCount(1);
    format.setChannelConfig(QAudioFormat::ChannelConfigMono);
    file.close();
}

WAVFile::~WAVFile() {
    data.clear();
}

